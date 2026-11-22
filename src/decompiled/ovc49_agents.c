/*
 * ovc49_agents.c - recovered from STRONG.EXE
 * memory block: OVC49_agents.c
 * range: 8699:0000 - 8699:441f
 * functions: 9
 */
#include "recovered.h"


/* 8699:0000 */

/* [R6] touches frameIndex, AgntCount */

undefined1 __cdecl16far ovc49_usesFrameIndex(agnt_t *agnt,byte *out)

{
  uint8_t uVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  agnt_t *paVar6;
  int *piVar7;
  undefined2 uVar8;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar8 = (undefined2)((ulong)agnt >> 0x10);
  paVar6 = (agnt_t *)agnt;
  if (((agntG_t *)paVar6->gdata)->extents[1][1] == 0) {
    *out = 0;
  }
  else {
    uVar1 = paVar6->faction;
    uVar2 = *(undefined2 *)((int)&paVar6->frames + 2);
    piVar7 = (int *)(*(int *)&paVar6->frames + (uint)paVar6->frameIndex * 4);
    iVar5 = piVar7[1];
    iVar3 = *piVar7;
    iStack_6 = (int)paVar6->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (paVar6->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] +
                        *(int *)(iVar3 + 0x17) + agnt->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)paVar6->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar3 + 0x17) -
                        (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0]) + agnt->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)paVar6->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    for (; iStack_a != iStack_c; iStack_a = iStack_a + cStack_d) {
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)paVar6->gdata)->extents[1][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar5 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar5) && (iVar5 < 10)) {
            if ((*(char *)(iVar5 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) !=
                  uVar1)) &&
                (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa);
              bVar4 = ovr_agnt_compute4((char *)out);
              if (bVar4) {
                return *out;
              }
            }
            if (((*(char *)(iVar5 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0);
              return *out;
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *out = 0;
  }
  return 0;
}



/* 8699:036e */

/* [R6] touches frameIndex, AgntCount */

undefined1 __cdecl16far ovc49_usesFrameIndex2(agnt_t *agnt,byte *out)

{
  uint8_t uVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  agnt_t *paVar6;
  int *piVar7;
  undefined2 uVar8;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar8 = (undefined2)((ulong)agnt >> 0x10);
  paVar6 = (agnt_t *)agnt;
  if (((agntG_t *)paVar6->gdata)->extents[0][1] == 0) {
    *out = 0;
  }
  else {
    uVar1 = paVar6->faction;
    uVar2 = *(undefined2 *)((int)&paVar6->frames + 2);
    piVar7 = (int *)(*(int *)&paVar6->frames + (uint)paVar6->frameIndex * 4);
    iVar5 = piVar7[1];
    iVar3 = *piVar7;
    iStack_6 = (int)paVar6->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (paVar6->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*((agntG_t *)paVar6->gdata)->extents)[0] + *(int *)(iVar3 + 0x17) +
                       agnt->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)paVar6->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)paVar6->gdata)->extents)[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar3 + 0x17) - (int)(*((agntG_t *)paVar6->gdata)->extents)[0]) +
                       agnt->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)paVar6->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)paVar6->gdata)->extents)[0] >> 1);
    }
    if (iStack_a < 0) {
      iStack_a = 0;
    }
    if (iStack_c < 0) {
      iStack_c = 0;
    }
    if (0x68 < iStack_a) {
      iStack_a = 0x68;
    }
    if (0x68 < iStack_c) {
      iStack_c = 0x68;
    }
    for (; iStack_a != iStack_c; iStack_a = iStack_a + cStack_d) {
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)paVar6->gdata)->extents[0][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          iVar5 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar5) && (iVar5 < 10)) {
            if ((*(char *)(iVar5 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) !=
                  uVar1)) &&
                (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa);
              bVar4 = ovr_agnt_compute4((char *)out);
              if (bVar4) {
                return *out;
              }
            }
            if (((*(char *)(iVar5 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0);
              return *out;
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *out = 0;
  }
  return 0;
}



/* 8699:06dc */

/* [R4] calls ovr_stExit */

int __cdecl16far ovc49_usesStExit(agnt_t *agnt,...)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar6;
  uint uVar5;
  int *piVar7;
  undefined2 in_stack_00000006;
  int iStack_6;
  int iStack_4;
  
  uVar1 = *(undefined2 *)((int)&agnt->frames + 2);
  piVar7 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
  iVar4 = piVar7[1];
  iVar2 = *piVar7;
  iVar3 = (int)agnt->y >> 1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (7 < iVar3) {
    iVar3 = 7;
  }
  iStack_4 = (int)(agnt->x - *(int *)(iVar2 + 0x17)) >> 1;
  iStack_6 = (int)(agnt->x + *(int *)(iVar2 + 0x17)) >> 1;
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (iStack_6 < 0) {
    iStack_6 = 0;
  }
  if (0x68 < iStack_4) {
    iStack_4 = 0x68;
  }
  if (0x68 < iStack_6) {
    iStack_6 = 0x68;
  }
  if (iStack_6 < iStack_4) {
                    /* WARNING: Subroutine does not return */
    ovr_stExit(0x1e);
  }
  uVar5 = (uint)agnt->animVariant;
  if (uVar5 == 0) {
    iVar4 = 0;
    for (; bVar6 = (byte)((uint)iVar4 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar3 * 0x69 + iStack_4 + 0x8fa) != '\0') {
        return CONCAT11((char)((uint)(iVar3 * 0x69) >> 8),1);
      }
      iVar4 = iVar3 * 0x69;
      if (*(char *)(iVar4 + iStack_4 + 0x963) != '\0') {
        return CONCAT11((char)((uint)iVar4 >> 8),1);
      }
    }
  }
  else {
    for (; bVar6 = (byte)(uVar5 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar3 * 0x69 + iStack_4 + 0x4e0) != '\0') {
        return CONCAT11((char)((uint)(iVar3 * 0x69) >> 8),1);
      }
      if (*(char *)(iVar3 * 0x69 + iStack_4 + 0x549) != '\0') {
        return CONCAT11((char)((uint)(iVar3 * 0x69) >> 8),1);
      }
      uVar5 = iVar3 * 0x69;
      if (*(char *)(uVar5 + iStack_4 + 0x5b2) != '\0') {
        return CONCAT11((char)(uVar5 >> 8),1);
      }
    }
  }
  return (uint)bVar6 << 8;
}



/* 8699:0849 */

/* [R7] body shape: compute */

uint __cdecl16far ovc49_compute1(int x,...)

{
  uint in_AX;
  uint uVar1;
  
  if ((x < 0) || (0xd2 < x)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar1 = (uint)(*(int *)(x * 2) == 0);
  }
  return uVar1;
}



/* 8699:0874 */

/* [R2] string "%s is no longer paralyzed." */

void __cdecl16far ovc49_textLongerParalyzed(agnt_t *agnt,byte param)

{
  undefined4 uVar1;
  char cVar2;
  bool bVar3;
  uint16_t uVar4;
  char *pcVar5;
  uint8_t *puVar6;
  uint uVar7;
  undefined2 uVar8;
  int iVar9;
  uint16_t uVar10;
  uint16_t in_DX;
  agnt_t *agnt_00;
  uint16_t *param_00;
  uint16_t *unaff_SS;
  byte mode;
  undefined1 uVar11;
  uint8_t uVar12;
  uint8_t text;
  uint8_t msg;
  uint8_t dirY;
  uint8_t dx;
  uint8_t agntIndex;
  uint16_t distance;
  
  param_00 = (uint16_t *)((ulong)agnt >> 0x10);
  agnt_00 = (agnt_t *)agnt;
  if ((agnt_00->combatState == 0x0) && (agnt_00->animFrame == 0xff)) {
    if (((agnt_00->flags & 0x200) != 0) && (uVar4 = ovr_randBelow(0xc), (uVar4 & 0xff) == 0)) {
      agnt_00->flags = agnt_00->flags & 0xfdff;
      uVar8 = GSavedBlitSeg;
      pcVar5 = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                            CONCAT12((char)&text,param_00)));
      puVar6 = ovr_ovc15_usesStshRealloc(pcVar5,(char)in_DX,uVar8);
      pcVar5 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x8436,unaff_SS),
                             (char *)CONCAT13((char)((uint)puVar6 >> 8),
                                              CONCAT12((char)puVar6,0x2410)),(char)puVar6,
                             (char)in_DX);
      ovr_uiNotify(pcVar5,in_DX,(char)in_DX);
      ovr_ovc41_advanceAnimFrame(agnt_00,param_00);
      ovr_attact_usesLDIV_at_2();
    }
    if (((agnt_00->flags & 0x100) != 0) &&
       ((uVar4 = ovr_randBelow(0x40), (uVar4 & 0xff) == 0 ||
        (((((agntG_t *)agnt_00->gdata)->flags3 & 0x2000) != 0 &&
         (uVar4 = ovr_randBelow(0x20), (uVar4 & 0xff) == 0)))))) {
      agnt_00->flags = agnt_00->flags & 0xfeff;
      uVar8 = GSavedBlitSeg;
      pcVar5 = ovr_agnt_statusText(agnt_00,(char *)CONCAT13((char)((uint)&text >> 8),
                                                            CONCAT12((char)&text,param_00)));
      puVar6 = ovr_ovc15_usesStshRealloc(pcVar5,(char)in_DX,uVar8);
      pcVar5 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x8451,unaff_SS),
                             (char *)CONCAT13((char)((uint)puVar6 >> 8),
                                              CONCAT12((char)puVar6,0x2410)),(char)puVar6,
                             (char)in_DX);
      ovr_uiNotify(pcVar5,in_DX,(char)in_DX);
      *(undefined1 *)&agnt_00->state = 0;
      ovr_agnt_compute13(agnt_00,param_00);
      ovr_attact_usesLDIV_at_2();
    }
    if ((agnt_00->flags & 0xbc0) == 0) {
      if (((*(char *)((int)&agnt_00->targetX + 1) < '\0') || ((int)agnt_00->y < 0x15)) ||
         (uVar7 = ovc49_agentIsActive(agnt), (uVar7 & 0xff) != 0)) {
        uVar8 = ovc49_agentIsActive(agnt);
        if ((char)uVar8 == '\0') {
          mode = (byte)((ulong)agnt >> 0x10);
          if ((agnt_00->animVariant == 0x0) ||
             (cVar2 = ovr_agnt_usesAnimFrame2(agnt_00,param_00), cVar2 == '\0')) {
            if ((((agnt_00->animVariant == 0x0) &&
                 (cVar2 = ovr_agnt_usesAnimFrame2(agnt_00,param_00), cVar2 != '\0')) &&
                (agnt_00->moveState == 0x0)) && (agnt_00->animFrame == 0xff)) {
              if ((((((agntG_t *)agnt_00->gdata)->flags & 1) == 0) ||
                  (iVar9 = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,2), (char)iVar9 == '\0')) ||
                 (uVar8 = ovr_agnt_acquireTarget
                                    (agnt_00,(char *)CONCAT13((char)((uint)&agntIndex >> 8),
                                                              CONCAT12((char)&agntIndex,param_00)),
                                     mode), (char)uVar8 == '\0')) {
                if ((((((agntG_t *)agnt_00->gdata)->flags & 1) == 0) ||
                    ((((entity_t *)agnt_00->entity)->base).level < 2)) ||
                   ((iVar9 = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,2), (char)iVar9 == '\0' ||
                    (cVar2 = ovr_agnt_usesStrengthMax
                                       (agnt_00,(byte *)CONCAT13((char)((uint)&agntIndex >> 8),
                                                                 CONCAT12((char)&agntIndex,param_00)
                                                                )), cVar2 == '\0')))) {
                  if (((((((agntG_t *)agnt_00->gdata)->flags & 0x400) == 0) ||
                       (0x14 < (int)agnt_00->y)) ||
                      (cVar2 = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                      cVar2 == '\0')) ||
                     ((0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32) ||
                      (uVar7 = ovr_ovc27_compute2(agnt_00,(int)param_00,mode,agntIndex - 1),
                      (char)uVar7 == '\0')))) {
                    if (((int)agnt_00->y < 0x15) &&
                       (iVar9 = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,3), (char)iVar9 != '\0')
                       ) {
                      cVar2 = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex));
                      if ((cVar2 == '\0') || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                        if ((((((((agntG_t *)agnt_00->gdata)->flags2 & 1) == 0) ||
                              (cVar2 = ovr_agnt_computeFrameExtents
                                                 (agnt_00,(uint8_t *)
                                                          CONCAT13((char)((uint)&agntIndex >> 8),
                                                                   CONCAT12((char)&agntIndex,
                                                                            param_00)),mode),
                              cVar2 == '\0')) || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32)))
                            || (((((agntG_t *)agnt_00->gdata)->flags3 & 0x400) != 0 &&
                                (uVar4 = ovr_randBelow(0x14), (uVar4 & 0xff) != 0)))) ||
                           (cVar2 = ovr_agnt_compute16(agnt,(agnt_t *)
                                                            CONCAT22(0x1726,(agnt_t *)
                                                                            ((uint)agntIndex * 0x34
                                                                            + -0x34))),
                           cVar2 == '\0')) {
                          if (((((((agntG_t *)agnt_00->gdata)->flags2 & 0x200) == 0) ||
                               (cVar2 = ovr_agnt_computeFrameExtents
                                                  (agnt_00,(uint8_t *)
                                                           CONCAT13((char)((uint)&agntIndex >> 8),
                                                                    CONCAT12((char)&agntIndex,
                                                                             param_00)),mode),
                               cVar2 == '\0')) ||
                              (((((agntG_t *)agnt_00->gdata)->flags3 & 0x400) != 0 &&
                               (uVar4 = ovr_randBelow(0x14), (uVar4 & 0xff) != 0)))) ||
                             (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                            if ((((((agntG_t *)agnt_00->gdata)->flags3 & 1) != 0) &&
                                (cVar2 = ovr_agnt_computeFrameExtents
                                                   (agnt_00,(uint8_t *)
                                                            CONCAT13((char)((uint)&agntIndex >> 8),
                                                                     CONCAT12((char)&agntIndex,
                                                                              param_00)),mode),
                                cVar2 != '\0')) && (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)
                               ) {
                              agnt_00->health = 0x2;
                              agnt_00->targetY = 0;
                              agnt_00->target = agntIndex + 0xff;
                              agnt_00->gindex = 0x5;
                            }
                          }
                          else {
                            agnt_00->health = 0x2;
                            agnt_00->targetY = 0;
                            agnt_00->target = agntIndex + 0xff;
                            agnt_00->gindex = 0x4;
                          }
                        }
                        else {
                          agnt_00->health = 0x2;
                          agnt_00->targetY = 0;
                          agnt_00->target = agntIndex + 0xff;
                          agnt_00->gindex = 0x2;
                        }
                      }
                      else {
                        agnt_00->health = 0x2;
                        agnt_00->targetY = 0;
                        agnt_00->target = agntIndex + 0xff;
                        agnt_00->gindex = 0x0;
                      }
                    }
                    else if ((((int)agnt_00->y < 0x15) &&
                             (uVar4 = ovr_randBelow(0x20), (uVar4 & 0xff) == 0)) &&
                            (((((agntG_t *)agnt_00->gdata)->flags & 0x4000) != 0 &&
                             ((agnt_00->health != 0x4 &&
                              (*(char *)((int)&(((entity_t *)agnt_00->entity)->base).entity + 1) !=
                               '\0')))))) {
                      agnt_00->health = 0x4;
                      agnt_00->targetY = 0;
                      uVar4 = ovr_audio_panFromX(agnt_00,param_00);
                      ovr_play_sfxU(0x32,0,uVar4,0);
                    }
                    else if (((((int)agnt_00->y < 0x15) &&
                              (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) &&
                             ((((agntG_t *)agnt_00->gdata)->flags2 & 0x40) != 0)) &&
                            (((agnt_00->health != 0x5 &&
                              (cVar2 = ovc49_usesFrameIndex
                                                 (agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                              cVar2 != '\0')) &&
                             (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                             (*(uint *)((int)uVar1 + 0x3e) & 0x80) != 0)))) {
                      uVar4 = ovr_audio_panFromX((agnt_t *)((uint)param * 0x34),0x1726);
                      ovr_play_sfxU(0x1e,0,uVar4,0);
                      agnt_00->target = agntIndex + 0xff;
                      agnt_00->health = 0x5;
                      agnt_00->targetY = 0;
                    }
                    else if ((((int)agnt_00->y < 0x15) &&
                             ((((agntG_t *)agnt_00->gdata)->flags2 & 0x100) != 0)) &&
                            ((agnt_00->health != 0x6 &&
                             ((((cVar2 = ovc49_usesFrameIndex
                                                   (agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                                cVar2 != '\0' &&
                                (iVar9 = (uint)agntIndex * 0x34 + -0x34, uVar11 = (undefined1)iVar9,
                                uVar7 = ovr_agnt_compute12(agnt_00,(agnt_t *)
                                                                   CONCAT13((char)((uint)iVar9 >> 8)
                                                                            ,CONCAT12(uVar11,
                                                  param_00)),mode,uVar11,0x1726),
                                (char)uVar7 != '\0')) &&
                               ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) &&
                              (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                              (*(uint *)((int)uVar1 + 0x3c) & 4) != 0)))))) {
                      uVar4 = ovr_audio_panFromX((agnt_t *)((uint)param * 0x34),0x1726);
                      ovr_play_sfxU(0x1f,0,uVar4,0);
                      agnt_00->target = agntIndex + 0xff;
                      agnt_00->health = 0x6;
                      agnt_00->targetY = 0;
                      agnt_00->gindex = 0x3;
                    }
                    else if ((((((agntG_t *)agnt_00->gdata)->flags3 & 0x200) == 0) ||
                             (uVar4 = (uint16_t)agnt_00->strengthMax, uVar4 < agnt_00->strength + 3)
                             ) || (uVar10 = ovr_randBelow(0x40), (uVar10 & 0xff) != 0)) {
                      if (((((char)agnt_00->targetX == '\0') &&
                           (*(char *)((int)&agnt_00->targetX + 1) == '\0')) ||
                          (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) &&
                         (agnt_00->health != 0x4)) {
                        uVar4 = ovr_randBelow(0xc);
                        if ((uVar4 & 0xff) == 0) {
                          if (((char)agnt_00->targetX == '\0') &&
                             (*(char *)((int)&agnt_00->targetX + 1) == '\0')) {
                            uVar4 = ovr_randBelow(2);
                            *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
                            uVar4 = ovr_randBelow(3);
                            *(char *)((int)&agnt_00->targetX + 1) = (char)uVar4 + -1;
                          }
                          else {
                            *(undefined1 *)&agnt_00->targetX = 0;
                            *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                          }
                        }
                        else {
                          bVar3 = ovr_agnt_usesAgntCount2
                                            (agnt_00,(uint16_t *)CONCAT22(&dx,param_00),
                                             (uint16_t *)CONCAT22(&dirY,unaff_SS));
                          if (bVar3) {
                            *(uint8_t *)((int)&agnt_00->targetX + 1) = dirY;
                            if ((distance < 0x6e) &&
                               ((((agntG_t *)agnt_00->gdata)->flags3 & 0x10) != 0)) {
                              if (distance < 0x30) {
                                if ((agnt_00->screenX < 0x14) || (0xbe < agnt_00->screenX)) {
                                  uVar4 = ovr_randBelow(2);
                                  *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
                                  uVar4 = ovr_randBelow(3);
                                  *(char *)((int)&agnt_00->targetX + 1) = (char)uVar4 + -1;
                                }
                                else if (dx == 0) {
                                  uVar4 = ovr_randBelow(2);
                                  *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
                                }
                                else {
                                  *(uint8_t *)&agnt_00->targetX = -dx;
                                }
                              }
                              else {
                                if (dx < 0) {
                                  agnt_00->level = 0x1;
                                }
                                else {
                                  agnt_00->level = 0x0;
                                }
                                *(undefined1 *)&agnt_00->targetX = 0;
                                *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                              }
                            }
                            else if (distance < 6) {
                              if (dx < 0) {
                                agnt_00->level = 0x1;
                              }
                              else {
                                agnt_00->level = 0x0;
                              }
                              *(undefined1 *)&agnt_00->targetX = 0;
                              *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                            }
                            else if (dx == 0) {
                              uVar4 = ovr_randBelow(2);
                              *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
                            }
                            else {
                              *(uint8_t *)&agnt_00->targetX = dx;
                            }
                          }
                          else {
                            uVar4 = ovr_randBelow(8);
                            if ((uVar4 & 0xff) == 0) {
                              if ((char)agnt_00->targetX == '\0') {
                                uVar4 = ovr_randBelow(2);
                                *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
                              }
                              else {
                                *(undefined1 *)&agnt_00->targetX = 0;
                              }
                            }
                            *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                          }
                        }
                        if ((((char)agnt_00->targetX < '\x01') || (agnt_00->level == 0x0)) &&
                           ((-1 < (char)agnt_00->targetX || (agnt_00->level != 0x0)))) {
                          agnt_00->health = 0x0;
                        }
                        else {
                          agnt_00->health = 0x1;
                        }
                      }
                    }
                    else {
                      agnt_00->strength = agnt_00->strength + 0x3;
                      uVar10 = ovr_audio_panFromX(agnt_00,param_00);
                      ovr_play_sfxU(0x4a,0,uVar10,0);
                      uVar12 = agnt_00->strength;
                      uVar8 = GSavedBlitSeg;
                      pcVar5 = ovr_agnt_statusText(agnt_00,(char *)CONCAT22(&text,param_00));
                      puVar6 = ovr_ovc15_usesStshRealloc(pcVar5,(char)uVar4,uVar12,uVar8);
                      pcVar5 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x846c,unaff_SS),
                                             (char *)CONCAT22(puVar6,(char *)0x26510),
                                             (char)uVar4);
                      ovr_uiNotify(pcVar5,uVar4,(char)uVar4);
                    }
                  }
                  else {
                    agnt_00->health = 0x2;
                    agnt_00->targetY = 0;
                    agnt_00->target = agntIndex + 0xff;
                    agnt_00->gindex = 0x1;
                  }
                }
                else {
                  agnt_00->health = 0x3;
                  agnt_00->targetY = 0;
                  agnt_00->target = agntIndex + 0xff;
                  agnt_00->flags = agnt_00->flags | 0x18;
                  agnt_00->gindex = 0x0;
                }
              }
              else {
                agnt_00->health = 0x3;
                agnt_00->targetY = 0;
                agnt_00->target = agntIndex + 0xff;
                agnt_00->gindex = 0x6;
              }
            }
          }
          else if (((((((agntG_t *)agnt_00->gdata)->flags & 0x400) == 0) ||
                    ((0x14 < (int)agnt_00->y ||
                     (cVar2 = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                     cVar2 == '\0')))) || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) ||
                  (uVar7 = ovr_ovc27_compute2(agnt_00,(int)param_00,mode,agntIndex - 1),
                  (char)uVar7 == '\0')) {
            if (((((int)agnt_00->y < 0x15) &&
                 (iVar9 = ovr_ovc27_rollAgainstStat(agnt_00,mode,mode,3), (char)iVar9 != '\0')) &&
                (cVar2 = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                cVar2 != '\0')) && (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)) {
              agnt_00->health = 0x2;
              agnt_00->targetY = 0;
              agnt_00->target = agntIndex + 0xff;
              agnt_00->gindex = 0x0;
            }
            else if ((((((agntG_t *)agnt_00->gdata)->flags2 & 0x200) == 0) ||
                     (0x14 < (int)agnt_00->y)) ||
                    ((cVar2 = ovr_agnt_computeFrameExtents
                                        (agnt_00,(uint8_t *)
                                                 CONCAT13((char)((uint)&agntIndex >> 8),
                                                          CONCAT12((char)&agntIndex,param_00)),mode)
                     , cVar2 == '\0' || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
              if ((((((agntG_t *)agnt_00->gdata)->flags3 & 1) == 0) || (0x14 < (int)agnt_00->y)) ||
                 ((cVar2 = ovr_agnt_computeFrameExtents
                                     (agnt_00,(uint8_t *)
                                              CONCAT13((char)((uint)&agntIndex >> 8),
                                                       CONCAT12((char)&agntIndex,param_00)),mode),
                  cVar2 == '\0' || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
                if (((('\0' < (char)agnt_00->targetX) && (0xaa < (int)agnt->x)) ||
                    (((char)agnt_00->targetX < '\0' && ((int)agnt->x < 0x34)))) &&
                   (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) {
                  bVar3 = ovr_agnt_usesAgntCount2
                                    (agnt_00,(uint16_t *)CONCAT22(&dx,param_00),
                                     (uint16_t *)CONCAT22(&dirY,unaff_SS));
                  if (bVar3) {
                    *(uint8_t *)((int)&agnt_00->targetX + 1) = dirY;
                  }
                  else {
                    *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
                  }
                  *(char *)&agnt_00->targetX = -(char)agnt_00->targetX;
                  *(undefined1 *)((uint)param * 0x34 + 0x10) = 1;
                  agnt_00->targetY = 0;
                }
              }
              else {
                agnt_00->health = 0x2;
                agnt_00->targetY = 0;
                agnt_00->target = agntIndex + 0xff;
                agnt_00->gindex = 0x5;
              }
            }
            else {
              agnt_00->health = 0x2;
              agnt_00->targetY = 0;
              agnt_00->target = agntIndex + 0xff;
              agnt_00->gindex = 0x4;
            }
          }
          else {
            agnt_00->health = 0x2;
            agnt_00->targetY = 0;
            agnt_00->target = agntIndex + 0xff;
            agnt_00->gindex = 0x1;
          }
        }
        else if ((agnt_00->moveState != 0x2) &&
                ((((*(char *)((int)&agnt_00->targetX + 1) == '\0' &&
                   ((char)agnt_00->targetX == '\0')) &&
                  (uVar4 = ovr_randBelow(4), (uVar4 & 0xff) == 0)) ||
                 (((*(char *)((int)&agnt_00->targetX + 1) < '\0' || (agnt_00->moveState != 0x1)) ||
                  (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)))))) {
          agnt_00->moveState = 0x1;
          uVar4 = ovr_randBelow(2);
          *(undefined1 *)((int)&agnt_00->targetX + 1) = (char)uVar4;
          uVar4 = ovr_randBelow(2);
          *(char *)&agnt_00->targetX = (char)uVar4 * '\x02' + -1;
          if ((int)agnt->x < 0x2a) {
            *(undefined1 *)&agnt_00->targetX = 0xff;
          }
          else if ((int)agnt->x < 0xb5) {
            *(undefined1 *)((int)&agnt_00->targetX + 1) = 1;
          }
          else {
            *(undefined1 *)&agnt_00->targetX = 1;
          }
        }
      }
      else {
        *(undefined1 *)((int)&agnt_00->targetX + 1) = 0xff;
        if ((char)agnt_00->targetX == '\0') {
          uVar4 = ovr_randBelow(3);
          *(char *)&agnt_00->targetX = (char)uVar4 + -1;
        }
      }
    }
    else {
      *(undefined1 *)&agnt_00->targetX = 0;
      *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
      agnt_00->health = 0x0;
    }
  }
  return;
}



/* 8699:1711 */

/* Returns whether an agent is active this frame: moveState below 2 and either the flags bit 2,
   moving, or field 0x2a == 2 with BothFactions. */

undefined2 __cdecl16far ovc49_agentIsActive(agnt_t *agnt)

{
  agnt_t *paVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)agnt >> 0x10);
  paVar1 = (agnt_t *)agnt;
  if ((paVar1->moveState < 2) &&
     ((((paVar1->flags & 4) != 0 || (paVar1->moveState == 0x1)) ||
      ((paVar1->teamCode == 0x2 && (BothFactions != '\0')))))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 8699:1753 */

/* Clears a span of `count` cells at the agent's grid position in the agent-index grids (two layers
   normally, three when animVariant is set). */

void * __cdecl16far ovc49_fillGridCells(byte count,agnt_t *agnt,...)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  uint16_t unaff_DI;
  undefined2 in_stack_00000008;
  int iStack_4;
  
  uVar1 = *(undefined2 *)((int)&agnt->frames + 2);
  piVar6 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
  iVar2 = piVar6[1];
  iVar3 = *piVar6;
  iVar4 = (int)(agnt->x - *(int *)(iVar3 + 0x17)) >> 1;
  iStack_4 = (int)(agnt->x + *(int *)(iVar3 + 0x17)) >> 1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (0x68 < iVar4) {
    iVar4 = 0x68;
  }
  if (0x68 < iStack_4) {
    iStack_4 = 0x68;
  }
  if (agnt->animVariant == 0x0) {
    _fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar4) + 1,unaff_DI);
    pvVar5 = _fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
                      (iStack_4 - iVar4) + 1,unaff_DI);
  }
  else {
    _fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar4) + 1,unaff_DI);
    _fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar4) + 1,unaff_DI);
    pvVar5 = _fmemset((void *)(ulong)CONCAT12(count,(int)&AgntAnms[0x75].halfWidth + 1),
                      (iStack_4 - iVar4) + 1,unaff_DI);
  }
  return pvVar5;
}



/* 8699:18c4 */
uint __cdecl16far ovc49_body1(agnt_t *agnt,...)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  far_t gfx;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t pixels;
  far_t pixels_00;
  far_t pixels_01;
  far_t pixels_02;
  far_t pixels_03;
  far_t pixels_04;
  far_t pixels_05;
  far_t pixels_06;
  far_t pixels_07;
  far_t pixels_08;
  far_t pixels_09;
  far_t pixels_10;
  far_t pixels_11;
  far_t pixels_12;
  far_t pixels_13;
  far_t pixels_14;
  far_t pixels_15;
  far_t pixels_16;
  far_t pixels_17;
  far_t pixels_18;
  far_t pixels_19;
  far_t pixels_20;
  far_t pixels_21;
  far_t pixels_22;
  far_t pixels_23;
  far_t pixels_24;
  far_t pixels_25;
  far_t pixels_26;
  far_t pixels_27;
  far_t pixels_28;
  far_t pixels_29;
  far_t pixels_30;
  far_t pixels_31;
  far_t pixels_32;
  far_t pixels_33;
  far_t pixels_34;
  far_t pixels_35;
  far_t pixels_36;
  far_t pixels_37;
  far_t entries;
  far_t gfx_06;
  far_t gfx_07;
  far_t dst;
  agnt_t *paVar4;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  char cVar8;
  byte bVar9;
  char *pcVar10;
  undefined2 *puVar11;
  cte_t *pcVar12;
  far_t far *pfVar13;
  undefined1 extraout_AH;
  int iVar14;
  uint uVar15;
  uint16_t uVar16;
  stg_tmp_t *psVar17;
  int iVar18;
  brect_t *pbVar19;
  agnt_t *agnt_00;
  uint uVar20;
  char *pcVar21;
  undefined2 uVar22;
  unit_t *puVar23;
  int *piVar24;
  uint *puVar25;
  char *pcVar26;
  int unaff_SI;
  undefined2 uVar27;
  brect_t *pbVar28;
  brect_t *pbVar29;
  brect_t *unaff_SS;
  byte in_AF;
  long lVar30;
  undefined2 in_stack_00000006;
  char *in_stack_00000008;
  char in_stack_00000010;
  undefined2 auStackY_2f2 [20];
  undefined1 auStackY_2ca [664];
  brect_t bStackY_32;
  int iStackY_28;
  uint uStackY_26;
  undefined2 uStackY_24;
  cte_t *uStackY_22;   /* hand fix: indexed and ->ofs/-info deref */
  char *in_stack_0000ffe0;
  undefined4 uVar31;
  far_t gfx_08;
  far_t gfx_09;
  uint16_t in_stack_0000ffe4;
  uint8_t *puVar32;
  stg_tmp_t *in_stack_0000ffe8;
  undefined1 uVar33;
  undefined1 uVar34;
  int iVar35;
  byte bVar36;
  uint uVar37;
  undefined1 uVar38;
  undefined1 uVar39;
  stg_tmp_t *in_stack_0000fff6;
  char *pcStack_8;
  char cVar40;
  undefined1 uVar41;
  char cVar42;
  uint8_t in_stack_0000fffc;
  byte in_stack_0000fffd;
  
  paVar4 = agnt;
  uVar27 = *(undefined2 *)((int)&agnt->frames + 2);
  pcStack_8 = *(char **)&agnt->frames;
  uVar39 = (undefined1)uVar27;
  uVar41 = (undefined1)((uint)uVar27 >> 8);
  uVar7 = 0x99;
  uVar34 = 0x86;
  uVar33 = 0x78;
  cVar6 = -0x7e;
  iVar14 = ovr_agnt_clampX(agnt->x);
  uVar27 = (undefined2)((ulong)in_stack_0000ffe0 >> 0x10);
  iVar14 = *(int *)(iVar14 * 2 + 0x1a6);
  if (agnt->combatState != 0x1) {
    if (agnt->combatState == 0x2) {
      uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
      if (*(int *)(pcStack_8 + 0xa0) == 0 && *(int *)(pcStack_8 + 0xa2) == 0) {
        if (agnt->animVariant == 0x0) {
          in_stack_0000fffd = 0;
        }
        else {
          in_stack_0000fffd = 4;
        }
      }
      else {
        in_stack_0000fffd = 0x12;
      }
    }
    else {
      if ((char)agnt->targetX < '\x01') {
        if ((char)agnt->targetX < '\0') {
          in_stack_0000fffc = 0x1;
          if (*(char *)((int)&agnt->targetX + 1) < '\x01') {
            if (*(char *)((int)&agnt->targetX + 1) < '\0') {
              in_stack_0000fffd = 2;
            }
            else if (iVar14 < 8) {
              if (iVar14 < -7) {
                in_stack_0000fffd = 2;
              }
              else {
                in_stack_0000fffd = 0;
              }
            }
            else {
              in_stack_0000fffd = 1;
            }
          }
          else {
            in_stack_0000fffd = 1;
          }
        }
        else {
          in_stack_0000fffc = agnt->level;
          if (*(char *)((int)&agnt->targetX + 1) < '\x01') {
            if (*(char *)((int)&agnt->targetX + 1) < '\0') {
              in_stack_0000fffd = 2;
            }
            else if ((agnt->flags & 0x100) == 0) {
              in_stack_0000fffd = 1;
            }
            else {
              uVar16 = ovr_randBelow(3);
              uVar15 = uVar16 & 0xff;
              if (uVar15 == 0) {
                in_stack_0000fffd = 0;
              }
              else if (uVar15 == 1) {
                in_stack_0000fffd = 2;
              }
              else if (uVar15 == 2) {
                in_stack_0000fffd = 1;
              }
            }
          }
          else {
            in_stack_0000fffd = 1;
          }
        }
      }
      else {
        in_stack_0000fffc = 0x0;
        if (*(char *)((int)&agnt->targetX + 1) < '\x01') {
          if (*(char *)((int)&agnt->targetX + 1) < '\0') {
            in_stack_0000fffd = 2;
          }
          else if (iVar14 < 8) {
            if (iVar14 < -7) {
              in_stack_0000fffd = 1;
            }
            else {
              in_stack_0000fffd = 0;
            }
          }
          else {
            in_stack_0000fffd = 2;
          }
        }
        else {
          in_stack_0000fffd = 1;
        }
      }
      if (agnt->animVariant == 0x0) {
        if (agnt->health == 0x2) {
          if ((agnt->gindex == 0x1) &&
             (uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10),
             *(int *)(pcStack_8 + 0x74) != 0 || *(int *)(pcStack_8 + 0x76) != 0)) {
            in_stack_0000fffd = 7;
          }
          else if ((agnt->gindex == 0x2) &&
                  (uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10),
                  *(int *)(pcStack_8 + 0xa8) != 0 || *(int *)(pcStack_8 + 0xaa) != 0)) {
            in_stack_0000fffd = 0x14;
          }
          else {
            in_stack_0000fffd = 3;
          }
        }
        else if (agnt->health == 0x3) {
          uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0x74) == 0 && *(int *)(pcStack_8 + 0x76) == 0) {
            in_stack_0000fffd = 3;
          }
          else {
            in_stack_0000fffd = 7;
          }
        }
        else if (agnt->health == 0x1) {
          uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0x9c) != 0 || *(int *)(pcStack_8 + 0x9e) != 0) {
            in_stack_0000fffd = 0x11;
          }
        }
        else if (agnt->health == 0x4) {
          uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
          if (*(int *)(pcStack_8 + 0xa4) != 0 || *(int *)(pcStack_8 + 0xa6) != 0) {
            in_stack_0000fffd = 0x13;
          }
        }
        else if (((agnt->health == 0x5) || (agnt->health == 0x6)) &&
                (uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10),
                *(int *)(pcStack_8 + 0xac) != 0 || *(int *)(pcStack_8 + 0xae) != 0)) {
          in_stack_0000fffd = 0x15;
        }
      }
      else {
        in_stack_0000fffd = 4;
        if (agnt->health == 0x2) {
          in_stack_0000fffd = 0xf;
        }
        else if (agnt->health == 0x1) {
          in_stack_0000fffd = 5;
        }
        uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
        if (*(int *)(pcStack_8 + (uint)in_stack_0000fffd * 4 + 0x58) == 0 &&
            *(int *)(pcStack_8 + (uint)in_stack_0000fffd * 4 + 0x5a) == 0) {
          in_stack_0000fffd = 4;
        }
      }
    }
L_OVC49_8699_18c4_1CA7:
    uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
    if (*(int *)(pcStack_8 + (uint)in_stack_0000fffd * 4 + 0x58) == 0 &&
        *(int *)(pcStack_8 + (uint)in_stack_0000fffd * 4 + 0x5a) == 0) {
      if (agnt->animVariant == 0x0) {
        in_stack_0000fffd = 0;
      }
      else {
        in_stack_0000fffd = 4;
      }
    }
    if ((((agnt->animVariant == 0x0) && (in_stack_0000fffd != 0x12)) && (agnt->health == 0x0)) &&
       ((*(char *)((int)&agnt->targetX + 1) == '\0' && ((char)agnt->targetX == '\0')))) {
      agnt->targetY = 0;
    }
    agnt->level = in_stack_0000fffc;
    agnt->frameIndex = in_stack_0000fffd;
    uVar27 = (undefined2)(CONCAT13(uVar41,CONCAT12(uVar39,pcStack_8)) >> 0x10);
    iVar14 = *(int *)((int)(pcStack_8 + (uint)in_stack_0000fffd * 4) + 2);
    iVar18 = *(int *)(pcStack_8 + (uint)in_stack_0000fffd * 4);
    uVar33 = (undefined1)iVar18;
    uVar7 = (undefined1)((uint)iVar18 >> 8);
    if (*(char *)(iVar18 + 0x1a) == -1) {
      if ((int)(uint)*(byte *)(iVar18 + 0x1b) <= (int)(agnt->targetY + 1)) {
        if ((((agntG_t *)agnt->gdata)->flags3 & 4) == 0) {
          agnt->health = 0x0;
        }
        else if (agnt->animFrame == 0xff) {
          animBranchCode = 1;
          ovr_agnt_usesAnimFrame(agnt);
        }
        else {
          agnt->health = 0x0;
        }
        if ((int)(uint)*(byte *)(CONCAT11(uVar7,uVar33) + 0x1b) <= (int)agnt->targetY) {
          agnt->targetY = 0;
        }
      }
    }
    else if ((int)(uint)*(byte *)(iVar18 + 0x1b) <= (int)agnt->targetY) {
      agnt->targetY = (uint)*(byte *)(iVar18 + 0x1a);
    }
    return (uint)in_stack_0000fffd;
  }
  if ((((agntG_t *)agnt->gdata)->flags3 & 2) != 0) {
    in_stack_0000fffd = 0x12;
    goto L_OVC49_8699_18c4_1CA7;
  }
  bVar36 = (byte)unaff_SS;
  uVar38 = (undefined1)((uint)unaff_SS >> 8);
  if (agnt->animVariant != 0x0) {
    uVar15 = agnt->timer & 3;
    if (uVar15 < 4) {
      switch(uVar15) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 2:
                    /* WARNING (jumptable): Read-only address (ram,0x0002db84) is written */
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
        pcVar1 = (uint16_t)((char *)(uVar15 * 2 + unaff_SI));
        uRam0002db84 = uVar15;
        *pcVar1 = *pcVar1 + -0x4d;
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)audioSaveCut1Seg;
        gfx_06.ofs = audioSaveCut1Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) = (char)((uint)audioSaveCut1Seg >> 8);
        ovr_blitLoadRleGfx(gfx_06);
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) = (char)audioSaveCut2Seg;
        gfx_07.ofs = audioSaveCut2Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) = (char)((uint)audioSaveCut2Seg >> 8);
        ovr_blitLoadRleGfx(gfx_07);
        GGameState = 0x2c;
        (*(uint8_t *)((uint8_t *)&(dst.seg))) = bVar36;
        dst.ofs = (uint16_t)&bStackY_32;
        (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar38;
        ovr_ovc23_textBuildThfres01Lbm(dst);
        cVar6 = 'o';
        cVar8 = '#';
        _fmemset((void *)ZEXT24(unaff_SS),2,(uint16_t)in_stack_0000fff6);
        for (uStackY_22 = (cte_t *)0x0; (int)uStackY_22 < (int)(uint)AgntCount;
            uStackY_22 = (cte_t *)((int)uStackY_22 + 1)) {
          (&stack0xffec)[*(byte *)((int)uStackY_22 * 0x34 + 0x2f)] = 1;
        }
        if ((cVar6 == '\0') || (cVar8 == '\0')) {
          BothFactions = 0;
        }
        else {
          BothFactions = 1;
        }
        GGameState = 0x2d;
        if (DebugVerbose != false) {
          printf("%d \r");
        }
        pbVar29 = (brect_t *)((int)&AgntAnms[0x38].halfWidth + 1);
        uStackY_22 =(uint16_t)(unsigned long)(unsigned long)( (cte_t *)0x0);
        goto L_OVC49_8699_1e09_29B9;
      case 3:
        in_AF = 9 < (byte)uVar15 | in_AF;
        uVar15 = CONCAT11(in_AF,(byte)uVar15 + in_AF * '\x06') & 0xff0f &
                 *(uint *)(&stack0x02c2 + iVar14);
        cVar6 = (char)uVar15 * '\x02' + -1;
        uVar15 = CONCAT11((char)(uVar15 >> 8),cVar6);
        *(char *)&agnt->targetX = cVar6;
        if ((((char)agnt->targetX < '\x01') || (agnt->level == 0x0)) &&
           ((-1 < (char)agnt->targetX || (uVar15 = (uint)(char)agnt->level, uVar15 != 0)))) {
          agnt->health = 0x0;
        }
        else {
          agnt->health = 0x1;
        }
      }
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
      return uVar15;
    }
    goto L_OVC49_8699_18c4_1CA7;
  }
  if ((char)agnt->targetX < '\x01') {
    if (*(char *)((int)&agnt->targetX + 1) < '\0') {
      iVar14 = 5;
    }
    else if (*(char *)((int)&agnt->targetX + 1) == '\0') {
      iVar14 = 4;
    }
    else {
      iVar14 = 3;
    }
  }
  else if (*(char *)((int)&agnt->targetX + 1) < '\0') {
    iVar14 = 0;
  }
  else if (*(char *)((int)&agnt->targetX + 1) == '\0') {
    iVar14 = 1;
  }
  else {
    iVar14 = 2;
  }
  uVar15 = ((uint)agnt->timer + iVar14) % 6;
  if (5 < uVar15) goto L_OVC49_8699_18c4_1CA7;
  switch(uVar15) {
  case 0:
    do {
      uVar7 = (undefined1)in_stack_0000ffe4;
      iVar14 = 0;
      uVar27 = (undefined2)((ulong)GUnits >> 0x10);
      puVar23 = (unit_t *)GUnits;
      pcVar10 = (char *)((int)(((long)*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x125) *
                                (long)(int)(uint)puVar23[uStackY_26].level & 0xffffU) / 0x18) + 1);
      uVar15 = (uint)((ulong)in_stack_0000ffe0 >> 0x10);
      in_stack_0000ffe0 = (uint16_t)((char *)CONCAT22(uVar15,pcVar10));
      if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116) == 0 &&
          *(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118) == 0) {
        if (((uStackY_26 < 0xf8) || (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x125) == 0)) ||
           (uVar22 = 0x195d, (*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) != 0)) {
          if ((((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) == 0) ||
              (puVar23[uStackY_26].unitType == 0xff)) ||
             (uVar31 = *(undefined4 *)((uint)puVar23[uStackY_26].unitType << 2),
             *(char *)((int)uVar31 + 0x3f) != '\0')) {
            auStackY_2f2[1] = 0x2410;
            auStackY_2f2[0] = 0x808a;
            iVar14 = 1;
          }
          in_stack_0000ffe0 = (uint16_t)((char *)((ulong)uVar15 << 0x10));
        }
        else {
          auStackY_2f2[1] = 0x2410;
          auStackY_2f2[0] = 0x806a;
          iVar14 = 1;
          if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) != '\0') {
            pcVar10 = ovr_fmVsprintf(" Salvage value %d gold.",
                                     (char *)CONCAT22(in_stack_0000fff6,pcVar10));
            strcat((char *)CONCAT13(uVar38,CONCAT12(bVar36,auStackY_2ca)),
                   (char *)CONCAT13((char)((uint)uVar22 >> 8),CONCAT12((char)uVar22,pcVar10)));
          }
        }
      }
      else {
        auStackY_2f2[1] = *(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118);
        auStackY_2f2[0] = *(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116);
        iVar14 = 1;
      }
      uVar22 = 0x23f1;
      uVar15 = ovr_ovc45_compute8(((unit_t *)GUnits)[uStackY_26].unitType);
      uVar27 = (undefined2)((ulong)GUnits >> 0x10);
      if (((char)uVar15 == '\0') || (7 < ((unit_t *)GUnits)[uStackY_26].level)) {
        uVar22 = 0x23f1;
        uVar15 = ovr_ovc45_compute8(((unit_t *)GUnits)[uStackY_26].unitType);
        if (((char)uVar15 != '\0') && (*(char *)(((uint)uStackY_22 >> 8) * 0x27 + 300) != '\0')) {
          (&stack0xffec)[iVar14] = 3;
          auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
          auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"Upgrade");
          iVar14 = iVar14 + 1;
          uVar27 = 0x195d;
          pcVar10 = (char *)*(uint *)(((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) +
                                      (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 300)) * 0x27 +
                                     0x125);
          in_stack_0000ffe0 = (uint16_t)((char *)(ZEXT24(pcVar10) << 0x10));
          if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) == '\0') {
            pcVar10 = ovr_fmVsprintf(" Upgrade costs %d gp.",
                                     (char *)CONCAT22(in_stack_0000fff6,pcVar10));
            uVar22 = 0x1000;
            strcat((char *)CONCAT13(uVar38,CONCAT12(bVar36,auStackY_2ca)),
                   (char *)CONCAT13((char)((uint)uVar27 >> 8),CONCAT12((char)uVar27,pcVar10)));
          }
        }
      }
      else {
        (&stack0xffec)[iVar14] = 2;
        auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
        auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"Repair");
        iVar14 = iVar14 + 1;
        uVar15 = *(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x125);
        uVar20 = uVar15 % 5;
        pcVar10 = (uint16_t)((char *)(uVar15 / 5 + 1));
        in_stack_0000ffe0 = (uint16_t)((char *)(ZEXT24(pcVar10) << 0x10));
        if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) == '\0') {
          pcVar10 = ovr_fmVsprintf(" Repair costs %d gp.",
                                   (char *)CONCAT22(in_stack_0000fff6,pcVar10));
          uVar22 = 0x1000;
          strcat((char *)CONCAT13(uVar38,CONCAT12(bVar36,auStackY_2ca)),
                 (char *)CONCAT13((char)(uVar20 >> 8),CONCAT12((char)uVar20,pcVar10)));
        }
      }
      bVar9 = ((unit_t *)GUnits)[uStackY_26].unitType;
      uStackY_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_24) + 1)),bVar9);
      if ((((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 0x400) == 0) && (bVar9 != 0xff)) &&
         (*(char *)((int)*(undefined4 *)((uint)bVar9 << 2) + 0x3f) == '\0')) {
        (&stack0xffec)[iVar14] = 7;
        auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
        auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"Information");
        iVar14 = iVar14 + 1;
      }
      uVar33 = 0x19;
      if (((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 4) == 0) && (0xf7 < uStackY_26)) {
        uVar33 = 0x24;
        if (*(char *)((int)Entities + (*(uint16_t *)((uint8_t *)&(in_stack_00000008) + 2)) * 0x37 + 0x1a) != (char)uStackY_24) {
          (&stack0xffec)[iVar14] = 6;
          auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
          auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"New Owner");
          iVar14 = iVar14 + 1;
        }
      }
      if (in_stack_00000010 != '\0') {
        (&stack0xffec)[iVar14] = 4;
        auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
        auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"Change Party");
        iVar14 = iVar14 + 1;
      }
      (&stack0xffec)[iVar14] = 5;
      auStackY_2f2[iVar14 * 2 + 1] =(uint16_t)(unsigned long)(unsigned long)( (char *)0x26510);
      auStackY_2f2[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( (char *)"Done");
      pcVar26 = (uint16_t)((char *)(iVar14 + 1));
      pcVar10 = (uint16_t)((char *)CONCAT11(uVar33,(byte)uStackY_22));
      goldPartyIndex = (byte)uStackY_22;
      puVar11 = auStackY_2f2;
      uVar33 = (undefined1)uVar22;
      cVar6 = (char)((uint)uVar22 >> 8);
      in_stack_0000ffe8 = (stg_tmp_t *)&AgntAnms[0xd].eventFrame;
      entries.seg = (uint16_t)unaff_SS;
      entries.ofs = (uint16_t)puVar11;
      pbVar29 = unaff_SS;
      pcVar21 = (uint16_t)(pcVar26);
      ovr_ovc28_compute2(entries);
      goldPartyIndex = 0xff;
      bVar9 = 0;
      if ((char)puVar11 != '\0') {
        pcVar10 = &stack0xffeb;
        bVar9 = pcVar10[(uint)puVar11 & 0xff];
      }
      in_stack_0000ffe4 = CONCAT11(bVar9,uVar7);
      pcVar12 = (cte_t *)(uint)bVar9;
      if ((cte_t *)((byte *)__C0_ASM_CopyRight + 3) < pcVar12) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iVar14 = (int)pcVar12 * 2;
      switch((uint16_t)pcVar12)   /* hand fix: case values are ints */ {
      case (cte_t *)0x0:
        do {
          if (*(char *)((int)pcVar12 * 0x34 + 5) < '\0') {
            piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
            *piVar2 = *piVar2 - *(int *)((int)&pbVar29[1].h + 1);
          }
L_OVC49_8699_1e09_21A5:
          do {
            uVar27 = (undefined2)((ulong)in_stack_0000ffe0 >> 0x10);
            if ((*(int *)((int)uStackY_22 * 0x34) < 0) || (0xd2 < *(int *)((int)uStackY_22 * 0x34)))
            {
L_OVC49_8699_1e09_2229:
              cVar8 = '\0';
            }
            else {
code_r0x00088b64:
              if ((*(int *)((int)uStackY_22 * 0x34 + 2) < 0) ||
                 ((*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0' &&
                  (uVar15 = ovc49_compute1(*(int *)((int)uStackY_22 * 0x34)), (char)uVar15 != '\0'))
                 )) goto L_OVC49_8699_1e09_2229;
              cVar8 = '\x01';
            }
            if ((cVar8 == '\0') || (0x14 < *(int *)((int)uStackY_22 * 0x34 + 2))) {
              uVar7 = 0;
            }
            else {
              uVar7 = 1;
            }
            uVar31 = CONCAT31(CONCAT21(uVar27,cVar8),uVar7);
            if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
              iVar14 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
              iStackY_28 = *(int *)(&columnScreenY[iVar14]) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
            }
            else {
              iVar14 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
              iStackY_28 = *(int *)(&columnScreenY[iVar14]) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                           -0x16;
            }
            pbVar29 = (brect_t *)((char *)0x22ff);
            *(int *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
            if ((*(char *)((int)uStackY_22 * 0x34 + 0x10) == '\x05') &&
               (*(char *)((int)uStackY_22 * 0x34 + 0xc) != -1)) {
              pbVar29 = (brect_t *)((char *)0x23d5);
              ovr_ovc41_usesXOfs((int)uStackY_22);
            }
            uVar27 = ovc49_agentIsActive((agnt_t *)
                                         CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
            if ((((char)uVar27 == '\0') || (*(int *)((int)uStackY_22 * 0x34 + 2) < 0)) ||
               ((-1 < *(int *)((int)uStackY_22 * 0x34) &&
                ((*(int *)((int)uStackY_22 * 0x34) < 0xd3 &&
                 ((uint)(*(int *)((int)uStackY_22 * 0x34 + 0x28) -
                        *(int *)(in_stack_0000ffe8->cmap + 9)) < 0x96)))))) {
              if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
                uVar15 = ovc49_compute1(*(int *)((int)uStackY_22 * 0x34));
                if ((char)uVar15 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = uStackY_26;
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    uVar16 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar16 + -1;
                  }
                  else {
                    *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4);
                  }
                  uVar27 = ovc49_agentIsActive((agnt_t *)
                                               CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)))
                  ;
                  if ((char)uVar27 == '\0') {
                    uVar16 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar16 + -1;
                  }
                  else {
                    uVar16 = ovr_randBelow(2);
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = (char)uVar16;
                  }
                  pbVar29 = (brect_t *)((char *)0x2337);
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar31 = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  ovc49_body1((agnt_t *)((int)uStackY_22 * 0x34));
                  goto L_OVC49_8699_1e09_2982;
                }
              }
              if (((char)((ulong)uVar31 >> 8) == '\0') ||
                 ((((char)uVar31 == '\0' && (-1 < *(char *)((int)uStackY_22 * 0x34 + 5))) &&
                  (uVar15 = ovc49_agentIsActive((agnt_t *)
                                                CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34))
                                               ), (uVar15 & 0xff) == 0)))) {
                if (*(char *)((int)uStackY_22 * 0x34 + 0x25) != '\x02') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = uStackY_26;
                  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
                    if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                      uVar16 = ovr_randBelow(2);
                      *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar16 * '\x02' + -1;
                    }
                    else {
                      *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4)
                      ;
                    }
                    pbVar29 = (brect_t *)((char *)0x2337);
                    uVar16 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar16 + -1;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar31 = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  ovc49_body1((agnt_t *)((int)uStackY_22 * 0x34));
                }
              }
              else {
                iVar14 = ovc49_usesStExit((agnt_t *)((int)uStackY_22 * 0x34));
                if ((char)iVar14 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = uStackY_26;
                  if ((*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') ||
                     (*(char *)((int)uStackY_22 * 0x34 + 4) != '\0')) {
                    if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
                      *(undefined1 *)((int)uStackY_22 * 0x34 + 4) = 0;
                    }
                    else {
                      *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4)
                      ;
                    }
                  }
                  else {
                    pbVar29 = (brect_t *)((char *)0x2337);
                    uVar16 = ovr_randBelow(2);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar16 * '\x02' + -1;
                  }
                  *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar31 = 0;
                  ovc49_body1((agnt_t *)((int)uStackY_22 * 0x34));
                }
              }
            }
            else {
              *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
            }
L_OVC49_8699_1e09_2982:
            cVar6 = (char)((ulong)uVar31 >> 0x18);
            ovr_ovc49_fillGridCells((byte)uStackY_22 + 1);
            if (cVar6 != '\0') {
              pbVar29 = (brect_t *)((char *)0x22ff);
              uVar27 = ovr_agnt_usesAgntSaved((int)uStackY_22);
              if ((char)uVar27 != '\0') {
                uStackY_22 = (cte_t *)(uStackY_22[-1].info + 0xb);
              }
            }
            uStackY_22 = (cte_t *)&uStackY_22->ofs;
L_OVC49_8699_1e09_29B9:
            bVar9 = (byte)in_stack_0000ffe4;
            if ((int)(uint)AgntCount <= (int)uStackY_22) {
              GGameState = 0x2e;
              if (DebugVerbose != false) {
                pbVar29 = (brect_t *)((int)&AgntAnms[0x38].halfWidth + 1);
                printf("%d \r");
              }
              uStackY_22 =(uint16_t)(unsigned long)(unsigned long)( (cte_t *)0x0);
              goto L_OVC49_8699_1e09_3BDE;
            }
            uVar27 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
            iVar14 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
            ovr_ovc49_fillGridCells(0);
            ovc49_textLongerParalyzed
                      ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                       (byte)uStackY_22);
            uStackY_26 = CONCAT22(*(undefined2 *)((int)uStackY_22 * 0x34),
                                   *(undefined2 *)((int)uStackY_22 * 0x34 + 2));
            uVar15 = ovc49_body1((agnt_t *)((int)uStackY_22 * 0x34));
            in_stack_0000ffe4 = (uint16_t)bVar9;
            uVar22 = 0x1726;
            psVar17 = (stg_tmp_t *)*(undefined2 *)(iVar14 + (uVar15 & 0xff) * 4 + 0x58);
            uVar7 = SUB21(psVar17,0);
            uVar34 = (undefined1)((uint)psVar17 >> 8);
            in_stack_0000ffe8 = ovr_stash_usesStExit(psVar17);
            pcVar21 = (uint16_t)((char *)CONCAT11(uVar34,uVar7));
            uVar33 = (undefined1)uVar22;
            cVar6 = (char)((uint)uVar22 >> 8);
            if (*(char *)((int)uStackY_22 * 0x34 + 4) < '\x01') {
              if (*(char *)((int)uStackY_22 * 0x34 + 4) < '\0') {
                *(int *)((int)uStackY_22 * 0x34) =
                     *(int *)((int)uStackY_22 * 0x34) - (int)(char)in_stack_0000ffe8->cmap[5];
              }
            }
            else {
              *(int *)((int)uStackY_22 * 0x34) =
                   *(int *)((int)uStackY_22 * 0x34) + (int)(char)in_stack_0000ffe8->cmap[5];
            }
            in_stack_0000ffe0 = (uint16_t)((char *)0x1000000);
            if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01') {
              if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\0') {
                piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
                *piVar2 = *piVar2 - *(int *)((int)&pbVar29[1].h + 1);
              }
              else {
                in_stack_0000ffe0 = (uint16_t)((char *)0x0);
              }
            }
            else {
              piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
              *piVar2 = *piVar2 + *(int *)((int)&pbVar29[1].h + 1);
            }
          } while (*(int *)((int)uStackY_22 * 0x34 + 2) < 0x15);
          pcVar12 = uStackY_22;
        } while (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01');
        piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
        *piVar2 = *piVar2 + *(int *)((int)&pbVar29[1].h + 1);
        goto L_OVC49_8699_1e09_21A5;
      case (cte_t *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (cte_t *)0x2:
        pcVar21 = ovr_fmVsprintf("%s: %s %d gold. Feeds %d %s.",
                                 (char *)CONCAT13((char)((uint)pcVar10 >> 8),
                                                  CONCAT12((char)pcVar10,(int)*(undefined4 *)pcVar26
                                                          )));
        pcStack_8 = (uint16_t)((char *)0x2337);
        in_stack_0000fff6 = (stg_tmp_t *)((char *)0x246fd);
        strcpy((char *)CONCAT13(uVar38,CONCAT12(bVar36,auStackY_2ca)),
               (char *)CONCAT22(pcVar10,pcVar21));
        break;
      case (cte_t *)0x3:
        SpecialColors[2] =
             ((char *)0x2b516)[(in_stack_0000fff6->aptr).ofs];
        SpecialColors[3] =
             ((char *)0x29fcf)
             [(in_stack_0000fff6->aptr).ofs];
        SpecialColors[4] = ((char *)0x2b01f)[(in_stack_0000fff6->aptr).ofs];
        SpecialColors[5] =
             *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (in_stack_0000fff6->aptr).ofs);
        SpecialColors[6] =
             *(uint8_t *)((int)(char **)&youlose1Cut1Seg + (in_stack_0000fff6->aptr).ofs);
        SpecialColors[7] = *(uint8_t *)((in_stack_0000fff6->aptr).ofs + 0x936e);
        pcVar10 = (uint16_t)((char *)0x26510);
        SpecialColors[1] = bVar9;
        specialColorsOfs = ovr_stshWrite((uint32_t *)SpecialColors);
        specialColorsSeg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut3Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut4Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut5Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
        trianglsCut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
        trianglsCut6Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
        ovr_stgFreeTmp(in_stack_0000fff6);
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          panel01Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          panel01Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          panel01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          panel01Cut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          panel01Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          panel01Cut3Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          Lbm_nwpanel1.ofs = (uint16_t)ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          Lbm_nwpanel1.seg = (uint16_t)pcVar10;
          nwpanel1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          nwpanel1Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          fullScreenGfxOfs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          fullScreenGfxSeg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          FontHandle.ofs = (uint16_t)ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          FontHandle.seg = (uint16_t)pcVar10;
          nwpanel1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          nwpanel1Cut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          nwpanel1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          nwpanel1Cut3Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          nwpanel1Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          nwpanel1Cut4Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          nwpanel1Cut5Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          nwpanel1Cut5Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          for (iVar14 = 0; iVar14 < 4; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            *(int *)((int)&CrossBlitGfx.seg + iVar14 * 4) = (int)pcVar10;
            ((far_t far *)&CrossBlitGfx + iVar14)->ofs = (uint16_t)pfVar13;
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&crossBlitType2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&crossBlitType2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
        }
        else {
          psVar17 = ovr_grabLbmTR(127);
          pcVar21 = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          panel01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          panel01Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          panel01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          panel01Cut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          panel01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          panel01Cut3Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(15);
          pcStack_8 = (uint16_t)(pcVar21);
          Lbm_nwpanel1.ofs = (uint16_t)ovr_stshWrite((uint32_t *)psVar17);
          Lbm_nwpanel1.seg = (uint16_t)pcStack_8;
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          nwpanel1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          nwpanel1Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          fullScreenGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar13);
          fullScreenGfxSeg = (uint16_t)(unsigned long)pcStack_8;   /* hand fix: 16-bit slot */
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          FontHandle.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar13);
          FontHandle.seg = (uint16_t)pcStack_8;
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          nwpanel1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          nwpanel1Cut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          nwpanel1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          nwpanel1Cut3Seg =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          nwpanel1Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          nwpanel1Cut4Seg =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          nwpanel1Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          nwpanel1Cut5Seg =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
          ovr_stgFreeTmp(psVar17);
          in_stack_0000fff6 = ovr_grabLbm(12);
          pcVar10 = (uint16_t)(pcStack_8);
          for (iVar14 = 0; iVar14 < 4; iVar14 = iVar14 + 1) {
            lVar30 = (long)iVar14 * 0xe;
            pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
            uVar27 = (undefined2)((ulong)lVar30 >> 0x10);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            *(undefined2 *)((int)&CrossBlitGfx.seg + iVar14 * 4) = uVar27;
            ((far_t far *)&CrossBlitGfx + iVar14)->ofs = (uint16_t)pcVar12;
            lVar30 = (long)iVar14 * 0xe;
            pcVar10 = (uint16_t)((char *)((ulong)lVar30 >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels.seg))) = (char)lVar30;
            pixels.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels.seg) + 1)) = (char)((ulong)lVar30 >> 8);
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&crossBlitType2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&crossBlitType2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          for (iVar14 = 0; iVar14 < 0x17; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&csite1Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite1Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 0x18; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&csite2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 0x20; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&csite5Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite5Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 0xe; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 0x11; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites5Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites5Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites4Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites4Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 8; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          for (iVar14 = 0; iVar14 < 5; iVar14 = iVar14 + 1) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites1Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites1Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
        }
        else {
          psVar17 = ovr_grabLbm(93);
          pcVar21 = (uint16_t)(pcVar10);
          for (iVar14 = 0; iVar14 < 6; iVar14 = iVar14 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_00.seg))) = 8;
            pixels_00.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_00.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_00);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite1Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite1Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 6; iVar14 = iVar14 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_01.seg))) = 0x55;
            pixels_01.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_01.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_01);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite1_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite1_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 6; iVar14 = iVar14 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_02.seg))) = 0x9f;
            pixels_02.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_02.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_02);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite1_12Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite1_12Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 5; iVar14 = iVar14 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_03.seg))) = 0xe5;
            pixels_03.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_03.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_03);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite1_18Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite1_18Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(94);
          pcVar10 = (uint16_t)(pcVar21);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            pixels_04.seg = 0;
            pixels_04.ofs = (psVar17->aptr).seg;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_04);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_05.seg))) = 0x6d;
            pixels_05.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_05.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_05);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite2_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite2_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_06.seg))) = 0xd7;
            pixels_06.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_06.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_06);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite2_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite2_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(95);
          pcVar21 = (uint16_t)(pcVar10);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            pixels_07.seg = 0;
            pixels_07.ofs = (psVar17->aptr).seg;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_07);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_08.seg))) = 0x6d;
            pixels_08.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_08.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_08);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite3_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite3_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(96);
          pcVar10 = (uint16_t)(pcVar21);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            pixels_09.seg = 0;
            pixels_09.ofs = (psVar17->aptr).seg;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_09);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite4Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite4Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_10.seg))) = 0x6d;
            pixels_10.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_10.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_10);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite4_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite4_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_11.seg))) = 0xd7;
            pixels_11.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_11.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_11);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite4_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite4_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(531);
          pcVar21 = (uint16_t)(pcVar10);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_12.seg))) = 1;
            pixels_12.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_12.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_12);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite5Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite5Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_13.seg))) = 0x68;
            pixels_13.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_13.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_13);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite5_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite5_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_14.seg))) = 0xd1;
            pixels_14.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_14.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_14);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite5_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite5_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(532);
          pcVar10 = (uint16_t)(pcVar21);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_15.seg))) = 1;
            pixels_15.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_15.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_15);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_16.seg))) = 0x68;
            pixels_16.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_16.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_16);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite6_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite6_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_17.seg))) = 0xd1;
            pixels_17.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_17.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_17);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite6_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&csite6_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(533);
          pcVar21 = (uint16_t)(pcVar10);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_18.seg))) = 1;
            pixels_18.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_18.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_18);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite7Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite7Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_19.seg))) = 0x68;
            pixels_19.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_19.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_19);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite7_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite7_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar21 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_20.seg))) = 0xd1;
            pixels_20.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_20.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_20);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite7_6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar21);
            ((undefined2 *)&csite7_6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(534);
          pcStack_8 = (uint16_t)(pcVar21);
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcStack_8 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_21.seg))) = 1;
            pixels_21.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_21.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_21);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite8Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
            ((undefined2 *)&csite8Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 2; iVar14 = iVar14 + 1) {
            pcStack_8 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x3d) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_22.seg))) = 0x68;
            pixels_22.ofs = (psVar17->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_22.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_22);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&csite8_3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcStack_8);
            ((undefined2 *)&csite8_3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(psVar17);
          in_stack_0000fff6 = ovr_grabLbm(535);
          pcVar10 = (uint16_t)(pcStack_8);
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_23.seg))) = 6;
            pixels_23.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_23.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_23);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_24.seg))) = 0x23;
            pixels_24.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_24.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_24);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites9Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites9Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_25.seg))) = 0x4c;
            pixels_25.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_25.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_25);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites5Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites5Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_26.seg))) = 0x66;
            pixels_26.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_26.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_26);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_27.seg))) = 0x80;
            pixels_27.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_27.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_27);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites7Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites7Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_28.seg))) = 0x9a;
            pixels_28.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_28.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_28);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites4Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites4Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_29.seg))) = 0xb8;
            pixels_29.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_29.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_29);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites3Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites3Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          for (iVar14 = 0; iVar14 < 7; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_30.seg))) = 0xcf;
            pixels_30.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_30.seg) + 1)) = 0;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_30);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites2Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites2Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          (*(uint8_t *)((uint8_t *)&(pixels_31.seg))) = 0xeb;
          pixels_31.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_31.seg) + 1)) = 0;
          pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_31);
          anim_tmstrsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          anim_tmstrsCut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          for (iVar14 = 0; iVar14 < 5; iVar14 = iVar14 + 1) {
            pcVar10 = (uint16_t)((char *)((ulong)((long)iVar14 * 0x1b) >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_32.seg))) = 0xb;
            pixels_32.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_32.seg) + 1)) = 1;
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_32);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&tmstrsSprites1Seg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&tmstrsSprites1Ofs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) != false) {
          in_stack_0000fff6 = ovr_grabLbm(35);
          pcStack_8 = (uint16_t)(pcVar10);
        }
        for (iVar14 = 0; iVar14 < 4; iVar14 = iVar14 + 1) {
          if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
            pfVar13 = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
            ((undefined2 *)&boltSpritesSeg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&boltSpritesOfs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pfVar13);
          }
          else {
            lVar30 = (long)iVar14 * 0x16;
            pcVar10 = (uint16_t)((char *)((ulong)lVar30 >> 0x10));
            (*(uint8_t *)((uint8_t *)&(pixels_33.seg))) = (char)lVar30;
            pixels_33.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_33.seg) + 1)) = (char)((ulong)lVar30 >> 8);
            pfVar13 = ovr_stshRleType2((far_t far *)(&in_stack_0000fff6->aptr)->ofs,pixels_33);
            pcVar12 = ovr_stshStoreFile((uint8_t *)pfVar13);
            ((undefined2 *)&boltSpritesSeg)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
            ((undefined2 *)&boltSpritesOfs)[iVar14 * 2] =(uint16_t)(unsigned long)(unsigned long)( pcVar12);
          }
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          gamfont1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          gamfont1Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          davfontCut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          davfontCut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          davfont2Cut1Ofs =(uint16_t)(unsigned long)(unsigned long)( (cte_t *)ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          davfont2Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          demfont1FontOfs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          demfont1FontSeg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          talkwin9Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          talkwin9Cut1Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          talkwin9Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          talkwin9Cut2Seg =(uint16_t)(unsigned long)(unsigned long)( pcVar10);
          talkwin9Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          talkwin9Cut3Seg = (uint16_t)(pcVar10);
          talkwin9Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          talkwin9Cut4Seg = (uint16_t)(pcVar10);
          talkwin9Cut5Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          talkwin9Cut5Seg = (uint16_t)(pcVar10);
          LbxButton2.ofs = (uint16_t)ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          LbxButton2.seg = (uint16_t)pcVar10;
          pcVar12 = (cte_t *)ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          iVar14 = 0x2410;
code_r0x00083f6a:
          *(char **)&butt01Cut1Seg = pcVar10;
          *(cte_t **)&butt01Cut1Ofs = pcVar12;
          butt01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          butt01Cut2Seg = (uint16_t)(pcVar10);
          butt01Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          butt01Cut3Seg = (uint16_t)(pcVar10);
          butt01Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          butt01Cut4Seg = (uint16_t)(pcVar10);
          butt01Cut5Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          butt01Cut5Seg = (uint16_t)(pcVar10);
          butt01Cut6Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          butt01Cut6Seg = (uint16_t)(pcVar10);
        }
        else {
          ovr_stgFreeTmp(in_stack_0000fff6);
          psVar17 = ovr_grabLbm(8);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          gamfont1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          gamfont1Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(6);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          davfontCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          davfontCut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(140);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          davfont2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          davfont2Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(411);
          FontSize.hi = 0;
          FontSize.lo = 0;
          pfVar13 = ovr_stshProcessFontSub((far_t far *)(&psVar17->aptr)->ofs);
          demfont1FontOfs = (uint16_t)(ovr_stshWrite((uint32_t *)pfVar13));
          demfont1FontSeg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(78);
          (*(uint8_t *)((uint8_t *)&(pixels_34.seg))) = 8;
          pixels_34.ofs = (psVar17->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_34.seg) + 1)) = 0;
          pcVar21 = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_34);
          talkwin9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          (*(uint8_t *)((uint8_t *)&(pixels_35.seg))) = 0xdd;
          pixels_35.ofs = (psVar17->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_35.seg) + 1)) = 0;
          talkwin9Cut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_35);
          talkwin9Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          (*(uint8_t *)((uint8_t *)&(pixels_36.seg))) = 0xd0;
          pixels_36.ofs = (psVar17->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_36.seg) + 1)) = 0;
          talkwin9Cut2Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_36);
          talkwin9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          (*(uint8_t *)((uint8_t *)&(pixels_37.seg))) = 8;
          pixels_37.ofs = (psVar17->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_37.seg) + 1)) = 0;
          talkwin9Cut3Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleType2((far_t far *)(&psVar17->aptr)->ofs,pixels_37);
          talkwin9Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          talkwin9Cut4Seg = (uint16_t)(pcVar21);
          talkwin9Cut5Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          talkwin9Cut5Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(543);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          LbxButton2.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar13);
          LbxButton2.seg = (uint16_t)pcVar21;
          ovr_stgFreeTmp(psVar17);
          in_stack_0000fff6 = ovr_grabLbm(139);
          pcVar10 = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut2Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut3Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut4Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut5Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          butt01Cut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          butt01Cut6Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          button1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          button1Cut1Seg = (uint16_t)(pcVar10);
          button1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          button1Cut2Seg = (uint16_t)(pcVar10);
          button1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          button1Cut3Seg = (uint16_t)(pcVar10);
          back03Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          back03Cut1Seg = (uint16_t)(pcVar10);
          back03Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          back03Cut2Seg = (uint16_t)(pcVar10);
          midgrnd5Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          midgrnd5Cut1Seg = (uint16_t)(pcVar10);
          midgrnd5Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          midgrnd5Cut2Seg = (uint16_t)(pcVar10);
          strong4Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          strong4Cut1Seg = (uint16_t)(pcVar10);
          strong4Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          strong4Cut2Seg = (uint16_t)(pcVar10);
          marbleCut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          marbleCut1Seg = (uint16_t)(pcVar10);
          marbleCut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          marbleCut2Seg = (uint16_t)(pcVar10);
          far_t_2000_d3e4.ofs = (uint16_t)ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          far_t_2000_d3e4.seg = (uint16_t)pcVar10;
          back2Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          back2Cut1Seg = (uint16_t)(pcVar10);
          back2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          back2Cut2Seg = (uint16_t)(pcVar10);
          midl3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          midl3Cut1Seg = (uint16_t)(pcVar10);
          midl3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          midl3Cut2Seg = (uint16_t)(pcVar10);
          frnt3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          frnt3Cut1Seg = (uint16_t)(pcVar10);
          frnt3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          frnt3Cut2Seg = (uint16_t)(pcVar10);
          winrebg1Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          winrebg1Cut1Seg = (uint16_t)(pcVar10);
          winrebg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          winrebg1Cut2Seg = (uint16_t)(pcVar10);
          winremg2Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          winremg2Cut1Seg = (uint16_t)(pcVar10);
          winremg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          winremg2Cut2Seg = (uint16_t)(pcVar10);
          winrefg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          winrefg1Cut1Seg = (uint16_t)(pcVar10);
          winrefg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          winrefg1Cut2Seg = (uint16_t)(pcVar10);
          captbg2Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          captbg2Cut1Seg = (uint16_t)(pcVar10);
          captbg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          captbg2Cut2Seg = (uint16_t)(pcVar10);
          captmg3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          captmg3Cut1Seg = (uint16_t)(pcVar10);
          captmg3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          captmg3Cut2Seg = (uint16_t)(pcVar10);
          captfg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          captfg1Cut1Seg = (uint16_t)(pcVar10);
          captfg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          captfg1Cut2Seg = (uint16_t)(pcVar10);
          l1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l1Cut1Seg = (uint16_t)(pcVar10);
          l1Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l1Cut2Seg = (uint16_t)(pcVar10);
          l1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l1Cut3Seg = (uint16_t)(pcVar10);
          l4Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l4Cut1Seg = (uint16_t)(pcVar10);
          l4Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l4Cut2Seg = (uint16_t)(pcVar10);
          l4Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l4Cut3Seg = (uint16_t)(pcVar10);
          l7Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l7Cut1Seg = (uint16_t)(pcVar10);
          l7Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l7Cut2Seg = (uint16_t)(pcVar10);
          l7Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l7Cut3Seg = (uint16_t)(pcVar10);
          l2Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l2Cut1Seg = (uint16_t)(pcVar10);
          l2Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l2Cut2Seg = (uint16_t)(pcVar10);
          l2Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l2Cut3Seg = (uint16_t)(pcVar10);
          l5Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l5Cut1Seg = (uint16_t)(pcVar10);
          l5Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l5Cut2Seg = (uint16_t)(pcVar10);
          l5Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l5Cut3Seg = (uint16_t)(pcVar10);
          l8Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l8Cut1Seg = (uint16_t)(pcVar10);
          l8Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l8Cut2Seg = (uint16_t)(pcVar10);
          l8Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l8Cut3Seg = (uint16_t)(pcVar10);
          l3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l3Cut1Seg = (uint16_t)(pcVar10);
          l3Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l3Cut2Seg = (uint16_t)(pcVar10);
          l3Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l3Cut3Seg = (uint16_t)(pcVar10);
          l6Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l6Cut1Seg = (uint16_t)(pcVar10);
          l6Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l6Cut2Seg = (uint16_t)(pcVar10);
          l6Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l6Cut3Seg = (uint16_t)(pcVar10);
          l9Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l9Cut1Seg = (uint16_t)(pcVar10);
          l9Cut2Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l9Cut2Seg = (uint16_t)(pcVar10);
          l9Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          l9Cut3Seg = (uint16_t)(pcVar10);
        }
        else {
          psVar17 = ovr_grabLbm(179);
          pcVar21 = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          button1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          button1Cut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          button1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          button1Cut2Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          button1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          button1Cut3Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(158);
          pcVar10 = (uint16_t)(pcVar21);
          back03Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          back03Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          back03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          back03Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(159);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          midgrnd5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          midgrnd5Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(159);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          midgrnd5Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          midgrnd5Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(160);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          strong4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          strong4Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(160);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          strong4Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          strong4Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(161);
          pcVar21 = (uint16_t)(pcVar10);
          marbleCut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          marbleCut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          marbleCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          marbleCut2Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          far_t_2000_d3e4.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar13);
          far_t_2000_d3e4.seg = (uint16_t)pcVar21;
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(412);
          pcVar10 = (uint16_t)(pcVar21);
          back2Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          back2Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          back2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          back2Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(414);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          midl3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          midl3Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(414);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          midl3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          midl3Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(413);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          frnt3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          frnt3Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(413);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          frnt3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          frnt3Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(422);
          pcVar21 = (uint16_t)(pcVar10);
          winrebg1Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          winrebg1Cut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          winrebg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          winrebg1Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(421);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          winremg2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          winremg2Cut1Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(421);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          winremg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          winremg2Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(420);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          winrefg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          winrefg1Cut1Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(420);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          winrefg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          winrefg1Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(437);
          pcVar10 = (uint16_t)(pcVar21);
          captbg2Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          captbg2Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          captbg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          captbg2Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(438);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          captmg3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          captmg3Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(438);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          captmg3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          captmg3Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(439);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          captfg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          captfg1Cut1Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(439);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          captfg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          captfg1Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
L_init_assets2_2FC9:
          psVar17 = ovr_grabLbm(305);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l1Cut1Seg = (uint16_t)(pcVar21);
          l1Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l1Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(305);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l1Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(328);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l4Cut1Seg = (uint16_t)(pcVar21);
          l4Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l4Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(328);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l4Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l4Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(331);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l7Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l7Cut1Seg = (uint16_t)(pcVar21);
          l7Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l7Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(331);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l7Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l7Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(307);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l2Cut1Seg = (uint16_t)(pcVar21);
          l2Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l2Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(307);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l2Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l2Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(329);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l5Cut1Seg = (uint16_t)(pcVar21);
          l5Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l5Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(329);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l5Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l5Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(332);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l8Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l8Cut1Seg = (uint16_t)(pcVar21);
          l8Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l8Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(332);
          pcVar26 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l8Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l8Cut3Seg = (uint16_t)(pcVar26);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(306);
          pcVar10 = (uint16_t)(pcVar26);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l3Cut1Seg = (uint16_t)(pcVar10);
          l3Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l3Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(306);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l3Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l3Cut3Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(330);
          pcVar10 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l6Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l6Cut1Seg = (uint16_t)(pcVar10);
          l6Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l6Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(330);
          pcVar21 = (uint16_t)(pcVar10);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l6Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l6Cut3Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(333);
          pcVar26 = (uint16_t)(pcVar21);
          ovr_stshUniqueColorsRemap(psVar17);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          l9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l9Cut1Seg = (uint16_t)(pcVar26);
          l9Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar17->cmap + 0x1e0)));
          l9Cut2Seg = (uint16_t)(pcVar26);
          ovr_stgFreeTmp(psVar17);
          in_stack_0000fff6 = ovr_grabLbm(333);
          pcVar10 = (uint16_t)(pcVar26);
          ovr_stshUniqueColorsRemap(in_stack_0000fff6);
          pfVar13 = ovr_stshRleCut((far_t far *)(&in_stack_0000fff6->aptr)->ofs);
          l9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          l9Cut3Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        ovr_stshInitAudioAssets((*(uint8_t *)((uint8_t *)&(agnt))));
        ovr_stshLoadAudioDrivers((*(uint8_t *)((uint8_t *)&(agnt))));
        ovr_stshInitSprites((*(uint8_t *)((uint8_t *)&(agnt))));
        stshInitTxtFiles((*(uint8_t *)((uint8_t *)&(agnt))));
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          sky06FliOfs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          sky06FliSeg = (uint16_t)(pcVar10);
          l9Cut4Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          l9Cut4Seg = (uint16_t)(pcVar10);
          ssilogoCut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          ssilogoCut1Seg = (uint16_t)(pcVar10);
          ssilogoCut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          ssilogoCut2Seg = (uint16_t)(pcVar10);
          youlose1Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          youlose1Cut1Seg = (uint16_t)(pcVar10);
          youlose1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          youlose1Cut2Seg = (uint16_t)(pcVar10);
          cred01Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          cred01Cut1Seg = (uint16_t)(pcVar10);
          cred01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          cred01Cut2Seg = (uint16_t)(pcVar10);
          cred02Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          cred02Cut1Seg = (uint16_t)(pcVar10);
          cred02Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          cred02Cut2Seg = (uint16_t)(pcVar10);
          cred03Cut1Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          cred03Cut1Seg = (uint16_t)(pcVar10);
          cred03Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t far *)in_stack_0000fff6));
          cred03Cut2Seg = (uint16_t)(pcVar10);
          cred03Cut3Ofs = ovr_stshAllocStub((far_t far *)in_stack_0000fff6);
          cred03Cut3Seg = (uint16_t)(pcVar10);
        }
        else {
          sky06FliOfs = ovr_stshStoreFile_2((far_t far *)(char *)StshNames[0x19f],
                                            (char *)(ulong)(*(uint16_t *)((uint8_t *)&(StshNames[0x19f]) + 2)),
                                            (uint16_t)in_stack_0000fff6);
          sky06FliSeg = (uint16_t)(pcVar10);
          l9Cut4Ofs = ovr_stshStoreFile_2((far_t far *)"bolt12.fli",(char *)0x2410,
                                          (uint16_t)in_stack_0000fff6);
          l9Cut4Seg = (uint16_t)(pcVar10);
          psVar17 = ovr_grabLbm(417);
          pcVar21 = (uint16_t)(pcVar10);
          ssilogoCut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          ssilogoCut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          ssilogoCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          ssilogoCut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(542);
          pcVar10 = (uint16_t)(pcVar21);
          youlose1Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          youlose1Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          youlose1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          youlose1Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(539);
          pcVar21 = (uint16_t)(pcVar10);
          cred01Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          cred01Cut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          cred01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          cred01Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(540);
          pcVar10 = (uint16_t)(pcVar21);
          cred02Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          cred02Cut1Seg = (uint16_t)(pcVar10);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          cred02Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          cred02Cut2Seg = (uint16_t)(pcVar10);
          ovr_stgFreeTmp(psVar17);
          psVar17 = ovr_grabLbm(541);
          pcVar21 = (uint16_t)(pcVar10);
          cred03Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar17));
          cred03Cut1Seg = (uint16_t)(pcVar21);
          pfVar13 = ovr_stshRleCut((far_t far *)(&psVar17->aptr)->ofs);
          cred03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar13);
          cred03Cut2Seg = (uint16_t)(pcVar21);
          ovr_stgFreeTmp(psVar17);
          cred03Cut3Ofs = ovr_stshStoreFile_2((far_t far *)"save.999",(char *)0x2410,(uint16_t)psVar17);
          cred03Cut3Seg = (uint16_t)(pcVar21);
        }
        return (uint)cred03Cut3Ofs;
      case (cte_t *)0x4:
        *pcVar26 = *pcVar26 + (0x44 < bVar9);
        goto L_init_assets2_2FC9;
      case (cte_t *)0x5:
        goto code_r0x00083f6a;
      case (cte_t *)0x6:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (cte_t *)0x7:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    } while( true );
  case 1:
    if (((uVar15 != 0) || (uVar16 = ovr_randBelow(4), (uVar16 & 0xff) != 0)) &&
       ((-1 < *(char *)((int)&agnt->targetX + 1) && (agnt->moveState == 0x1)))) {
      uVar16 = ovr_randBelow(8);
      if ((uVar16 & 0xff) != 0) {
        return uVar16 & 0xff;
      }
    }
    agnt->moveState = 0x1;
    uVar16 = ovr_randBelow(2);
    *(undefined1 *)((int)&agnt->targetX + 1) = (char)uVar16;
    uVar16 = ovr_randBelow(2);
    cVar6 = (char)uVar16 * '\x02' + -1;
    uVar15 = CONCAT11((char)(uVar16 >> 8),cVar6);
    *(char *)&agnt->targetX = cVar6;
    if ((int)paVar4->x < 0x2a) {
      *(undefined1 *)&agnt->targetX = 0xff;
      return uVar15;
    }
    if (0xb4 < (int)paVar4->x) {
      *(undefined1 *)&agnt->targetX = 1;
      return uVar15;
    }
    *(undefined1 *)((int)&agnt->targetX + 1) = 1;
    return uVar15;
  case 2:
    break;
  case 3:
    break;
  case 4:
    uVar39 = 9;
    uVar41 = 0;
    if (agnt->level != 0x0) {
      cVar8 = -1;
      uVar15 = ((int)((-*(int *)(CONCAT11(cVar6,uVar33) + 0x17) -
                      (int)(*(((agntG_t *)agnt->gdata)->extents + 1))[0]) + paVar4->x) >> 1) + 1;
      uVar20 = uVar15 - ((int)((agntG_t *)agnt->gdata)->extents[1][1] -
                         (int)(*(((agntG_t *)agnt->gdata)->extents + 1))[0] >> 1);
      goto L_OVC49_8699_0000_0121;
    }
    break;
  case 5:
    goto code_r0x00088b64;
  }
  cVar8 = '\x01';
  uVar15 = ((int)((int)(*(((agntG_t *)agnt->gdata)->extents + 1))[0] +
                  *(int *)(CONCAT11(cVar6,uVar33) + 0x17) + paVar4->x) >> 1) - 1;
  uVar20 = uVar15 + ((int)((agntG_t *)agnt->gdata)->extents[1][1] -
                     (int)(*(((agntG_t *)agnt->gdata)->extents + 1))[0] >> 1);
L_OVC49_8699_0000_0121:
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  uVar37 = uVar20;
  if ((int)uVar20 < 0) {
    uVar37 = 0;
  }
  if (0x68 < (int)uVar15) {
    uVar15 = 0x68;
  }
  if (0x68 < (int)uVar37) {
    uVar37 = 0x68;
  }
  do {
    if (uVar15 == uVar37) {
      *in_stack_00000008 = '\0';
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
      return uVar20 & 0xff00;
    }
    for (pcStack_8 = (char *)0x0;
        (int)pcStack_8 <= (int)((agntG_t *)agnt->gdata)->extents[1][2] >> 1;
        pcStack_8 = (char *)((int)pcStack_8 + 1)) {
      cVar6 = -1;
      while (((cVar6 < '\x02' && (pcStack_8 != (char *)0x0)) ||
             ((cVar6 == -1 && (pcStack_8 == (char *)0x0))))) {
        iVar14 = CONCAT11(uVar41,uVar39) + (int)pcStack_8 * (int)cVar6;
        if ((-1 < iVar14) && (iVar14 < 10)) {
          if ((*(char *)(iVar14 * 0x69 + uVar15 + 0x8fa) != '\0') &&
             (((*(byte *)(iVar14 * 0x69 + uVar15 + 0x8fa) <= AgntCount &&
               (*(byte *)((uint)*(byte *)(iVar14 * 0x69 + uVar15 + 0x8fa) * 0x34 + -5) !=
                in_stack_0000fffd)) &&
              (*(char *)((uint)*(byte *)(iVar14 * 0x69 + uVar15 + 0x8fa) * 0x34 + -0x10) == '\0'))))
          {
            *in_stack_00000008 = *(char *)(iVar14 * 0x69 + uVar15 + 0x8fa);
            bVar5 = ovr_agnt_compute4(in_stack_00000008);
            if (bVar5) {
              return CONCAT11(extraout_AH,*in_stack_00000008);
            }
          }
          if (((*(char *)(iVar14 * 0x69 + uVar15 + 0x4e0) != '\0') &&
              (*(byte *)(iVar14 * 0x69 + uVar15 + 0x4e0) <= AgntCount)) &&
             ((*(byte *)((uint)*(byte *)(iVar14 * 0x69 + uVar15 + 0x4e0) * 0x34 + -5) !=
               in_stack_0000fffd &&
              (*(char *)((uint)*(byte *)(iVar14 * 0x69 + uVar15 + 0x4e0) * 0x34 + -0x10) == '\0'))))
          {
            *in_stack_00000008 = *(char *)(iVar14 * 0x69 + uVar15 + 0x4e0);
            return CONCAT11((char)((uint)(iVar14 * 0x69) >> 8),*in_stack_00000008);
          }
        }
        cVar6 = cVar6 + '\x02';
      }
    }
    uVar20 = (uint)cVar8;
    uVar15 = uVar15 + uVar20;
  } while( true );
L_OVC49_8699_1e09_3BDE:
  if ((int)(uint)AgntCount <= (int)uStackY_22) goto L_OVC49_8699_1e09_3BF1;
  uVar27 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
  iVar14 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
  in_stack_0000ffe4 =
       CONCAT11(*(undefined1 *)((int)uStackY_22 * 0x34 + 0x12),(char)in_stack_0000ffe4);
  GGameState = 0x37;
  if (DebugVerbose != false) {
    pbVar29 = (brect_t *)((int)&AgntAnms[0x38].halfWidth + 1);
    printf("%d \r");
  }
  psVar17 = ovr_stash_usesStExit
                      ((stg_tmp_t *)*(undefined2 *)(iVar14 + (in_stack_0000ffe4 >> 8) * 4 + 0x58));
  GGameState = 0x38;
  pbVar19 = (uint16_t)(pbVar29);
  if (DebugVerbose != false) {
    pbVar19 = (brect_t *)((char *)0x2337);
    printf("%d \r");
  }
  uVar16 = *(int *)((int)uStackY_22 * 0x34) + 0xc;
  if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
    bVar9 = 0x3e;
    uVar33 = 0x95;
    iVar18 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
    iStackY_28 = *(int *)(&columnScreenY[iVar18]) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
  }
  else {
    bVar9 = 0xd9;
    uVar33 = 0x94;
    iVar18 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
    uVar31 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
    iStackY_28 = *(int *)(&columnScreenY[iVar18]) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                 (int)*(char *)((int)uVar31 + 0x52) + -0x16;
  }
  pbVar28 = (brect_t *)((char *)0x22ff);
  *(uint16_t *)((int)uStackY_22 * 0x34 + 0x26) = uVar16;
  *(int *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0') {
      GGameState = 0x32;
      pbVar19 = &bStackY_32;
      in_stack_0000ffe4 = 0x22ff;
      pbVar28 = (brect_t *)((char *)0x263d3);
      gfx.seg = uVar16;
      gfx.ofs = (uint16_t)(psVar17->cmap + 6);
      bVar9 = bVar36;
      uVar33 = uVar38;
      ovr_blitGfxRect(gfx);
      GGameState = 0x33;
      if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 100) != 0) {
        pbVar19 = &bStackY_32;
        bVar9 = *(byte *)((int)uStackY_22 * 0x34 + 0x23);
        pcVar1 = (uint16_t)((char *)((int)uStackY_22 * 0x34 + 0x23));
        *pcVar1 = *pcVar1 + -1;
        uVar15 = bVar9 & 3;
        in_stack_0000ffe4 = 0x22d3;
        pbVar28 = (brect_t *)((char *)0x263d3);
        gfx_00.seg = ((undefined2 *)&crossBlitType2Seg)[uVar15 * 2];
        gfx_00.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar15 * 2];
        bVar9 = bVar36;
        uVar33 = uVar38;
        ovr_blitGfxRect(gfx_00);
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x01') {
      uVar31 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
      if ((*(uint *)((int)uVar31 + 0x40) & 2) == 0) {
        gfx_02.seg = uVar16;
        gfx_02.ofs = (uint16_t)(psVar17->cmap + 6);
        ovr_blitGfxRect(gfx_02);
        pbVar19 = &bStackY_32;
        uVar15 = *(byte *)((int)uStackY_22 * 0x34 + 0x23) & 3;
        in_stack_0000ffe4 = 0x22d3;
        pbVar28 = (brect_t *)((char *)0x263d3);
        gfx_03.seg = ((undefined2 *)&crossBlitType2Seg)[uVar15 * 2];
        gfx_03.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar15 * 2];
        bVar9 = bVar36;
        uVar33 = uVar38;
        ovr_blitGfxRect(gfx_03);
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
        else {
          pcVar1 = (uint16_t)((char *)((int)uStackY_22 * 0x34 + 0x23));
          *pcVar1 = *pcVar1 + -1;
        }
      }
      else {
        pbVar19 = &bStackY_32;
        in_stack_0000ffe4 = 0x22ff;
        pbVar28 = (brect_t *)((char *)0x263d3);
        gfx_01.seg = uVar16;
        gfx_01.ofs = (uint16_t)(psVar17->cmap + 6);
        bVar9 = bVar36;
        uVar33 = uVar38;
        ovr_blitGfxRect(gfx_01);
        if ((int)(uint)*(byte *)((int)&pbVar19[2].h + 1) <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1
           ) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x02') {
      if ((char)(in_stack_0000ffe4 >> 8) == '\x12') {
        pbVar19 = &bStackY_32;
        in_stack_0000ffe4 = 0x22ff;
        pbVar28 = (brect_t *)((char *)0x263d3);
        gfx_04.seg = uVar16;
        gfx_04.ofs = (uint16_t)(psVar17->cmap + 6);
        bVar9 = bVar36;
        uVar33 = uVar38;
        ovr_blitGfxRect(gfx_04);
        if ((int)(uint)*(byte *)((int)&pbVar19[2].h + 1) <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1
           ) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          pbVar28 = (brect_t *)((char *)0x23d5);
          bVar9 = 0x9a;
          uVar33 = 0x99;
          ovr_ovc41_paralyzeNearbyAgents((int)uStackY_22);
        }
      }
      else {
        ovr_randBelow(0x100);
        bVar9 = 1;
        uVar33 = 0;
        pbVar19 = (brect_t *)
                  CONCAT11((char)((uint)((int)uStackY_22 * 0x34) >> 8),
                           *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf));
        gfx_09.seg = (uint16_t)unaff_SS;
        gfx_09.ofs = (uint16_t)&bStackY_32.h;
        uStackY_22 = (cte_t *)0x2337;
        pbVar28 = (brect_t *)((char *)0x263d3);
        uStackY_26 = CONCAT22(0x98d2,uStackY_26);
        in_stack_0000ffe4 = uVar16;
        ovr_gfxRlePrepare(gfx_09,uVar16);
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          pbVar28 = (brect_t *)((char *)0x23d5);
          bVar9 = 0x20;
          uVar33 = 0x99;
          ovr_ovc41_paralyzeNearbyAgents((int)uStackY_22);
        }
        else {
          pcVar1 = (uint16_t)((char *)((int)uStackY_22 * 0x34 + 0x23));
          *pcVar1 = *pcVar1 + -1;
        }
      }
    }
  }
  else {
    bVar9 = 0xff;
    uVar33 = 0;
    pbVar19 = (brect_t *)
              CONCAT11((char)((uint)((int)uStackY_22 * 0x34) >> 8),
                       *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf));
    gfx_08.seg = (uint16_t)unaff_SS;
    gfx_08.ofs = (uint16_t)&bStackY_32.h;
    uStackY_22 = (cte_t *)0x22ff;
    pbVar28 = (brect_t *)((char *)0x263d3);
    uStackY_26 = CONCAT22(0x95e4,uStackY_26);
    in_stack_0000ffe4 = uVar16;
    ovr_gfxRlePrepare(gfx_08,uVar16);
  }
  pbVar29 = (uint16_t)(pbVar28);
  if (*(char *)((int)uStackY_22 * 0x34 + 0x30) != '\0') {
    uVar33 = (undefined1)((uint)&bStackY_32 >> 8);
    pbVar29 = (brect_t *)((char *)0x22ff);
    bVar9 = (byte)uStackY_22;
    ovr_agnt_drawSpriteFrame((byte)uStackY_22);
    pbVar19 = (uint16_t)(pbVar28);
  }
  cVar6 = (char)in_stack_0000ffe4;
  if (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 8) == 0) ||
     ((uint)*(byte *)((int)&pbVar19[2].w + 1) != *(uint *)((int)uStackY_22 * 0x34 + 6))) {
    if (((uint)*(byte *)((int)&pbVar19[2].w + 1) == *(uint *)((int)uStackY_22 * 0x34 + 6)) &&
       ((*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0' &&
        (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)))) {
      if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') {
        cVar8 = ovc49_usesFrameIndex2
                          ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                           (byte *)CONCAT13(uVar38,CONCAT12(bVar36,&stack0xffe4)));
        if (cVar8 == '\0') {
          if ((*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x03') ||
             (*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x0f')) {
            ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
            ovr_play_sfxU(0x33);
          }
          animBranchCode = 9;
          pbVar29 = (brect_t *)((char *)0x22ff);
          ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = cVar6 + -1;
        }
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        cVar8 = ovc49_usesFrameIndex
                          ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                           (byte *)CONCAT13(uVar38,CONCAT12(bVar36,&stack0xffe4)));
        if (cVar8 != '\0') {
          pbVar29 = (brect_t *)((char *)0x26489);
          uVar15 = ovr_ovc27_compute1((agnt_t *)((int)uStackY_22 * 0x34));
          if ((char)uVar15 != '\0') {
            *(char *)((int)uStackY_22 * 0x34 + 0xc) = cVar6 + -1;
            goto L_OVC49_8699_1e09_3310;
          }
        }
        animBranchCode = 10;
        pbVar29 = (brect_t *)((char *)0x22ff);
        ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) ||
              (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05')) {
        pbVar29 = (brect_t *)((char *)0x22ff);
        cVar8 = ovr_agnt_computeFrameExtents((agnt_t *)((int)uStackY_22 * 0x34));
        if (cVar8 == '\0') {
          animBranchCode = 0xb;
          pbVar29 = (brect_t *)((char *)0x22ff);
          ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = cVar6 + -1;
        }
      }
L_OVC49_8699_1e09_3310:
      bVar9 = *(char *)((int)uStackY_22 * 0x34 + 0xc) + 1;
      in_stack_0000ffe4 = (uint16_t)bVar9;
      uVar33 = SUB21(pbVar29,0);
      uVar7 = (undefined1)((uint)pbVar29 >> 8);
      if (((bVar9 == 0) || (*(char *)((uint)bVar9 * 0x34 + -0x10) != '\0')) ||
         ((*(char *)((int)uStackY_22 * 0x34 + 0xd) != '\x06' &&
          ((0x14 < *(int *)((int)uStackY_22 * 0x34 + 2) ||
           (0x14 < *(int *)((uint)bVar9 * 0x34 + -0x32))))))) {
        animBranchCode = 0xc;
        pbVar29 = (brect_t *)((char *)0x22ff);
        ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        pbVar29 = (brect_t *)((char *)0x26489);
        uVar15 = ovr_ovc27_spellNotice((int)uStackY_22);
        if ((uVar15 & 0xff) == 0) {
          animBranchCode = 0xf;
          pbVar29 = (brect_t *)((char *)0x22ff);
          ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
        }
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) &&
              (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)) {
        iVar35 = -0x61fb;
        iVar18 = ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
        uVar34 = (undefined1)((uint)iVar18 >> 8);
        bVar9 = *(byte *)(iVar35 + 0x1d);
        iVar18 = 0x22f8;
        pbVar29 = (brect_t *)((char *)0x263f8);
        ovr_play_sfxU(bVar9);
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 0;
        *(char *)((int)uStackY_22 * 0x34 + 10) = *(char *)(iVar18 + 0x15) + (char)iStackY_28;
        if (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0') {
          *(int *)((int)uStackY_22 * 0x34 + 8) = *(int *)(iVar18 + 0x13) + uVar16;
        }
        else {
          *(int *)((int)uStackY_22 * 0x34 + 8) = uVar16 - *(int *)(iVar18 + 0x13);
        }
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xb) =
             *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf);
      }
      else if ((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') &&
              (uVar31 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d),
              (*(uint *)((int)uVar31 + 0x3c) & 8) == 0)) {
        iVar18 = -0x60d4;
        ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
        ovr_play_sfxU(*(byte *)(iVar18 + 0x1d));
        pbVar29 = (brect_t *)((char *)0x23d5);
        ovr_ovc41_resolveSpecialAttack
                  ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                   (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x03') {
        uVar15 = ovr_agnt_compute12((agnt_t *)((int)uStackY_22 * 0x34));
        if (((char)uVar15 != '\0') &&
           ((*(uint *)((in_stack_0000ffe4 & 0xff) * 0x34 + -9) & 0x800) == 0)) {
          uVar31 = *(undefined4 *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x1d);
          if (((*(uint *)((int)uVar31 + 0x14) & 2) == 0) ||
             ((uVar16 = ovr_randBelow(2), (uVar16 & 0xff) != 0 ||
              ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
            ovr_OVC41_6a8f_01e7_entry((agnt_t *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x34));
            puVar3 = (uint *)((in_stack_0000ffe4 & 0xff) * 0x34 + -9);
            *puVar3 = *puVar3 | 0x800;
            ovr_audio_panFromX((agnt_t *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x34));
            ovr_play_sfxU(0x1b);
          }
          else {
            ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
            ovr_play_sfxU(0x1b);
            ovr_OVC41_6a8f_01e7_entry((agnt_t *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x34));
            puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
            *puVar3 = *puVar3 | 0x800;
          }
        }
        animBranchCode = 0xd;
        pbVar29 = (brect_t *)((char *)0x22ff);
        ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05') {
        iVar18 = -0x5edf;
        ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
        pbVar29 = (brect_t *)((char *)0x263f8);
        ovr_play_sfxU(*(byte *)(iVar18 + 0x1d));
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0xf5;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 1;
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x06') {
        iVar18 = -0x5e71;
        ovr_audio_panFromX((agnt_t *)((int)uStackY_22 * 0x34));
        ovr_play_sfxU(*(byte *)(iVar18 + 0x1d));
        pbVar29 = (brect_t *)((char *)0x23d5);
        ovr_ovc41_resolveSpecialAttack
                  ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                   (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
      }
      else {
        animBranchCode = 0xe;
        pbVar29 = (brect_t *)((char *)0x22ff);
        ovr_agnt_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      }
    }
  }
  else {
    pbVar29 = (brect_t *)((char *)0x23d5);
    ovr_ovc41_resolveSpecialAttack
              ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
               (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
  }
  GGameState = 0x39;
  if (DebugVerbose != false) {
    pbVar29 = (brect_t *)((int)&AgntAnms[0x38].halfWidth + 1);
    printf("%d \r");
  }
  piVar2 = (int *)((int)uStackY_22 * 0x34 + 6);
  *piVar2 = *piVar2 + 1;
  if (*(char *)((int)uStackY_22 * 0x34 + 0xe) != -1) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0xc) == -1) {
      pbVar29 = (brect_t *)((char *)0x22ff);
      ovr_agnt_usesAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      animBranchCode = 7;
    }
    else if ((*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') ||
            (*(char *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
      uVar34 = (undefined1)uVar27;
      uVar39 = (undefined1)((uint)uVar27 >> 8);
      uVar33 = (undefined1)iVar14;
      uVar7 = (undefined1)((uint)iVar14 >> 8);
      if (*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') {
        bVar9 = 6;
      }
      else {
        bVar9 = *(byte *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16);
      }
      uVar27 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar34,iVar14)) >> 0x10);
      piVar24 = (int *)(iVar14 + (uint)bVar9 * 4);
      if (*piVar24 == 0 && piVar24[1] == 0) {
        uVar34 = (undefined1)SprProjectiles.seg;
        uVar39 = (undefined1)(SprProjectiles.seg >> 8);
        uVar33 = (undefined1)SprProjectiles.ofs;
        uVar7 = (undefined1)(SprProjectiles.ofs >> 8);
      }
      uVar27 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar34,CONCAT11(uVar7,uVar33))) >> 0x10);
      puVar25 = (uint *)(CONCAT11(uVar7,uVar33) + (uint)bVar9 * 4);
      uVar15 = *puVar25 | puVar25[1];
      if (uVar15 == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xf);
      }
      psVar17 = ovr_stash_usesStExit
                          ((stg_tmp_t *)
                           *(undefined2 *)(CONCAT11(uVar7,uVar33) + (uint)bVar9 * 4 + 0x58));
      GGameState = 0x30;
      pbVar19 = &bStackY_32;
      uVar16 = *(uint16_t *)((int)uStackY_22 * 0x34 + 8);
      uVar7 = (undefined1)uVar16;
      cVar6 = (char)(uVar16 >> 8);
      puVar32 = psVar17->cmap + 6;
      in_stack_0000ffe4 = 0x2337;
      pbVar29 = (brect_t *)((char *)0x263d3);
      gfx_05.seg = uVar16;
      gfx_05.ofs = (uint16_t)puVar32;
      bVar9 = bVar36;
      uVar33 = uVar38;
      ovr_blitGfxRect(gfx_05);
      agnt_00 = (agnt_t *)CONCAT11(uVar33,bVar9);
      GGameState = 0x31;
      if ((pbVar19[2].seg & 2) == 0) {
        if (*(char *)((int)uStackY_22 * 0x34 + 0xb) == '\0') {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 + (int)*(char *)(uVar16 + 5);
        }
        else {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 - (int)*(char *)(uVar16 + 5);
        }
        puVar32 = puVar32 + 1;
        if ((undefined1 *)(*(byte *)((int)&pbVar19[2].w + 1) + 1) == puVar32) {
          agnt_00 = (agnt_t *)((int)uStackY_22 * 0x34);
          pbVar19 = (brect_t *)((char *)0x263d3);
          pbVar29 = (brect_t *)((char *)0x23d5);
          ovr_ovc41_specialAttack(agnt_00);
        }
        if ((int)puVar32 < (int)(uint)*(byte *)((int)&pbVar19[2].h + 1)) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = (char)puVar32;
        }
        else {
          animBranchCode = 8;
          pbVar29 = (brect_t *)((char *)0x22ff);
          ovr_agnt_usesAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
        }
      }
      else {
        pbVar29 = (brect_t *)((char *)0x22ff);
        ovr_agnt_usesStExit((agnt_t *)((int)uStackY_22 * 0x34));
      }
    }
    else {
      pbVar29 = (brect_t *)((char *)0x26489);
      ovr_ovc27_usesBlitGfxRect((int)uStackY_22);
    }
  }
  uStackY_22 = (cte_t *)((int)uStackY_22 + 1);
  goto L_OVC49_8699_1e09_3BDE;
L_OVC49_8699_1e09_3BF1:
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects(&bStackY_32);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  cVar8 = '\0';
  cVar6 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  do {
    do {
      uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      if ((int)uStackY_22 < 0) goto L_OVC49_8699_1e09_3CF7;
    } while (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)((int)uStackY_22 * 0x34 + 0x2f) == '\0') {
      cVar8 = '\x01';
    }
    else {
      cVar6 = '\x01';
    }
  } while ((cVar6 == '\0') || (cVar8 == '\0'));
L_OVC49_8699_1e09_3CF7:
  if ((cVar8 == '\0') || (cVar6 == '\0')) {
    cVar42 = '\x01';
  }
  else {
    cVar42 = '\0';
  }
  cVar40 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  while (uStackY_22 = (cte_t *)((int)uStackY_22 - 1), -1 < (int)uStackY_22) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02') {
      ovr_ovc41_removeAgent((uint)uStackY_22);
      AgentsChanged = '\x01';
    }
    else if ((cVar42 != '\0') && ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      cVar40 = '\x01';
      *(undefined1 *)((int)uStackY_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) == '\0' || (cVar6 != '\0')))) &&
         ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) != '\0' || (cVar8 != '\0')))) {
        puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
        ovr_ovc41_advanceAnimFrame((agnt_t *)((int)uStackY_22 * 0x34));
      }
      else {
        puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x21) = 0;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x23) = 10;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 2;
        *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
      }
      AgentsChanged = '\x01';
    }
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  if (cVar40 != '\0') {
    ovr_play_sfxU(0x3b);
  }
  uVar20 = EntityCount - 1;
  for (uVar15 = uVar20; -1 < (int)uVar15; uVar15 = uVar15 - 1) {
    uVar27 = (undefined2)((ulong)Entities >> 0x10);
    uVar20 = (uint)*(byte *)((int)Entities + uVar15 * 0x37 + 0xe);
    if ((uVar20 == 0) &&
       (uVar20 = ovr_ovc23_isCursorAt(*(uint16_t *)((int)Entities + uVar15 * 0x37)),
       (char)uVar20 != '\0')) {
      uVar20 = AgntCount - 1;
      uStackY_22 = (cte_t *)uVar20;
      while ((-1 < (int)uStackY_22 &&
             (uVar20 = (int)uStackY_22 * 0x34, *(uint *)(uVar20 + 0x1b) != uVar15))) {
        uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      }
      if ((int)uStackY_22 < 0) {
        ovr_ovc15_removeEntity(uVar15);
        uVar20 = 0x2410;
        constructionDirty = 1;
      }
    }
  }
  ovr_ovc41_usesDebugVerbose();
  return uVar20;
}


/* 8699:1e09 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Per-frame agent pass: updates each agent's grid cells and AI state, resolves its animation and
   sprite, and draws it (also sets BothFactions and GGameState). */

void __cdecl16far ovc49_drawAgents(void)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  bool bVar5;
  undefined4 uVar6;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  bool bVar7;
  bool bVar8;
  far_t gfx_01;
  far_t gfx_02;
  char cVar9;
  uint uVar10;
  stg_tmp_t *psVar11;
  uint16_t uVar12;
  undefined2 uVar13;
  int iVar14;
  undefined2 uVar15;
  undefined2 *puVar16;
  int iVar17;
  int *piVar18;
  uint16_t *puVar19;
  uint16_t unaff_DI;
  undefined2 uVar20;
  undefined2 uVar21;
  uint unaff_SS;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  undefined1 uVar22;
  uint8_t type;
  undefined1 uVar23;
  brect_t agentRect;
  int iStack_28;
  uint uStack_22;
  byte bStack_1e;
  uint8_t agntIndex;
  byte bStack_1b;
  uint uStack_1a;
  stg_tmp_t *psStack_18;
  uint16_t uStack_16;
  uint8_t factionSeen;
  char cStack_13;
  uint16_t uStack_12;
  uint16_t uStack_10;
  undefined4 uStack_e;
  undefined4 uStack_a;
  char cStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  type = (uint8_t)unaff_SS;
  uVar23 = (undefined1)(unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = type;
  dst.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar23;
  F_SCOPY(far_from_u32((uint32_t)(0x2410842c)),dst);
  AgentsChanged = '\0';
  agentRect.seg = GSavedBlitSeg;
  GGameState = 0x2b;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)audioSaveCut1Seg;
  gfx.ofs = audioSaveCut1Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)audioSaveCut1Seg >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)agentRect.seg;
  dst_00.ofs = 0x8cc;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(agentRect.seg >> 8);
  ovr_blitLoadRleGfx(gfx,dst_00,0xcc);
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)audioSaveCut2Seg;
  gfx_00.ofs = audioSaveCut2Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)audioSaveCut2Seg >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = (char)agentRect.seg;
  dst_01.ofs = 0x618c;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = (char)(agentRect.seg >> 8);
  ovr_blitLoadRleGfx(gfx_00,dst_01,0x8c);
  GGameState = 0x2c;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = type;
  dst_02.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar23;
  ovr_ovc23_textBuildThfres01Lbm(dst_02);
  _fmemset((void *)(ulong)unaff_SS,2,unaff_DI);
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    (&factionSeen)[*(byte *)(uStack_22 * 0x34 + 0x2f)] = 0x1;
  }
  if ((factionSeen == 0x0) || (cStack_13 == '\0')) {
    BothFactions = 0;
  }
  else {
    BothFactions = 1;
  }
  GGameState = 0x2d;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    uStack_a = CONCAT22(*(undefined2 *)(uStack_22 * 0x34 + 0x15),
                        *(undefined2 *)(uStack_22 * 0x34 + 0x13));
    ovc49_fillGridCells(0,(agnt_t *)(uStack_22 * 0x34),(char)(agnt_t *)(uStack_22 * 0x34),0x26);
    ovc49_textLongerParalyzed
              ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),(byte)uStack_22);
    uVar13 = *(undefined2 *)(uStack_22 * 0x34);
    uVar21 = *(undefined2 *)(uStack_22 * 0x34 + 2);
    uVar10 = ovc49_body1((agnt_t *)(uStack_22 * 0x34),0x26);
    bStack_1b = (byte)uVar10;
    uVar20 = (undefined2)((ulong)uStack_a >> 0x10);
    puVar16 = (undefined2 *)((int)uStack_a + (uVar10 & 0xff) * 4);
    uStack_12 = CONCAT22(puVar16[1],*puVar16);
    uVar15 = 0x1726;
    iVar17 = (int)uStack_a + (uVar10 & 0xff) * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                         (char)*(undefined2 *)(iVar17 + 0x5a),*(undefined1 *)(uStack_22 * 0x34 + 6))
    ;
    psStack_18 = (stg_tmp_t *)CONCAT22(uVar15,psVar11);
    if (*(char *)(uStack_22 * 0x34 + 4) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 4) < '\0') {
        *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) - (int)(char)psVar11->cmap[5];
      }
    }
    else {
      *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) + (int)(char)psVar11->cmap[5];
    }
    bVar5 = true;
    iVar17 = (int)uStack_12;
    uVar15 = (undefined2)((ulong)uStack_12 >> 0x10);
    if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 - *(int *)(iVar17 + 0x11);
      }
      else {
        bVar5 = false;
      }
    }
    else {
      piVar1 = (int *)(uStack_22 * 0x34 + 2);
      *piVar1 = *piVar1 + *(int *)(iVar17 + 0x11);
    }
    if (0x14 < *(int *)(uStack_22 * 0x34 + 2)) {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
        if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
          piVar1 = (int *)(uStack_22 * 0x34 + 2);
          *piVar1 = *piVar1 - *(int *)(iVar17 + 0x11);
        }
      }
      else {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 + *(int *)(iVar17 + 0x11);
      }
    }
    if ((((*(int *)(uStack_22 * 0x34) < 0) || (0xd2 < *(int *)(uStack_22 * 0x34))) ||
        (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0' &&
        (uVar10 = ovc49_compute1(*(int *)(uStack_22 * 0x34)), (char)uVar10 != '\0')))) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    if ((bVar7) && (*(int *)(uStack_22 * 0x34 + 2) < 0x15)) {
      bVar8 = true;
    }
    else {
      bVar8 = false;
    }
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar17 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(&columnScreenY[iVar17]) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar17 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(&columnScreenY[iVar17]) + *(int *)(uStack_22 * 0x34 + 2) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(char *)(uStack_22 * 0x34 + 0x10) == '\x05') && (*(char *)(uStack_22 * 0x34 + 0xc) != -1))
    {
      ovr_ovc41_usesXOfs(uStack_22);
    }
    uVar15 = ovc49_agentIsActive((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
    if ((((char)uVar15 == '\0') || (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((-1 < *(int *)(uStack_22 * 0x34) &&
        ((*(int *)(uStack_22 * 0x34) < 0xd3 &&
         ((uint)(*(int *)(uStack_22 * 0x34 + 0x28) - *(int *)(((stg_tmp_t *)psStack_18)->cmap + 9))
          < 0x96)))))) {
      if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') &&
         (uVar10 = ovc49_compute1(*(int *)(uStack_22 * 0x34)), (char)uVar10 != '\0')) {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar21;
        if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
          uVar12 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 4) = (char)uVar12 + -1;
        }
        else {
          *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
        }
        uVar13 = ovc49_agentIsActive((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        if ((char)uVar13 == '\0') {
          uVar12 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar12 + -1;
        }
        else {
          uVar12 = ovr_randBelow(2);
          *(undefined1 *)(uStack_22 * 0x34 + 5) = (char)uVar12;
        }
        if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
          *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
        }
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        bVar5 = false;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        ovc49_body1((agnt_t *)(uStack_22 * 0x34),0x26);
      }
      else if ((bVar7) &&
              (((bVar8 || (*(char *)(uStack_22 * 0x34 + 5) < '\0')) ||
               (uVar10 = ovc49_agentIsActive((agnt_t *)
                                             CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34))),
               (uVar10 & 0xff) != 0)))) {
        iVar17 = ovc49_usesStExit((agnt_t *)(uStack_22 * 0x34),0x26);
        if ((char)iVar17 != '\0') {
          *(undefined2 *)(uStack_22 * 0x34) = uVar13;
          *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar21;
          if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') ||
             (*(char *)(uStack_22 * 0x34 + 4) != '\0')) {
            if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
              *(undefined1 *)(uStack_22 * 0x34 + 4) = 0;
            }
            else {
              *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
            }
          }
          else {
            uVar12 = ovr_randBelow(2);
            *(char *)(uStack_22 * 0x34 + 4) = (char)uVar12 * '\x02' + -1;
          }
          *(undefined1 *)(uStack_22 * 0x34 + 5) = 0;
          *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
          if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) &&
              (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')) ||
             ((*(char *)(uStack_22 * 0x34 + 4) < '\0' && (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')
              ))) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
          }
          bVar5 = false;
          ovc49_body1((agnt_t *)(uStack_22 * 0x34),0x26);
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x25) != '\x02') {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar21;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
          if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
            uVar12 = ovr_randBelow(2);
            *(char *)(uStack_22 * 0x34 + 4) = (char)uVar12 * '\x02' + -1;
          }
          else {
            *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
          }
          uVar12 = ovr_randBelow(3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar12 + -1;
        }
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        bVar5 = false;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        ovc49_body1((agnt_t *)(uStack_22 * 0x34),0x26);
      }
    }
    else {
      *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
    }
    ovc49_fillGridCells((byte)uStack_22 + 1,(agnt_t *)(uStack_22 * 0x34),
                        (char)(agnt_t *)(uStack_22 * 0x34),0x26);
    if ((bVar5) && (uVar13 = ovr_agnt_usesAgntSaved(uStack_22), (char)uVar13 != '\0')) {
      uStack_22 = uStack_22 + -1;
    }
  }
  GGameState = 0x2e;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  for (uStack_22 = 0; (int)uStack_22 < (int)(uint)AgntCount; uStack_22 = uStack_22 + 1) {
    uVar13 = *(undefined2 *)(uStack_22 * 0x34 + 0x15);
    iVar17 = *(int *)(uStack_22 * 0x34 + 0x13);
    uStack_a = CONCAT22(uVar13,iVar17);
    uStack_1a = *(uint *)(uStack_22 * 0x34 + 6);
    bStack_1b = *(byte *)(uStack_22 * 0x34 + 0x12);
    puVar16 = (undefined2 *)(iVar17 + (uint)bStack_1b * 4);
    uStack_12 = CONCAT22(puVar16[1],*puVar16);
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar13 = 0x1726;
    uVar21 = (undefined2)((ulong)uStack_a >> 0x10);
    iVar17 = (int)uStack_a + (uint)bStack_1b * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                         (char)*(undefined2 *)(iVar17 + 0x5a),*(undefined1 *)(uStack_22 * 0x34 + 6))
    ;
    psStack_18 = (stg_tmp_t *)CONCAT22(uVar13,psVar11);
    GGameState = 0x38;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iVar17 = *(int *)(uStack_22 * 0x34) + 0xc;
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar14 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(&columnScreenY[iVar14]) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar14 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      uVar6 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
      iStack_28 = *(int *)(&columnScreenY[iVar14]) + *(int *)(uStack_22 * 0x34 + 2) +
                  (int)*(char *)((int)uVar6 + 0x52) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x26) = iVar17;
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) {
      if (*(char *)(uStack_22 * 0x34 + 0x24) == '\0') {
        GGameState = 0x32;
        gfx_04.seg = uStack_16;
        gfx_04.ofs = (uint16_t)(psStack_18->cmap + 6);
        ovr_blitGfxRect(gfx_04,iVar17,iStack_28,&agentRect,type,(*(uint8_t *)((uint8_t *)&(iStack_28))));
        GGameState = 0x33;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 100) != 0) {
          iVar14 = iStack_28 - *(int *)((int)uStack_12 + 0xd);
          bVar4 = *(byte *)(uStack_22 * 0x34 + 0x23);
          pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
          *pcVar2 = *pcVar2 + -1;
          uVar10 = bVar4 & 3;
          gfx_05.seg = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_05.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_05,iVar17,iVar14,&agentRect,type,SUB21(iVar14,0));
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x01') {
        uVar6 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        if ((*(uint *)((int)uVar6 + 0x40) & 2) == 0) {
          gfx_07.seg = uStack_16;
          gfx_07.ofs = (uint16_t)(psStack_18->cmap + 6);
          ovr_blitGfxRect(gfx_07,iVar17,iStack_28,&agentRect,type,(*(uint8_t *)((uint8_t *)&(iStack_28))));
          iVar14 = iStack_28 - *(int *)((int)uStack_12 + 0xd);
          uVar10 = *(byte *)(uStack_22 * 0x34 + 0x23) & 3;
          gfx_08.seg = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_08.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_08,iVar17,iVar14,&agentRect,type,SUB21(iVar14,0));
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          gfx_06.seg = uStack_16;
          gfx_06.ofs = (uint16_t)(psStack_18->cmap + 6);
          ovr_blitGfxRect(gfx_06,iVar17,iStack_28,&agentRect,type,(*(uint8_t *)((uint8_t *)&(iStack_28))));
          if ((int)(uint)*(byte *)((int)uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x02') {
        if (bStack_1b == 0x12) {
          gfx_09.seg = uStack_16;
          gfx_09.ofs = (uint16_t)(psStack_18->cmap + 6);
          ovr_blitGfxRect(gfx_09,iVar17,iStack_28,&agentRect,type,(*(uint8_t *)((uint8_t *)&(iStack_28))));
          if ((int)(uint)*(byte *)((int)uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_ovc41_paralyzeNearbyAgents(uStack_22);
          }
        }
        else {
          uVar12 = ovr_randBelow(0x100);
          gfx_01.seg = (uint16_t)((ulong)psStack_18 >> 0x10);
          gfx_01.ofs = (uint16_t)(psStack_18->cmap + 6);
          ovr_gfxRlePrepare(gfx_01,iVar17,iStack_28,&agentRect.x,type,'\x10',0x10,
                            CONCAT11((char)(uStack_22 * 0x34 >> 8),
                                     *(undefined1 *)(uStack_22 * 0x34 + 0xf)),1,
                            *(char *)(uStack_22 * 0x34 + 0x23) * '\x19',(char)uVar12);
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_ovc41_paralyzeNearbyAgents(uStack_22);
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
      }
    }
    else {
      gfx_03.seg = uStack_16;
      gfx_03.ofs = (uint16_t)(psStack_18->cmap + 6);
      ovr_gfxRlePrepare(gfx_03,iVar17,iStack_28,&agentRect.x,type,'\x10',0x10,
                        CONCAT11((char)(uStack_22 * 0x34 >> 8),
                                 *(undefined1 *)(uStack_22 * 0x34 + 0xf)),0xff,0,0);
    }
    if (*(char *)(uStack_22 * 0x34 + 0x30) != '\0') {
      ovr_agnt_drawSpriteFrame((byte)uStack_22,&agentRect,(char)&agentRect);
    }
    uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
    if (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 8) == 0) ||
       ((uint)*(byte *)((int)uStack_12 + 0x19) != *(uint *)(uStack_22 * 0x34 + 6))) {
      if (((uint)*(byte *)((int)uStack_12 + 0x19) == *(uint *)(uStack_22 * 0x34 + 6)) &&
         ((*(char *)(uStack_22 * 0x34 + 0x24) == '\0' && (*(char *)(uStack_22 * 0x34 + 0xe) == -1)))
         ) {
        if (*(char *)(uStack_22 * 0x34 + 0xd) == '\0') {
          cVar9 = ovc49_usesFrameIndex2
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                             (byte *)CONCAT13(uVar23,CONCAT12(type,&agntIndex)));
          if (cVar9 == '\0') {
            if ((*(char *)(uStack_22 * 0x34 + 0x12) == '\x03') ||
               (*(char *)(uStack_22 * 0x34 + 0x12) == '\x0f')) {
              uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x33,0,uVar12,0,(char)uVar12);
            }
            animBranchCode = 9;
            ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar9 = ovc49_usesFrameIndex
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                             (byte *)CONCAT13(uVar23,CONCAT12(type,&agntIndex)));
          if ((cVar9 == '\0') ||
             (uVar10 = ovr_ovc27_compute1((agnt_t *)(uStack_22 * 0x34),0x1726,0x26,agntIndex + 0xff)
             , (char)uVar10 == '\0')) {
            animBranchCode = 10;
            ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) ||
                (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05')) {
          cVar9 = ovr_agnt_computeFrameExtents
                            ((agnt_t *)(uStack_22 * 0x34),
                             (uint8_t *)
                             CONCAT13((char)((uint)&agntIndex >> 8),
                                      CONCAT12((char)&agntIndex,0x1726)),0x26);
          if (cVar9 == '\0') {
            animBranchCode = 0xb;
            ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        agntIndex = *(char *)(uStack_22 * 0x34 + 0xc) + 1;
        if (((agntIndex == 0) || (*(char *)((uint)agntIndex * 0x34 + -0x10) != '\0')) ||
           ((*(char *)(uStack_22 * 0x34 + 0xd) != '\x06' &&
            ((0x14 < *(int *)(uStack_22 * 0x34 + 2) ||
             (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))))) {
          animBranchCode = 0xc;
          ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          uVar10 = ovr_ovc27_spellNotice(uStack_22);
          if ((uVar10 & 0xff) == 0) {
            animBranchCode = 0xf;
            ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) &&
                (*(char *)(uStack_22 * 0x34 + 0xe) == -1)) {
          uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)uStack_12 + 0x1d),0,uVar12,0,(char)uVar12);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 0;
          uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
          iVar14 = (int)uStack_12;
          *(char *)(uStack_22 * 0x34 + 10) = *(char *)(iVar14 + 0x15) + (*(uint8_t *)((uint8_t *)&(iStack_28)));
          if (*(char *)(uStack_22 * 0x34 + 0xf) == '\0') {
            *(int *)(uStack_22 * 0x34 + 8) = *(int *)(iVar14 + 0x13) + iVar17;
          }
          else {
            *(int *)(uStack_22 * 0x34 + 8) = iVar17 - *(int *)(iVar14 + 0x13);
          }
          *(undefined1 *)(uStack_22 * 0x34 + 0xb) = *(undefined1 *)(uStack_22 * 0x34 + 0xf);
        }
        else if ((*(char *)(uStack_22 * 0x34 + 0xd) == '\0') &&
                (uVar6 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d),
                (*(uint *)((int)uVar6 + 0x3c) & 8) == 0)) {
          uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)uStack_12 + 0x1d),0,uVar12,0,(char)uVar12);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x03') {
          iVar17 = (uint)agntIndex * 0x34 + -0x34;
          uVar22 = (undefined1)iVar17;
          uVar10 = ovr_agnt_compute12((agnt_t *)(uStack_22 * 0x34),
                                      (agnt_t *)
                                      CONCAT13((char)((uint)iVar17 >> 8),CONCAT12(uVar22,0x1726)),
                                      0x26,uVar22,0x26);
          if (((char)uVar10 != '\0') && ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) {
            uVar6 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x1d);
            if (((*(uint *)((int)uVar6 + 0x14) & 2) == 0) ||
               ((uVar12 = ovr_randBelow(2), (uVar12 & 0xff) != 0 ||
                ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
              ovr_OVC41_6a8f_01e7_entry((agnt_t *)((uint)agntIndex * 0x34 + -0x34),0x26);
              puVar3 = (uint *)((uint)agntIndex * 0x34 + -9);
              *puVar3 = *puVar3 | 0x800;
              uVar12 = ovr_audio_panFromX((agnt_t *)((uint)agntIndex * 0x34 + -0x34),0x26);
              ovr_play_sfxU(0x1b,0,uVar12,0,(char)uVar12);
            }
            else {
              uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
              ovr_play_sfxU(0x1b,0,uVar12,0,(char)uVar12);
              ovr_OVC41_6a8f_01e7_entry((agnt_t *)((uint)agntIndex * 0x34 + -0x34),0x26);
              puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
              *puVar3 = *puVar3 | 0x800;
            }
          }
          animBranchCode = 0xd;
          ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05') {
          uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)uStack_12 + 0x1d),0,uVar12,0,(char)uVar12);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0xf5;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 1;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x06') {
          uVar12 = ovr_audio_panFromX((agnt_t *)(uStack_22 * 0x34),0x26);
          ovr_play_sfxU(*(byte *)((int)uStack_12 + 0x1d),0,uVar12,0,(char)uVar12);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else {
          animBranchCode = 0xe;
          ovr_agnt_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
        }
      }
    }
    else {
      ovr_ovc41_resolveSpecialAttack
                ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                 (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
    }
    GGameState = 0x39;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    piVar1 = (int *)(uStack_22 * 0x34 + 6);
    *piVar1 = *piVar1 + 1;
    if (*(char *)(uStack_22 * 0x34 + 0xe) != -1) {
      if (*(char *)(uStack_22 * 0x34 + 0xc) == -1) {
        ovr_agnt_usesAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
        animBranchCode = 7;
      }
      else if ((*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') ||
              (*(char *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
        bVar4 = *(byte *)(uStack_22 * 0x34 + 0xe);
        uStack_1a = (uint)bVar4;
        uVar13 = (undefined2)((ulong)uStack_a >> 0x10);
        uStack_e = uStack_a;
        if (*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') {
          bStack_1e = 6;
        }
        else {
          bStack_1e = *(byte *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16);
        }
        piVar18 = (int *)((int)uStack_a + (uint)bStack_1e * 4);
        if (*piVar18 == 0 && piVar18[1] == 0) {
          uStack_e = CONCAT22(SprProjectiles.seg,SprProjectiles.ofs);
        }
        uVar13 = (undefined2)((ulong)uStack_e >> 0x10);
        iVar17 = (int)uStack_e;
        puVar19 = (uint16_t *)(iVar17 + (uint)bStack_1e * 4);
        uVar12 = *puVar19;
        uStack_12 = CONCAT22(puVar19[1],uVar12);
        piVar18 = (int *)(iVar17 + (uint)bStack_1e * 4);
        if (*piVar18 == 0 && piVar18[1] == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0xf);
        }
        iVar17 = iVar17 + (uint)bStack_1e * 4;
        psVar11 = ovr_stash_usesStExit
                            ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                             (char)*(undefined2 *)(iVar17 + 0x5a),bVar4);
        psStack_18 = (stg_tmp_t *)CONCAT22(uVar12,psVar11);
        GGameState = 0x30;
        bVar5 = *(bool *)(uStack_22 * 0x34 + 10);
        gfx_02.seg = uVar12;
        gfx_02.ofs = (uint16_t)(psVar11->cmap + 6);
        ovr_blitGfxRect(gfx_02,*(int16_t *)(uStack_22 * 0x34 + 8),(uint)bVar5,&agentRect,type,bVar5)
        ;
        GGameState = 0x31;
        uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
        iVar17 = (int)uStack_12;
        if ((*(byte *)(iVar17 + 0x1c) & 2) == 0) {
          uVar21 = (undefined2)((ulong)psStack_18 >> 0x10);
          if (*(char *)(uStack_22 * 0x34 + 0xb) == '\0') {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 + (int)(char)((stg_tmp_t *)psStack_18)->cmap[5];
          }
          else {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 - (int)(char)((stg_tmp_t *)psStack_18)->cmap[5];
          }
          uStack_1a = uStack_1a + 1;
          if (*(byte *)(iVar17 + 0x19) + 1 == uStack_1a) {
            ovr_ovc41_specialAttack
                      ((agnt_t *)(uStack_22 * 0x34),0x1726,0x26,
                       *(undefined1 *)(uStack_22 * 0x34 + 0xc));
          }
          if ((int)uStack_1a < (int)(uint)*(byte *)((int)uStack_12 + 0x1b)) {
            *(undefined1 *)(uStack_22 * 0x34 + 0xe) = (undefined1)uStack_1a;
          }
          else {
            animBranchCode = 8;
            ovr_agnt_usesAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
          }
        }
        else {
          ovr_agnt_usesStExit((agnt_t *)(uStack_22 * 0x34),
                              (anm_t *)CONCAT22(iVar17,(anm_t *)((int)&AgntAnms[0x75].halfWidth + 1)
                                               ),
                              (stg_tmp_t *)
                              CONCAT13((char)((ulong)psStack_18 >> 8),
                                       CONCAT12((char)psStack_18,uVar13)),0x26,
                              (char)((ulong)uStack_12 >> 0x10),(char)psStack_18,
                              (char)((ulong)psStack_18 >> 0x10));
        }
      }
      else {
        ovr_ovc27_usesBlitGfxRect(uStack_22,&agentRect,(char)&agentRect);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects(&agentRect);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  cStack_3 = '\0';
  cStack_4 = '\0';
  uStack_22 = (uint)AgntCount;
  do {
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) goto L_OVC49_8699_1e09_3CF7;
    } while (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)(uStack_22 * 0x34 + 0x2f) == '\0') {
      cStack_3 = '\x01';
    }
    else {
      cStack_4 = '\x01';
    }
  } while ((cStack_4 == '\0') || (cStack_3 == '\0'));
L_OVC49_8699_1e09_3CF7:
  if ((cStack_3 == '\0') || (cStack_4 == '\0')) {
    cStack_5 = '\x01';
  }
  else {
    cStack_5 = '\0';
  }
  cStack_6 = '\0';
  uStack_22 = (uint)AgntCount;
  while (uStack_22 = uStack_22 - 1, -1 < (int)uStack_22) {
    if (*(char *)(uStack_22 * 0x34 + 0x25) == '\x02') {
      ovr_ovc41_removeAgent(uStack_22,0,0);
      AgentsChanged = '\x01';
    }
    else if ((cStack_5 != '\0') && ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      cStack_6 = '\x01';
      *(undefined1 *)(uStack_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) == '\0' || (cStack_4 != '\0')))) &&
         ((*(char *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d) != '\0' || (cStack_3 != '\0')))) {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        ovr_ovc41_advanceAnimFrame((agnt_t *)(uStack_22 * 0x34),0x26);
      }
      else {
        puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)(uStack_22 * 0x34 + 0x21) = 0;
        *(undefined1 *)(uStack_22 * 0x34 + 0x23) = 10;
        *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 2;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
      }
      AgentsChanged = '\x01';
    }
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  uVar10 = EntityCount;
  if (cStack_6 != '\0') {
    ovr_play_sfxU(0x3b,0,0x80,0,0x80);
    uVar10 = EntityCount;
  }
  do {
    do {
      uVar10 = uVar10 - 1;
      if ((int)uVar10 < 0) {
        ovr_ovc41_usesDebugVerbose();
        return;
      }
      uVar13 = (undefined2)((ulong)Entities >> 0x10);
      iVar17 = (int)Entities;
    } while ((((entity_t *)iVar17)[uVar10].base.animFrame != '\0') ||
            (iVar14 = ((entity_t *)iVar17)[uVar10].base.y,
            uVar13 = ovr_ovc23_isCursorAt(*(uint16_t *)((entity_t *)iVar17 + uVar10),iVar14,(char)iVar14)
            , (char)uVar13 == '\0'));
    uStack_22 = (uint)AgntCount;
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) break;
    } while (*(uint *)(uStack_22 * 0x34 + 0x1b) != uVar10);
    if ((int)uStack_22 < 0) {
      ovr_ovc15_removeEntity(uVar10);
      constructionDirty = 1;
    }
  } while( true );
}


