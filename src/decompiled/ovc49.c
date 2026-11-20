/*
 * ovc49.c - recovered from STRONG.EXE
 * memory block: OVC49
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
  undefined2 in_stack_0000000a;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar8 = (undefined2)((ulong)agnt >> 0x10);
  paVar6 = (agnt_t *)agnt;
  if (((agntG_t *)paVar6->gdata)->extents[1][1] == 0) {
    *_out = 0;
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
              *_out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa);
              bVar4 = ovr_agnt_compute4((char *)out);
              if (bVar4) {
                return *_out;
              }
            }
            if (((*(char *)(iVar5 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *_out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0);
              return *_out;
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *_out = 0;
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
  undefined2 in_stack_0000000a;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar8 = (undefined2)((ulong)agnt >> 0x10);
  paVar6 = (agnt_t *)agnt;
  if (((agntG_t *)paVar6->gdata)->extents[0][1] == 0) {
    *_out = 0;
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
              *_out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x8fa);
              bVar4 = ovr_agnt_compute4((char *)out);
              if (bVar4) {
                return *_out;
              }
            }
            if (((*(char *)(iVar5 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *_out = *(byte *)(iVar5 * 0x69 + iStack_a + 0x4e0);
              return *_out;
            }
          }
          cStack_e = cStack_e + '\x02';
        }
      }
    }
    *_out = 0;
  }
  return 0;
}



/* 8699:06dc */

/* [R4] calls ovr_stExit */

int __cdecl16far ovc49_usesStExit(agnt_t *agnt)

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

uint __cdecl16far ovc49_compute1(int x)

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
  uint uVar6;
  undefined2 uVar7;
  int iVar8;
  uint16_t uVar9;
  uint16_t in_DX;
  agnt_t *paVar10;
  undefined2 uVar11;
  char *unaff_SS;
  undefined1 uVar12;
  undefined1 uVar13;
  uint8_t text;
  uint8_t msg;
  uint8_t dirY;
  uint8_t dx;
  uint8_t agntIndex;
  uint16_t distance;
  
  uVar11 = (undefined2)((ulong)agnt >> 0x10);
  paVar10 = (agnt_t *)agnt;
  if ((paVar10->combatState == 0x0) && (paVar10->animFrame == 0xff)) {
    if (((paVar10->flags & 0x200) != 0) && (uVar4 = ovr_randBelow(0xc), (uVar4 & 0xff) == 0)) {
      paVar10->flags = paVar10->flags & 0xfdff;
      pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar5));
      pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s is no longer paralyzed.");
      ovr_uiNotify(pcVar5,in_DX);
      ovr_ovc41_advanceAnimFrame(agnt);
      ovr_attact_usesLDIV_at_2();
    }
    if (((paVar10->flags & 0x100) != 0) &&
       ((uVar4 = ovr_randBelow(0x40), (uVar4 & 0xff) == 0 ||
        (((((agntG_t *)paVar10->gdata)->flags3 & 0x2000) != 0 &&
         (uVar4 = ovr_randBelow(0x20), (uVar4 & 0xff) == 0)))))) {
      paVar10->flags = paVar10->flags & 0xfeff;
      pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
      ovr_ovc15_usesStshRealloc((char *)CONCAT22(in_DX,pcVar5));
      pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,(char *)"%s breaks free of the web.");
      ovr_uiNotify(pcVar5,in_DX);
      *(undefined1 *)&paVar10->state = 0;
      ovr_agnt_compute13(agnt);
      ovr_attact_usesLDIV_at_2();
    }
    if ((paVar10->flags & 0xbc0) == 0) {
      if (((*(char *)((int)&paVar10->targetX + 1) < '\0') || ((int)paVar10->y < 0x15)) ||
         (uVar6 = ovc49_agentIsActive(agnt), (uVar6 & 0xff) != 0)) {
        uVar7 = ovc49_agentIsActive(agnt);
        if ((char)uVar7 == '\0') {
          uVar12 = SUB21(unaff_SS,0);
          uVar13 = (undefined1)((uint)unaff_SS >> 8);
          if ((paVar10->animVariant == 0x0) ||
             (cVar2 = ovr_agnt_usesAnimFrame2(agnt), cVar2 == '\0')) {
            if ((((paVar10->animVariant == 0x0) &&
                 (cVar2 = ovr_agnt_usesAnimFrame2(agnt), cVar2 != '\0')) &&
                (paVar10->moveState == 0x0)) && (paVar10->animFrame == 0xff)) {
              if ((((((agntG_t *)paVar10->gdata)->flags & 1) == 0) ||
                  (iVar8 = ovr_ovc27_rollAgainstStat(agnt,2), (char)iVar8 == '\0')) ||
                 (uVar7 = ovr_agnt_acquireTarget(agnt,(char *)&agntIndex), (char)uVar7 == '\0')) {
                if ((((((agntG_t *)paVar10->gdata)->flags & 1) == 0) ||
                    ((((entity_t *)paVar10->entity)->base).level < 2)) ||
                   ((iVar8 = ovr_ovc27_rollAgainstStat(agnt,2), (char)iVar8 == '\0' ||
                    (cVar2 = ovr_agnt_usesStrengthMax(agnt,&agntIndex), cVar2 == '\0')))) {
                  if (((((((agntG_t *)paVar10->gdata)->flags & 0x400) == 0) ||
                       (0x14 < (int)paVar10->y)) ||
                      (cVar2 = ovc49_usesFrameIndex(agnt,&agntIndex), cVar2 == '\0')) ||
                     ((0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32) ||
                      (uVar6 = ovr_ovc27_compute2(agnt,agntIndex - 1), (char)uVar6 == '\0')))) {
                    if (((int)paVar10->y < 0x15) &&
                       (iVar8 = ovr_ovc27_rollAgainstStat(agnt,3), (char)iVar8 != '\0')) {
                      cVar2 = ovc49_usesFrameIndex2(agnt,&agntIndex);
                      if ((cVar2 == '\0') || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                        if ((((((((agntG_t *)paVar10->gdata)->flags2 & 1) == 0) ||
                              (cVar2 = ovr_agnt_computeFrameExtents(agnt,&agntIndex), cVar2 == '\0')
                              ) || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) ||
                            (((((agntG_t *)paVar10->gdata)->flags3 & 0x400) != 0 &&
                             (uVar4 = ovr_randBelow(0x14), (uVar4 & 0xff) != 0)))) ||
                           (cVar2 = ovr_agnt_compute16_8
                                              (agnt,(agnt_t *)
                                                    CONCAT13(0x17,CONCAT12(0x26,(uint)agntIndex *
                                                                                0x34 + -0x34))),
                           cVar2 == '\0')) {
                          if (((((((agntG_t *)paVar10->gdata)->flags2 & 0x200) == 0) ||
                               (cVar2 = ovr_agnt_computeFrameExtents(agnt,&agntIndex), cVar2 == '\0'
                               )) || (((((agntG_t *)paVar10->gdata)->flags3 & 0x400) != 0 &&
                                      (uVar4 = ovr_randBelow(0x14), (uVar4 & 0xff) != 0)))) ||
                             (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                            if ((((((agntG_t *)paVar10->gdata)->flags3 & 1) != 0) &&
                                (cVar2 = ovr_agnt_computeFrameExtents(agnt,&agntIndex),
                                cVar2 != '\0')) && (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)
                               ) {
                              paVar10->health = 0x2;
                              paVar10->targetY = 0;
                              paVar10->target = agntIndex + 0xff;
                              paVar10->gindex = 0x5;
                            }
                          }
                          else {
                            paVar10->health = 0x2;
                            paVar10->targetY = 0;
                            paVar10->target = agntIndex + 0xff;
                            paVar10->gindex = 0x4;
                          }
                        }
                        else {
                          paVar10->health = 0x2;
                          paVar10->targetY = 0;
                          paVar10->target = agntIndex + 0xff;
                          paVar10->gindex = 0x2;
                        }
                      }
                      else {
                        paVar10->health = 0x2;
                        paVar10->targetY = 0;
                        paVar10->target = agntIndex + 0xff;
                        paVar10->gindex = 0x0;
                      }
                    }
                    else if ((((int)paVar10->y < 0x15) &&
                             (uVar4 = ovr_randBelow(0x20), (uVar4 & 0xff) == 0)) &&
                            (((((agntG_t *)paVar10->gdata)->flags & 0x4000) != 0 &&
                             ((paVar10->health != 0x4 &&
                              (*(char *)((int)&(((entity_t *)paVar10->entity)->base).entity + 1) !=
                               '\0')))))) {
                      paVar10->health = 0x4;
                      paVar10->targetY = 0;
                      uVar4 = ovr_audio_panFromX(agnt);
                      ovr_play_sfxU(0x32,0,uVar4);
                    }
                    else if (((((int)paVar10->y < 0x15) &&
                              (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) &&
                             ((((agntG_t *)paVar10->gdata)->flags2 & 0x40) != 0)) &&
                            (((paVar10->health != 0x5 &&
                              (cVar2 = ovc49_usesFrameIndex(agnt,&agntIndex), cVar2 != '\0')) &&
                             (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                             (*(uint *)((int)uVar1 + 0x3e) & 0x80) != 0)))) {
                      uVar4 = ovr_audio_panFromX((agnt_t *)
                                                 CONCAT13(0x17,CONCAT12(0x26,(uint)param * 0x34)));
                      ovr_play_sfxU(0x1e,0,uVar4);
                      paVar10->target = agntIndex + 0xff;
                      paVar10->health = 0x5;
                      paVar10->targetY = 0;
                    }
                    else if ((((int)paVar10->y < 0x15) &&
                             ((((agntG_t *)paVar10->gdata)->flags2 & 0x100) != 0)) &&
                            ((paVar10->health != 0x6 &&
                             ((((cVar2 = ovc49_usesFrameIndex(agnt,&agntIndex), cVar2 != '\0' &&
                                (uVar6 = ovr_agnt_compute12(agnt,(agnt_t *)
                                                                 CONCAT13(0x17,CONCAT12(0x26,(uint)
                                                  agntIndex * 0x34 + -0x34))), (char)uVar6 != '\0'))
                               && ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) &&
                              (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                              (*(uint *)((int)uVar1 + 0x3c) & 4) != 0)))))) {
                      uVar4 = ovr_audio_panFromX((agnt_t *)
                                                 CONCAT13(0x17,CONCAT12(0x26,(uint)param * 0x34)));
                      ovr_play_sfxU(0x1f,0,uVar4);
                      paVar10->target = agntIndex + 0xff;
                      paVar10->health = 0x6;
                      paVar10->targetY = 0;
                      paVar10->gindex = 0x3;
                    }
                    else if ((((((agntG_t *)paVar10->gdata)->flags3 & 0x200) == 0) ||
                             (uVar4 = (uint16_t)paVar10->strengthMax, uVar4 < paVar10->strength + 3)
                             ) || (uVar9 = ovr_randBelow(0x40), (uVar9 & 0xff) != 0)) {
                      if (((((char)paVar10->targetX == '\0') &&
                           (*(char *)((int)&paVar10->targetX + 1) == '\0')) ||
                          (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) &&
                         (paVar10->health != 0x4)) {
                        uVar4 = ovr_randBelow(0xc);
                        if ((uVar4 & 0xff) == 0) {
                          if (((char)paVar10->targetX == '\0') &&
                             (*(char *)((int)&paVar10->targetX + 1) == '\0')) {
                            uVar4 = ovr_randBelow(2);
                            *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
                            uVar4 = ovr_randBelow(3);
                            *(char *)((int)&paVar10->targetX + 1) = (char)uVar4 + -1;
                          }
                          else {
                            *(undefined1 *)&paVar10->targetX = 0;
                            *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
                          }
                        }
                        else {
                          bVar3 = ovr_agnt_usesAgntCount2
                                            (agnt,(uint16_t *)CONCAT22(unaff_SS,&dx),
                                             (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&dirY)),
                                             (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&distance))
                                            );
                          if (bVar3) {
                            *(uint8_t *)((int)&paVar10->targetX + 1) = dirY;
                            if ((distance < 0x6e) &&
                               ((((agntG_t *)paVar10->gdata)->flags3 & 0x10) != 0)) {
                              if (distance < 0x30) {
                                if ((paVar10->screenX < 0x14) || (0xbe < paVar10->screenX)) {
                                  uVar4 = ovr_randBelow(2);
                                  *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
                                  uVar4 = ovr_randBelow(3);
                                  *(char *)((int)&paVar10->targetX + 1) = (char)uVar4 + -1;
                                }
                                else if (_dx == 0) {
                                  uVar4 = ovr_randBelow(2);
                                  *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
                                }
                                else {
                                  *(uint8_t *)&paVar10->targetX = -dx;
                                }
                              }
                              else {
                                if ((int)_dx < 0) {
                                  paVar10->level = 0x1;
                                }
                                else {
                                  paVar10->level = 0x0;
                                }
                                *(undefined1 *)&paVar10->targetX = 0;
                                *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
                              }
                            }
                            else if (distance < 6) {
                              if ((int)_dx < 0) {
                                paVar10->level = 0x1;
                              }
                              else {
                                paVar10->level = 0x0;
                              }
                              *(undefined1 *)&paVar10->targetX = 0;
                              *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
                            }
                            else if (_dx == 0) {
                              uVar4 = ovr_randBelow(2);
                              *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
                            }
                            else {
                              *(uint8_t *)&paVar10->targetX = dx;
                            }
                          }
                          else {
                            uVar4 = ovr_randBelow(8);
                            if ((uVar4 & 0xff) == 0) {
                              if ((char)paVar10->targetX == '\0') {
                                uVar4 = ovr_randBelow(2);
                                *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
                              }
                              else {
                                *(undefined1 *)&paVar10->targetX = 0;
                              }
                            }
                            *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
                          }
                        }
                        if ((((char)paVar10->targetX < '\x01') || (paVar10->level == 0x0)) &&
                           ((-1 < (char)paVar10->targetX || (paVar10->level != 0x0)))) {
                          paVar10->health = 0x0;
                        }
                        else {
                          paVar10->health = 0x1;
                        }
                      }
                    }
                    else {
                      paVar10->strength = paVar10->strength + 0x3;
                      uVar9 = ovr_audio_panFromX(agnt);
                      ovr_play_sfxU(0x4a,0,uVar9);
                      pcVar5 = ovr_agnt_statusText(agnt,(char *)&text);
                      ovr_ovc15_usesStshRealloc
                                ((char *)CONCAT13((char)(uVar4 >> 8),CONCAT12((char)uVar4,pcVar5)));
                      pcVar5 = ovr_stsprintf((char *)&msg,unaff_SS,
                                             (char *)
                                             "%s regenerates 3 hitpoints to a total of %d hitpoints."
                                            );
                      ovr_uiNotify(pcVar5,uVar4);
                    }
                  }
                  else {
                    paVar10->health = 0x2;
                    paVar10->targetY = 0;
                    paVar10->target = agntIndex + 0xff;
                    paVar10->gindex = 0x1;
                  }
                }
                else {
                  paVar10->health = 0x3;
                  paVar10->targetY = 0;
                  paVar10->target = agntIndex + 0xff;
                  paVar10->flags = paVar10->flags | 0x18;
                  paVar10->gindex = 0x0;
                }
              }
              else {
                paVar10->health = 0x3;
                paVar10->targetY = 0;
                paVar10->target = agntIndex + 0xff;
                paVar10->gindex = 0x6;
              }
            }
          }
          else if (((((((agntG_t *)paVar10->gdata)->flags & 0x400) == 0) ||
                    ((0x14 < (int)paVar10->y ||
                     (cVar2 = ovc49_usesFrameIndex(agnt,&agntIndex), cVar2 == '\0')))) ||
                   (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) ||
                  (uVar6 = ovr_ovc27_compute2(agnt,agntIndex - 1), (char)uVar6 == '\0')) {
            if (((((int)paVar10->y < 0x15) &&
                 (iVar8 = ovr_ovc27_rollAgainstStat(agnt,3), (char)iVar8 != '\0')) &&
                (cVar2 = ovc49_usesFrameIndex2(agnt,&agntIndex), cVar2 != '\0')) &&
               (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)) {
              paVar10->health = 0x2;
              paVar10->targetY = 0;
              paVar10->target = agntIndex + 0xff;
              paVar10->gindex = 0x0;
            }
            else if ((((((agntG_t *)paVar10->gdata)->flags2 & 0x200) == 0) ||
                     (0x14 < (int)paVar10->y)) ||
                    ((cVar2 = ovr_agnt_computeFrameExtents(agnt,&agntIndex), cVar2 == '\0' ||
                     (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
              if ((((((agntG_t *)paVar10->gdata)->flags3 & 1) == 0) || (0x14 < (int)paVar10->y)) ||
                 ((cVar2 = ovr_agnt_computeFrameExtents(agnt,&agntIndex), cVar2 == '\0' ||
                  (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
                if (((('\0' < (char)paVar10->targetX) && (0xaa < (int)agnt->x)) ||
                    (((char)paVar10->targetX < '\0' && ((int)agnt->x < 0x34)))) &&
                   (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)) {
                  bVar3 = ovr_agnt_usesAgntCount2
                                    (agnt,(uint16_t *)CONCAT22(unaff_SS,&dx),
                                     (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&dirY)),
                                     (uint16_t *)CONCAT13(uVar13,CONCAT12(uVar12,&distance)));
                  if (bVar3) {
                    *(uint8_t *)((int)&paVar10->targetX + 1) = dirY;
                  }
                  else {
                    *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
                  }
                  *(char *)&paVar10->targetX = -(char)paVar10->targetX;
                  *(undefined1 *)((uint)param * 0x34 + 0x10) = 1;
                  paVar10->targetY = 0;
                }
              }
              else {
                paVar10->health = 0x2;
                paVar10->targetY = 0;
                paVar10->target = agntIndex + 0xff;
                paVar10->gindex = 0x5;
              }
            }
            else {
              paVar10->health = 0x2;
              paVar10->targetY = 0;
              paVar10->target = agntIndex + 0xff;
              paVar10->gindex = 0x4;
            }
          }
          else {
            paVar10->health = 0x2;
            paVar10->targetY = 0;
            paVar10->target = agntIndex + 0xff;
            paVar10->gindex = 0x1;
          }
        }
        else if ((paVar10->moveState != 0x2) &&
                ((((*(char *)((int)&paVar10->targetX + 1) == '\0' &&
                   ((char)paVar10->targetX == '\0')) &&
                  (uVar4 = ovr_randBelow(4), (uVar4 & 0xff) == 0)) ||
                 (((*(char *)((int)&paVar10->targetX + 1) < '\0' || (paVar10->moveState != 0x1)) ||
                  (uVar4 = ovr_randBelow(8), (uVar4 & 0xff) == 0)))))) {
          paVar10->moveState = 0x1;
          uVar4 = ovr_randBelow(2);
          *(undefined1 *)((int)&paVar10->targetX + 1) = (char)uVar4;
          uVar4 = ovr_randBelow(2);
          *(char *)&paVar10->targetX = (char)uVar4 * '\x02' + -1;
          if ((int)agnt->x < 0x2a) {
            *(undefined1 *)&paVar10->targetX = 0xff;
          }
          else if ((int)agnt->x < 0xb5) {
            *(undefined1 *)((int)&paVar10->targetX + 1) = 1;
          }
          else {
            *(undefined1 *)&paVar10->targetX = 1;
          }
        }
      }
      else {
        *(undefined1 *)((int)&paVar10->targetX + 1) = 0xff;
        if ((char)paVar10->targetX == '\0') {
          uVar4 = ovr_randBelow(3);
          *(char *)&paVar10->targetX = (char)uVar4 + -1;
        }
      }
    }
    else {
      *(undefined1 *)&paVar10->targetX = 0;
      *(undefined1 *)((int)&paVar10->targetX + 1) = 0;
      paVar10->health = 0x0;
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

void * __cdecl16far ovc49_fillGridCells(byte count,agnt_t *agnt)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  undefined2 in_stack_00000008;
  
  uVar1 = *(undefined2 *)((int)&agnt->frames + 2);
  piVar5 = (int *)(*(int *)&agnt->frames + (uint)agnt->frameIndex * 4);
  iVar2 = (int)agnt->y >> 1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (7 < iVar2) {
    iVar2 = 7;
  }
  iVar3 = (int)(agnt->x - *(int *)(*piVar5 + 0x17)) >> 1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (0x68 < iVar3) {
    iVar3 = 0x68;
  }
  if (agnt->animVariant == 0x0) {
    _fmemset((void *)(iVar2 * 0x69 + iVar3 + 0x8fa),0x1726,(uint)count);
    pvVar4 = _fmemset((void *)(iVar2 * 0x69 + iVar3 + 0x963),0x1726,(uint)count);
  }
  else {
    _fmemset((void *)(iVar2 * 0x69 + iVar3 + 0x4e0),0x1726,(uint)count);
    _fmemset((void *)(iVar2 * 0x69 + iVar3 + 0x549),0x1726,(uint)count);
    pvVar4 = _fmemset((void *)(iVar2 * 0x69 + iVar3 + 0x5b2),0x1726,(uint)count);
  }
  return pvVar4;
}



/* 8699:18c4 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00088b74) overlaps instruction at (ram,0x00088b73)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* [R7] no exported body */

uint __cdecl16far ovc49_body1(agnt_t *agnt)

{
  char *pcVar1;
  int *piVar2;
  uint *puVar3;
  long lVar4;
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
  far_t src;
  far_t src_00;
  far_t src_01;
  far_t src_02;
  far_t src_03;
  far_t src_04;
  far_t src_05;
  far_t src_06;
  far_t src_07;
  far_t src_08;
  far_t src_09;
  far_t src_10;
  far_t src_11;
  far_t src_12;
  far_t src_13;
  far_t src_14;
  far_t src_15;
  far_t src_16;
  far_t src_17;
  far_t src_18;
  far_t src_19;
  far_t src_20;
  far_t src_21;
  far_t src_22;
  far_t src_23;
  far_t src_24;
  far_t src_25;
  far_t src_26;
  far_t src_27;
  far_t src_28;
  far_t src_29;
  far_t src_30;
  far_t src_31;
  far_t src_32;
  far_t src_33;
  far_t src_34;
  far_t src_35;
  far_t src_36;
  far_t src_37;
  far_t src_38;
  far_t src_39;
  far_t src_40;
  far_t src_41;
  far_t src_42;
  far_t src_43;
  far_t src_44;
  far_t src_45;
  far_t src_46;
  far_t src_47;
  far_t src_48;
  far_t src_49;
  far_t src_50;
  far_t src_51;
  far_t src_52;
  far_t src_53;
  far_t src_54;
  far_t src_55;
  far_t src_56;
  far_t src_57;
  far_t src_58;
  far_t src_59;
  far_t src_60;
  far_t src_61;
  far_t src_62;
  far_t src_63;
  far_t src_64;
  far_t src_65;
  far_t src_66;
  far_t src_67;
  far_t src_68;
  far_t src_69;
  far_t src_70;
  far_t src_71;
  far_t src_72;
  far_t src_73;
  far_t gfx_06;
  far_t gfx_07;
  far_t hint;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t hndl;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  byte bVar8;
  undefined2 *puVar9;
  cte_t *pcVar10;
  far_t *pfVar11;
  undefined1 extraout_AH;
  int iVar12;
  uint uVar13;
  uint16_t uVar14;
  stg_tmp_t *psVar15;
  undefined1 uVar18;
  uint16_t uVar16;
  uint uVar17;
  uint8_t *puVar19;
  uint8_t *puVar20;
  uint8_t *puVar21;
  agnt_t *paVar22;
  int iVar23;
  int *piVar24;
  uint *puVar25;
  entity_t *peVar26;
  char *count;
  int unaff_SI;
  undefined2 uVar27;
  undefined2 uVar28;
  char *unaff_SS;
  byte in_AF;
  char *pcStack0008;
  int iStack000a;
  char in_stack_00000010;
  undefined2 auStackY_2f2 [20];
  char acStackY_2ca [664];
  brect_t bStackY_32;
  int iStackY_28;
  undefined1 auStackY_26 [2];
  undefined2 uStackY_24;
  undefined2 uStackY_22;
  long in_stack_0000ffe0;
  undefined4 uVar29;
  far_t gfx_08;
  far_t gfx_09;
  byte bVar30;
  uint16_t in_stack_0000ffe4;
  stg_tmp_t *in_stack_0000ffe8;
  uint8_t uVar31;
  undefined1 uVar32;
  byte bVar33;
  brect_t *pbVar34;
  undefined1 uVar35;
  char *pcVar36;
  char cVar37;
  uint uVar38;
  undefined1 uVar39;
  stg_tmp_t *in_stack_0000fff6;
  uint8_t *puStack_8;
  char cVar40;
  char cVar41;
  undefined1 uVar42;
  uint in_stack_0000fffc;
  byte bVar43;
  
  uVar27 = (undefined2)((ulong)agnt >> 0x10);
  paVar22 = (agnt_t *)agnt;
  uVar28 = *(undefined2 *)((int)&paVar22->frames + 2);
  puStack_8 = *(uint8_t **)&paVar22->frames;
  uVar35 = (undefined1)uVar28;
  uVar39 = (undefined1)((uint)uVar28 >> 8);
  uVar7 = 0x99;
  uVar32 = 0x86;
  uVar18 = 0x78;
  uVar31 = 0x82;
  iVar12 = ovr_agnt_clampX(agnt->x);
  uVar28 = (undefined2)((ulong)in_stack_0000ffe0 >> 0x10);
  iVar12 = *(int *)(iVar12 * 2 + 0x1a6);
  uVar42 = (undefined1)in_stack_0000fffc;
  if (paVar22->combatState != 0x1) {
    if (paVar22->combatState == 0x2) {
      uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
      if (*(int *)(puStack_8 + 0xa0) == 0 && *(int *)(puStack_8 + 0xa2) == 0) {
        if (paVar22->animVariant == 0x0) {
          in_stack_0000fffc = in_stack_0000fffc & 0xff;
        }
        else {
          in_stack_0000fffc = CONCAT11(4,uVar42);
        }
      }
      else {
        in_stack_0000fffc = CONCAT11(0x12,uVar42);
      }
    }
    else {
      if ((char)paVar22->targetX < '\x01') {
        if ((char)paVar22->targetX < '\0') {
          if (*(char *)((int)&paVar22->targetX + 1) < '\x01') {
            if (*(char *)((int)&paVar22->targetX + 1) < '\0') {
              in_stack_0000fffc = 0x201;
            }
            else if (iVar12 < 8) {
              if (iVar12 < -7) {
                in_stack_0000fffc = 0x201;
              }
              else {
                in_stack_0000fffc = 1;
              }
            }
            else {
              in_stack_0000fffc = 0x101;
            }
          }
          else {
            in_stack_0000fffc = 0x101;
          }
        }
        else {
          uVar31 = paVar22->level;
          in_stack_0000fffc = CONCAT11((char)(in_stack_0000fffc >> 8),uVar31);
          if (*(char *)((int)&paVar22->targetX + 1) < '\x01') {
            if (*(char *)((int)&paVar22->targetX + 1) < '\0') {
              in_stack_0000fffc = CONCAT11(2,uVar31);
            }
            else if ((paVar22->flags & 0x100) == 0) {
              in_stack_0000fffc = CONCAT11(1,uVar31);
            }
            else {
              uVar14 = ovr_randBelow(3);
              uVar13 = uVar14 & 0xff;
              if (uVar13 == 0) {
                in_stack_0000fffc = in_stack_0000fffc & 0xff;
              }
              else if (uVar13 == 1) {
                in_stack_0000fffc = CONCAT11(2,(char)in_stack_0000fffc);
              }
              else if (uVar13 == 2) {
                in_stack_0000fffc = CONCAT11(1,(char)in_stack_0000fffc);
              }
            }
          }
          else {
            in_stack_0000fffc = CONCAT11(1,uVar31);
          }
        }
      }
      else if (*(char *)((int)&paVar22->targetX + 1) < '\x01') {
        if (*(char *)((int)&paVar22->targetX + 1) < '\0') {
          in_stack_0000fffc = 0x200;
        }
        else if (iVar12 < 8) {
          if (iVar12 < -7) {
            in_stack_0000fffc = 0x100;
          }
          else {
            in_stack_0000fffc = 0;
          }
        }
        else {
          in_stack_0000fffc = 0x200;
        }
      }
      else {
        in_stack_0000fffc = 0x100;
      }
      uVar18 = (undefined1)in_stack_0000fffc;
      if (paVar22->animVariant == 0x0) {
        if (paVar22->health == 0x2) {
          if ((paVar22->gindex == 0x1) &&
             (uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10),
             *(int *)(puStack_8 + 0x74) != 0 || *(int *)(puStack_8 + 0x76) != 0)) {
            in_stack_0000fffc = CONCAT11(7,uVar18);
          }
          else if ((paVar22->gindex == 0x2) &&
                  (uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10),
                  *(int *)(puStack_8 + 0xa8) != 0 || *(int *)(puStack_8 + 0xaa) != 0)) {
            in_stack_0000fffc = CONCAT11(0x14,uVar18);
          }
          else {
            in_stack_0000fffc = CONCAT11(3,uVar18);
          }
        }
        else if (paVar22->health == 0x3) {
          uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
          if (*(int *)(puStack_8 + 0x74) == 0 && *(int *)(puStack_8 + 0x76) == 0) {
            in_stack_0000fffc = CONCAT11(3,uVar18);
          }
          else {
            in_stack_0000fffc = CONCAT11(7,uVar18);
          }
        }
        else if (paVar22->health == 0x1) {
          uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
          if (*(int *)(puStack_8 + 0x9c) != 0 || *(int *)(puStack_8 + 0x9e) != 0) {
            in_stack_0000fffc = CONCAT11(0x11,uVar18);
          }
        }
        else if (paVar22->health == 0x4) {
          uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
          if (*(int *)(puStack_8 + 0xa4) != 0 || *(int *)(puStack_8 + 0xa6) != 0) {
            in_stack_0000fffc = CONCAT11(0x13,uVar18);
          }
        }
        else if (((paVar22->health == 0x5) || (paVar22->health == 0x6)) &&
                (uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10),
                *(int *)(puStack_8 + 0xac) != 0 || *(int *)(puStack_8 + 0xae) != 0)) {
          in_stack_0000fffc = CONCAT11(0x15,uVar18);
        }
      }
      else {
        in_stack_0000fffc = CONCAT11(4,uVar18);
        if (paVar22->health == 0x2) {
          in_stack_0000fffc = CONCAT11(0xf,uVar18);
        }
        else if (paVar22->health == 0x1) {
          in_stack_0000fffc = CONCAT11(5,uVar18);
        }
        uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
        if (*(int *)(puStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x58) == 0 &&
            *(int *)(puStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x5a) == 0) {
          in_stack_0000fffc = CONCAT11(4,(char)in_stack_0000fffc);
        }
      }
    }
L_OVC49_8699_18c4_1CA7:
    uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
    if (*(int *)(puStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x58) == 0 &&
        *(int *)(puStack_8 + (in_stack_0000fffc >> 8) * 4 + 0x5a) == 0) {
      if (paVar22->animVariant == 0x0) {
        in_stack_0000fffc = in_stack_0000fffc & 0xff;
      }
      else {
        in_stack_0000fffc = CONCAT11(4,(char)in_stack_0000fffc);
      }
    }
    bVar43 = (byte)(in_stack_0000fffc >> 8);
    if ((((paVar22->animVariant == 0x0) && (bVar43 != 0x12)) && (paVar22->health == 0x0)) &&
       ((*(char *)((int)&paVar22->targetX + 1) == '\0' && ((char)paVar22->targetX == '\0')))) {
      paVar22->targetY = 0;
    }
    paVar22->level = (uint8_t)in_stack_0000fffc;
    paVar22->frameIndex = bVar43;
    uVar28 = (undefined2)(CONCAT13(uVar39,CONCAT12(uVar35,puStack_8)) >> 0x10);
    iVar12 = *(int *)((int)(puStack_8 + (uint)bVar43 * 4) + 2);
    iVar23 = *(int *)(puStack_8 + (uint)bVar43 * 4);
    uVar18 = (undefined1)iVar23;
    uVar7 = (undefined1)((uint)iVar23 >> 8);
    if (*(char *)(iVar23 + 0x1a) == -1) {
      if ((int)(uint)*(byte *)(iVar23 + 0x1b) <= (int)(paVar22->targetY + 1)) {
        if ((((agntG_t *)paVar22->gdata)->flags3 & 4) == 0) {
          paVar22->health = 0x0;
        }
        else if (paVar22->animFrame == 0xff) {
          animBranchCode = 1;
          ovr_agnt_usesAnimFrame(agnt);
        }
        else {
          paVar22->health = 0x0;
        }
        if ((int)(uint)*(byte *)(CONCAT11(uVar7,uVar18) + 0x1b) <= (int)paVar22->targetY) {
          paVar22->targetY = 0;
        }
      }
    }
    else if ((int)(uint)*(byte *)(iVar23 + 0x1b) <= (int)paVar22->targetY) {
      paVar22->targetY = (uint)*(byte *)(iVar23 + 0x1a);
    }
    return in_stack_0000fffc >> 8;
  }
  if ((((agntG_t *)paVar22->gdata)->flags3 & 2) != 0) {
    in_stack_0000fffc = CONCAT11(0x12,uVar42);
    goto L_OVC49_8699_18c4_1CA7;
  }
  bVar43 = (byte)unaff_SS;
  uVar42 = (undefined1)((uint)unaff_SS >> 8);
  if (paVar22->animVariant != 0x0) {
    uVar13 = paVar22->timer & 3;
    if (uVar13 < 4) {
      switch(uVar13) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 2:
                    /* WARNING (jumptable): Read-only address (ram,0x0002db84) is written */
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
        pcVar1 = (char *)(uVar13 * 2 + unaff_SI);
        uRam0002db84 = uVar13;
        *pcVar1 = *pcVar1 + -0x4d;
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = (char)audioSaveCut1Seg;
        gfx_06.ofs = audioSaveCut1Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) = (char)((uint)audioSaveCut1Seg >> 8);
        (*(uint8_t *)((uint8_t *)&(dst.seg))) = (char)bStackY_32.seg;
        dst.ofs = 0x8cc;
        (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = (char)(bStackY_32.seg >> 8);
        ovr_blitLoadRleGfx(gfx_06,dst);
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) = (char)audioSaveCut2Seg;
        gfx_07.ofs = audioSaveCut2Ofs;
        (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) = (char)((uint)audioSaveCut2Seg >> 8);
        (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = (char)bStackY_32.seg;
        dst_00.ofs = 0x618c;
        (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = (char)(bStackY_32.seg >> 8);
        ovr_blitLoadRleGfx(gfx_07,dst_00);
        GGameState = 0x2c;
        (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = bVar43;
        dst_01.ofs = (uint16_t)&bStackY_32;
        (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar42;
        ovr_ovc23_textBuildThfres01Lbm(dst_01);
        cVar6 = 'o';
        cVar37 = '#';
        _fmemset(&stack0xffec,(uint16_t)unaff_SS,0);
        for (uStackY_22 = (cte_t *)0x0; (int)uStackY_22 < (int)(uint)AgntCount;
            uStackY_22 = (cte_t *)((int)uStackY_22 + 1)) {
          (&stack0xffec)[*(byte *)((int)uStackY_22 * 0x34 + 0x2f)] = 1;
        }
        if ((cVar6 == '\0') || (cVar37 == '\0')) {
          BothFactions = 0;
        }
        else {
          BothFactions = 1;
        }
        GGameState = 0x2d;
        if (DebugVerbose != false) {
          printf("%d \r");
        }
        uVar28 = 0x1000;
        uStackY_22 = (cte_t *)0x0;
        goto L_OVC49_8699_1e09_29B9;
      case 3:
        in_AF = 9 < (byte)uVar13 | in_AF;
        uVar13 = CONCAT11(in_AF,(byte)uVar13 + in_AF * '\x06') & 0xff0f &
                 *(uint *)(&stack0x02c2 + iVar12);
        cVar6 = (char)uVar13 * '\x02' + -1;
        uVar13 = CONCAT11((char)(uVar13 >> 8),cVar6);
        *(char *)&paVar22->targetX = cVar6;
        if ((((char)paVar22->targetX < '\x01') || (paVar22->level == 0x0)) &&
           ((-1 < (char)paVar22->targetX || (uVar13 = (uint)(char)paVar22->level, uVar13 != 0)))) {
          paVar22->health = 0x0;
        }
        else {
          paVar22->health = 0x1;
        }
      }
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
      return uVar13;
    }
    goto L_OVC49_8699_18c4_1CA7;
  }
  if ((char)paVar22->targetX < '\x01') {
    if (*(char *)((int)&paVar22->targetX + 1) < '\0') {
      iVar12 = 5;
    }
    else if (*(char *)((int)&paVar22->targetX + 1) == '\0') {
      iVar12 = 4;
    }
    else {
      iVar12 = 3;
    }
  }
  else if (*(char *)((int)&paVar22->targetX + 1) < '\0') {
    iVar12 = 0;
  }
  else if (*(char *)((int)&paVar22->targetX + 1) == '\0') {
    iVar12 = 1;
  }
  else {
    iVar12 = 2;
  }
  uVar13 = ((uint)paVar22->timer + iVar12) % 6;
  if (5 < uVar13) goto L_OVC49_8699_18c4_1CA7;
  switch(uVar13) {
  case 0:
    do {
      bVar8 = (byte)in_stack_0000ffe4;
      iVar12 = 0;
      uVar28 = (undefined2)((ulong)GUnits >> 0x10);
      uVar13 = (uint)((ulong)in_stack_0000ffe0 >> 0x10);
      in_stack_0000ffe0 = (ulong)uVar13 << 0x10;
      if (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116) == 0 &&
          *(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118) == 0) {
        if ((((uint)auStackY_26 < 0xf8) || (*(int *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x125) == 0))
           || ((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) != 0)) {
          if ((((*(uint *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x121) & 4) == 0) ||
              (((unit_t *)GUnits)[(int)auStackY_26].unitType == 0xff)) ||
             (uVar29 = *(undefined4 *)((uint)((unit_t *)GUnits)[(int)auStackY_26].unitType << 2),
             *(char *)((int)uVar29 + 0x3f) != '\0')) {
            auStackY_2f2[1] = 0x2410;
            auStackY_2f2[0] = 0x808a;
            iVar12 = 1;
          }
          in_stack_0000ffe0 = (ulong)uVar13 << 0x10;
        }
        else {
          auStackY_2f2[1] = 0x2410;
          auStackY_2f2[0] = 0x806a;
          iVar12 = 1;
          if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) != '\0') {
            ovr_fmVsprintf((char *)" Salvage value %d gold.",(char *)"puppetmaker" + 3);
            strcat(acStackY_2ca,unaff_SS);
          }
        }
      }
      else {
        auStackY_2f2[1] = *(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x118);
        auStackY_2f2[0] = *(undefined2 *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 0x116);
        iVar12 = 1;
      }
      uVar27 = 0x23f1;
      uVar13 = ovr_ovc45_compute8(((unit_t *)GUnits)[(int)auStackY_26].unitType);
      uVar28 = (undefined2)((ulong)GUnits >> 0x10);
      if (((char)uVar13 == '\0') || (7 < ((unit_t *)GUnits)[(int)auStackY_26].level)) {
        uVar27 = 0x23f1;
        uVar13 = ovr_ovc45_compute8(((unit_t *)GUnits)[(int)auStackY_26].unitType);
        if (((char)uVar13 != '\0') && (*(char *)(((uint)uStackY_22 >> 8) * 0x27 + 300) != '\0')) {
          (&stack0xffec)[iVar12] = 3;
          auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
          auStackY_2f2[iVar12 * 2] = (char *)"Upgrade";
          iVar12 = iVar12 + 1;
          in_stack_0000ffe0 =
               (ulong)*(uint *)(((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) +
                                (uint)*(byte *)((uint)(*(uint8_t *)((uint8_t *)&(uStackY_22) + 1)) * 0x27 + 300)) * 0x27 + 0x125
                               ) << 0x10;
          if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) == '\0') {
            ovr_fmVsprintf((char *)" Upgrade costs %d gp.",(char *)"puppetmaker" + 3);
            uVar27 = 0x1000;
            strcat(acStackY_2ca,unaff_SS);
          }
        }
      }
      else {
        (&stack0xffec)[iVar12] = 2;
        auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
        auStackY_2f2[iVar12 * 2] = (char *)"Repair";
        iVar12 = iVar12 + 1;
        in_stack_0000ffe0 =
             (ulong)(*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x125) / 5 + 1) << 0x10;
        if ((*(uint8_t *)((uint8_t *)&(bStackY_32.seg) + 1)) == '\0') {
          ovr_fmVsprintf((char *)" Repair costs %d gp.",(char *)"puppetmaker" + 3);
          uVar27 = 0x1000;
          strcat(acStackY_2ca,unaff_SS);
        }
      }
      bVar30 = ((unit_t *)GUnits)[(int)auStackY_26].unitType;
      uStackY_24 = CONCAT11((*(uint8_t *)((uint8_t *)&(uStackY_24) + 1)),bVar30);
      if ((((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 0x400) == 0) && (bVar30 != 0xff))
         && (*(char *)((int)*(undefined4 *)((uint)bVar30 << 2) + 0x3f) == '\0')) {
        (&stack0xffec)[iVar12] = 7;
        auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
        auStackY_2f2[iVar12 * 2] = (char *)"Information";
        iVar12 = iVar12 + 1;
      }
      uVar18 = 0x19;
      if (((*(uint *)(((uint)uStackY_22 >> 8) * 0x27 + 0x121) & 4) == 0) &&
         (0xf7 < (uint)auStackY_26)) {
        uVar18 = 0x24;
        if (*(char *)((int)&((entity_t *)Entities)[iStack000a].base.entity + 3) != (char)uStackY_24)
        {
          (&stack0xffec)[iVar12] = 6;
          auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
          auStackY_2f2[iVar12 * 2] = (char *)"New Owner";
          iVar12 = iVar12 + 1;
        }
      }
      if (in_stack_00000010 != '\0') {
        (&stack0xffec)[iVar12] = 4;
        auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
        auStackY_2f2[iVar12 * 2] = (char *)"Change Party";
        iVar12 = iVar12 + 1;
      }
      (&stack0xffec)[iVar12] = 5;
      auStackY_2f2[iVar12 * 2 + 1] = (char *)"puppetmaker" + 3;
      auStackY_2f2[iVar12 * 2] = (char *)"Done";
      count = (char *)(iVar12 + 1);
      puVar20 = (uint8_t *)CONCAT11(uVar18,(byte)uStackY_22);
      goldPartyIndex = (byte)uStackY_22;
      puVar9 = auStackY_2f2;
      uVar18 = (undefined1)uVar27;
      uVar31 = (uint8_t)((uint)uVar27 >> 8);
      in_stack_0000ffe8 = (stg_tmp_t *)&AgntAnms[0xd].eventFrame;
      (*(uint8_t *)((uint8_t *)&(entries.seg))) = bVar43;
      entries.ofs = (uint16_t)puVar9;
      (*(uint8_t *)((uint8_t *)&(entries.seg) + 1)) = uVar42;
      (*(uint8_t *)((uint8_t *)&(hint.seg))) = bVar43;
      hint.ofs = (uint16_t)acStackY_2ca;
      (*(uint8_t *)((uint8_t *)&(hint.seg) + 1)) = uVar42;
      bVar33 = bVar43;
      uVar7 = uVar42;
      pcVar36 = count;
      ovr_ovc28_compute2(entries,(uint16_t)count,hint);
      goldPartyIndex = 0xff;
      bVar30 = 0;
      if ((char)puVar9 != '\0') {
        puVar20 = &stack0xffeb;
        bVar30 = puVar20[(uint)puVar9 & 0xff];
      }
      in_stack_0000ffe4 = CONCAT11(bVar30,bVar8);
      pcVar10 = (cte_t *)(uint)bVar30;
      if ((cte_t *)((byte *)__C0_ASM_CopyRight + 3) < pcVar10) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      iVar12 = (int)pcVar10 * 2;
      switch(pcVar10) {
      case (cte_t *)0x0:
        do {
          if (*(char *)((int)pcVar10 * 0x34 + 5) < '\0') {
            piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
            *piVar2 = *piVar2 - *(int *)(CONCAT11(uVar7,bVar33) + 0x11);
          }
L_OVC49_8699_1e09_21A5:
          do {
            uVar28 = (undefined2)((ulong)in_stack_0000ffe0 >> 0x10);
            if ((*(int *)((int)uStackY_22 * 0x34) < 0) || (0xd2 < *(int *)((int)uStackY_22 * 0x34)))
            {
L_OVC49_8699_1e09_2229:
              cVar6 = '\0';
            }
            else {
code_r0x00088b64:
              if ((*(int *)((int)uStackY_22 * 0x34 + 2) < 0) ||
                 ((*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0' &&
                  (uVar13 = ovc49_compute1(*(int *)((int)uStackY_22 * 0x34)), (char)uVar13 != '\0'))
                 )) goto L_OVC49_8699_1e09_2229;
              cVar6 = '\x01';
            }
            if ((cVar6 == '\0') || (0x14 < *(int *)((int)uStackY_22 * 0x34 + 2))) {
              uVar7 = 0;
            }
            else {
              uVar7 = 1;
            }
            uVar29 = CONCAT31(CONCAT21(uVar28,cVar6),uVar7);
            if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
              iVar12 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
              iStackY_28 = *(int *)(iVar12 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
            }
            else {
              iVar12 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
              iStackY_28 = *(int *)(iVar12 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                           -0x16;
            }
            uVar28 = 0x22ff;
            *(int *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
            if ((*(char *)((int)uStackY_22 * 0x34 + 0x10) == '\x05') &&
               (*(char *)((int)uStackY_22 * 0x34 + 0xc) != -1)) {
              uVar28 = 0x23d5;
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
                uVar13 = ovc49_compute1(*(int *)((int)uStackY_22 * 0x34));
                if ((char)uVar13 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    uVar14 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar14 + -1;
                  }
                  else {
                    *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4);
                  }
                  uVar28 = ovc49_agentIsActive((agnt_t *)
                                               CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)))
                  ;
                  if ((char)uVar28 == '\0') {
                    uVar14 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar14 + -1;
                  }
                  else {
                    uVar14 = ovr_randBelow(2);
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = (char)uVar14;
                  }
                  uVar28 = 0x2337;
                  if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar29 = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
                  goto L_OVC49_8699_1e09_2982;
                }
              }
              if (((char)((ulong)uVar29 >> 8) == '\0') ||
                 ((((char)uVar29 == '\0' && (-1 < *(char *)((int)uStackY_22 * 0x34 + 5))) &&
                  (uVar13 = ovc49_agentIsActive((agnt_t *)
                                                CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34))
                                               ), (uVar13 & 0xff) == 0)))) {
                if (*(char *)((int)uStackY_22 * 0x34 + 0x25) != '\x02') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
                  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
                    if (*(char *)((int)uStackY_22 * 0x34 + 4) == '\0') {
                      uVar14 = ovr_randBelow(2);
                      *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar14 * '\x02' + -1;
                    }
                    else {
                      *(char *)((int)uStackY_22 * 0x34 + 4) = -*(char *)((int)uStackY_22 * 0x34 + 4)
                      ;
                    }
                    uVar28 = 0x2337;
                    uVar14 = ovr_randBelow(3);
                    *(char *)((int)uStackY_22 * 0x34 + 5) = (char)uVar14 + -1;
                  }
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar29 = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
                }
              }
              else {
                iVar12 = ovc49_usesStExit((agnt_t *)((int)uStackY_22 * 0x34));
                if ((char)iVar12 != '\0') {
                  *(undefined2 *)((int)uStackY_22 * 0x34) = uStackY_24;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 2) = auStackY_26;
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
                    uVar28 = 0x2337;
                    uVar14 = ovr_randBelow(2);
                    *(char *)((int)uStackY_22 * 0x34 + 4) = (char)uVar14 * '\x02' + -1;
                  }
                  *(undefined1 *)((int)uStackY_22 * 0x34 + 5) = 0;
                  *(undefined2 *)((int)uStackY_22 * 0x34 + 6) = 0;
                  if ((('\0' < *(char *)((int)uStackY_22 * 0x34 + 4)) &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) != '\0')) ||
                     ((*(char *)((int)uStackY_22 * 0x34 + 4) < '\0' &&
                      (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0')))) {
                    *(undefined1 *)((int)uStackY_22 * 0x34 + 0x10) = 1;
                  }
                  uVar29 = 0;
                  ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
                }
              }
            }
            else {
              *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
            }
L_OVC49_8699_1e09_2982:
            cVar6 = (char)((ulong)uVar29 >> 0x18);
            ovc49_fillGridCells((byte)uStackY_22 + 1,(agnt_t *)((int)uStackY_22 * 0x34));
            if (cVar6 != '\0') {
              uVar28 = 0x22ff;
              uVar27 = ovr_agnt_usesAgntSaved((int)uStackY_22);
              if ((char)uVar27 != '\0') {
                uStackY_22 = (cte_t *)(uStackY_22[-1].info + 0xb);
              }
            }
            uStackY_22 = (cte_t *)&uStackY_22->ofs;
L_OVC49_8699_1e09_29B9:
            bVar8 = (byte)in_stack_0000ffe4;
            bVar33 = (byte)uVar28;
            uVar7 = (undefined1)((uint)uVar28 >> 8);
            if ((int)(uint)AgntCount <= (int)uStackY_22) {
              GGameState = 0x2e;
              if (DebugVerbose != false) {
                uVar28 = 0x1000;
                printf("%d \r");
              }
              uStackY_22 = (cte_t *)0x0;
              goto L_OVC49_8699_1e09_3BDE;
            }
            uVar28 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
            iVar12 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
            ovc49_fillGridCells(0,(agnt_t *)((int)uStackY_22 * 0x34));
            ovc49_textLongerParalyzed
                      ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                       (byte)uStackY_22);
            _auStackY_26 = CONCAT22(*(undefined2 *)((int)uStackY_22 * 0x34),
                                    *(undefined2 *)((int)uStackY_22 * 0x34 + 2));
            uVar13 = ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
            in_stack_0000ffe4 = (uint16_t)bVar8;
            uVar27 = 0x1726;
            iVar12 = iVar12 + (uVar13 & 0xff) * 4;
            psVar15 = (stg_tmp_t *)*(undefined2 *)(iVar12 + 0x58);
            uVar32 = SUB21(psVar15,0);
            uVar35 = (undefined1)((uint)psVar15 >> 8);
            in_stack_0000ffe8 = ovr_stash_usesStExit(psVar15,(byte)*(undefined2 *)(iVar12 + 0x5a));
            pcVar36 = (char *)CONCAT11(uVar35,uVar32);
            uVar18 = (undefined1)uVar27;
            uVar31 = (uint8_t)((uint)uVar27 >> 8);
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
            in_stack_0000ffe0 = 0x1000000;
            if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01') {
              if (*(char *)((int)uStackY_22 * 0x34 + 5) < '\0') {
                piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
                *piVar2 = *piVar2 - *(int *)(CONCAT11(uVar7,bVar33) + 0x11);
              }
              else {
                in_stack_0000ffe0 = 0;
              }
            }
            else {
              piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
              *piVar2 = *piVar2 + *(int *)(CONCAT11(uVar7,bVar33) + 0x11);
            }
          } while (*(int *)((int)uStackY_22 * 0x34 + 2) < 0x15);
          pcVar10 = uStackY_22;
        } while (*(char *)((int)uStackY_22 * 0x34 + 5) < '\x01');
        piVar2 = (int *)((int)uStackY_22 * 0x34 + 2);
        *piVar2 = *piVar2 + *(int *)(CONCAT11(uVar7,bVar33) + 0x11);
        goto L_OVC49_8699_1e09_21A5;
      case (cte_t *)0x1:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case (cte_t *)0x2:
        ovr_fmVsprintf((char *)"%s: %s %d gold. Feeds %d %s.",(char *)"puppetmaker" + 3);
        puStack_8 = (uint8_t *)((char *)"glassworks" + 9);
        in_stack_0000fff6 = (stg_tmp_t *)((char *)"choose" + 4);
        strcpy(acStackY_2ca,unaff_SS);
        break;
      case (cte_t *)0x3:
        SpecialColors[2] =
             ((char *)"If you lead with wisdom and cunning..." + 9)[(in_stack_0000fff6->aptr).ofs];
        SpecialColors[3] =
             ((char *)"ENTER: use previous configuration, SPACE: reconfigure, ESC: quit" + 0x12)
             [(in_stack_0000fff6->aptr).ofs];
        SpecialColors[4] = ((char *)"%s turns %d undead." + 0x10)[(in_stack_0000fff6->aptr).ofs];
        SpecialColors[5] =
             *(uint8_t *)((int)&GStrangeTable[0x12].seg + 1 + (in_stack_0000fff6->aptr).ofs);
        SpecialColors[6] =
             *(uint8_t *)((int)(uint8_t **)&youlose1Cut1Seg + (in_stack_0000fff6->aptr).ofs);
        SpecialColors[7] = *(uint8_t *)((in_stack_0000fff6->aptr).ofs + 0x936e);
        puVar20 = (uint8_t *)((char *)"puppetmaker" + 3);
        SpecialColors[1] = bVar30;
        specialColorsOfs =
             ovr_stshWrite((uint32_t *)SpecialColors,(uint8_t *)((char *)"puppetmaker" + 3),8);
        (*(uint8_t *)((uint8_t *)&(src.seg))) = 0xea;
        src.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src.seg) + 1)) = 0;
        specialColorsSeg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src,64,314,120,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        (*(uint8_t *)((uint8_t *)&(src_00.seg))) = 0xd0;
        src_00.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_00.seg) + 1)) = 0;
        trianglsCut1Seg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_00,158,228,176,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        (*(uint8_t *)((uint8_t *)&(src_01.seg))) = 0xb3;
        src_01.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_01.seg) + 1)) = 0;
        trianglsCut2Seg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_01,180,198,196,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        (*(uint8_t *)((uint8_t *)&(src_02.seg))) = 0xcf;
        src_02.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_02.seg) + 1)) = 0;
        trianglsCut3Seg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_02,180,226,196,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        (*(uint8_t *)((uint8_t *)&(src_03.seg))) = 0x26;
        src_03.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_03.seg) + 1)) = 0;
        trianglsCut4Seg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_03,181,57,196,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        (*(uint8_t *)((uint8_t *)&(src_04.seg))) = 9;
        src_04.ofs = (in_stack_0000fff6->aptr).seg;
        (*(uint8_t *)((uint8_t *)&(src_04.seg) + 1)) = 0;
        trianglsCut5Seg = puVar20;
        pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_04,181,24,196,
                                 (int16_t)in_stack_0000fff6);
        trianglsCut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
        trianglsCut6Seg = puVar20;
        ovr_stgFreeTmp(in_stack_0000fff6);
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          panel01Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          panel01Cut1Seg = puVar20;
          panel01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          panel01Cut2Seg = puVar20;
          panel01Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          panel01Cut3Seg = puVar20;
          Lbm_nwpanel1.ofs = (uint16_t)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          Lbm_nwpanel1.seg = (uint16_t)puVar20;
          nwpanel1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          nwpanel1Cut1Seg = puVar20;
          fullScreenGfxOfs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          fullScreenGfxSeg = puVar20;
          FontHandle.ofs = (uint16_t)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          FontHandle.seg = (uint16_t)puVar20;
          nwpanel1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          nwpanel1Cut2Seg = puVar20;
          nwpanel1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          nwpanel1Cut3Seg = puVar20;
          nwpanel1Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          nwpanel1Cut4Seg = puVar20;
          nwpanel1Cut5Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          nwpanel1Cut5Seg = puVar20;
          for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            *(int *)((int)&CrossBlitGfx.seg + iVar12 * 4) = (int)puVar20;
            ((far_t *)&CrossBlitGfx + iVar12)->ofs = (uint16_t)pfVar11;
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&crossBlitType2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&crossBlitType2Ofs)[iVar12 * 2] = pfVar11;
          }
        }
        else {
          psVar15 = ovr_grabLbmTR(127);
          (*(uint8_t *)((uint8_t *)&(src_05.seg))) = 0xf5;
          src_05.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_05.seg) + 1)) = 0;
          puVar19 = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_05,116,267,128,
                                   (int16_t)psVar15);
          panel01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_06.seg))) = 0x24;
          src_06.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_06.seg) + 1)) = 1;
          panel01Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_06,114,314,133,
                                   (int16_t)psVar15);
          panel01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_07.seg))) = 0xdd;
          src_07.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_07.seg) + 1)) = 0;
          panel01Cut2Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_07,157,228,198,
                                   (int16_t)psVar15);
          panel01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          panel01Cut3Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(15,0,0);
          puStack_8 = puVar19;
          Lbm_nwpanel1.ofs = (uint16_t)ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300);
          (*(uint8_t *)((uint8_t *)&(src_08.seg))) = 0xe6;
          src_08.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_08.seg) + 1)) = 0;
          Lbm_nwpanel1.seg = (uint16_t)puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_08,57,314,113,(int16_t)psVar15
                                  );
          nwpanel1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          src_09.seg = 0;
          src_09.ofs = (psVar15->aptr).seg;
          nwpanel1Cut1Seg = puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_09,0,319,199,(int16_t)psVar15)
          ;
          fullScreenGfxOfs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_10.seg))) = 0x1d;
          src_10.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_10.seg) + 1)) = 0;
          fullScreenGfxSeg = puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_10,156,207,199,
                                   (int16_t)psVar15);
          FontHandle.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_11.seg))) = 9;
          src_11.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_11.seg) + 1)) = 0;
          FontHandle.seg = (uint16_t)puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_11,181,28,196,(int16_t)psVar15
                                  );
          nwpanel1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_12.seg))) = 0xdf;
          src_12.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_12.seg) + 1)) = 0;
          nwpanel1Cut2Seg = puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_12,8,237,50,(int16_t)psVar15);
          nwpanel1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_13.seg))) = 6;
          src_13.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_13.seg) + 1)) = 0;
          nwpanel1Cut3Seg = puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_13,156,28,171,(int16_t)psVar15
                                  );
          nwpanel1Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_14.seg))) = 0xd0;
          src_14.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_14.seg) + 1)) = 0;
          nwpanel1Cut4Seg = puStack_8;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_14,157,229,198,
                                   (int16_t)psVar15);
          nwpanel1Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          nwpanel1Cut5Seg = puStack_8;
          ovr_stgFreeTmp(psVar15);
          in_stack_0000fff6 = ovr_grabLbm(12,0,0);
          puVar20 = puStack_8;
          for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
            lVar4 = (long)iVar12 * 0xe;
            uVar28 = (undefined2)((ulong)lVar4 >> 0x10);
            (*(uint8_t *)((uint8_t *)&(src_15.seg))) = (char)lVar4;
            src_15.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(src_15.seg) + 1)) = (char)((ulong)lVar4 >> 8);
            pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_15,46,
                                     iVar12 * 0xe + 0xd,55,(int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            *(undefined2 *)((int)&CrossBlitGfx.seg + iVar12 * 4) = uVar28;
            ((far_t *)&CrossBlitGfx + iVar12)->ofs = (uint16_t)pcVar10;
            lVar4 = (long)iVar12 * 0xe;
            puVar20 = (uint8_t *)((ulong)lVar4 >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels.seg))) = (char)lVar4;
            pixels.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels.seg) + 1)) = (uint8_t)((ulong)lVar4 >> 8);
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels,16,
                                       iVar12 * 0xe + 0xd,24,6,4,(int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&crossBlitType2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&crossBlitType2Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          for (iVar12 = 0; iVar12 < 0x17; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&csite1Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite1Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 0x18; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&csite2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite2Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 0x20; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&csite5Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite5Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 0xe; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 0x11; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites5Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites5Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites4Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites4Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites3Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites3Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 8; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites2Ofs)[iVar12 * 2] = pfVar11;
          }
          for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&tmstrsSprites1Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites1Ofs)[iVar12 * 2] = pfVar11;
          }
        }
        else {
          psVar15 = ovr_grabLbm(93,0,0);
          puVar19 = puVar20;
          for (iVar12 = 0; iVar12 < 6; iVar12 = iVar12 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_00.seg))) = 8;
            pixels_00.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_00.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_00,iVar12 * 0x20 + 10,
                                       63,iVar12 * 0x20 + 0x24,0,0,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite1Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite1Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 6; iVar12 = iVar12 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_01.seg))) = 0x55;
            pixels_01.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_01.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_01,iVar12 * 0x20 + 10,
                                       140,iVar12 * 0x20 + 0x24,0,0,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite1_6Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite1_6Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 6; iVar12 = iVar12 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_02.seg))) = 0x9f;
            pixels_02.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_02.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_02,iVar12 * 0x20 + 10,
                                       214,iVar12 * 0x20 + 0x24,0,0,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite1_12Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite1_12Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {
            (*(uint8_t *)((uint8_t *)&(pixels_03.seg))) = 0xe5;
            pixels_03.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_03.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_03,iVar12 * 0x20 + 10,
                                       284,iVar12 * 0x20 + 0x24,0,0,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite1_18Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite1_18Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(94,0,0);
          puVar20 = puVar19;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            pixels_04.seg = 0;
            pixels_04.ofs = (psVar15->aptr).seg;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_04,
                                       (int)((long)iVar12 * 0x3d) + 0x11,104,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite2Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_05.seg))) = 0x6d;
            pixels_05.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_05.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_05,
                                       (int)((long)iVar12 * 0x3d) + 0x11,213,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite2_3Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite2_3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_06.seg))) = 0xd7;
            pixels_06.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_06.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_06,
                                       (int)((long)iVar12 * 0x3d) + 0x11,319,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite2_6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite2_6Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(95,0,0);
          puVar19 = puVar20;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            pixels_07.seg = 0;
            pixels_07.ofs = (psVar15->aptr).seg;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_07,
                                       (int)((long)iVar12 * 0x3d) + 0x11,104,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite3Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_08.seg))) = 0x6d;
            pixels_08.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_08.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_08,
                                       (int)((long)iVar12 * 0x3d) + 0x11,213,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite3_3Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite3_3Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(96,0,0);
          puVar20 = puVar19;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            pixels_09.seg = 0;
            pixels_09.ofs = (psVar15->aptr).seg;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_09,
                                       (int)((long)iVar12 * 0x3d) + 0x11,104,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite4Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite4Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_10.seg))) = 0x6d;
            pixels_10.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_10.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_10,
                                       (int)((long)iVar12 * 0x3d) + 0x11,213,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite4_3Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite4_3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_11.seg))) = 0xd7;
            pixels_11.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_11.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_11,
                                       (int)((long)iVar12 * 0x3d) + 0x11,319,iVar12 * 0x3d + 0x49,0,
                                       -60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite4_6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite4_6Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(531,0,0);
          puVar19 = puVar20;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_12.seg))) = 1;
            pixels_12.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_12.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_12,
                                       (int)((long)iVar12 * 0x3d) + 0x11,103,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite5Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite5Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_13.seg))) = 0x68;
            pixels_13.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_13.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_13,
                                       (int)((long)iVar12 * 0x3d) + 0x11,206,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite5_3Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite5_3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_14.seg))) = 0xd1;
            pixels_14.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_14.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_14,
                                       (int)((long)iVar12 * 0x3d) + 0x11,311,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite5_6Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite5_6Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(532,0,0);
          puVar20 = puVar19;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_15.seg))) = 1;
            pixels_15.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_15.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_15,
                                       (int)((long)iVar12 * 0x3d) + 0x11,103,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite6Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_16.seg))) = 0x68;
            pixels_16.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_16.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_16,
                                       (int)((long)iVar12 * 0x3d) + 0x11,206,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite6_3Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite6_3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_17.seg))) = 0xd1;
            pixels_17.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_17.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_17,
                                       (int)((long)iVar12 * 0x3d) + 0x11,311,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite6_6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&csite6_6Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(533,0,0);
          puVar19 = puVar20;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_18.seg))) = 1;
            pixels_18.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_18.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_18,
                                       (int)((long)iVar12 * 0x3d) + 0x11,103,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite7Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite7Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_19.seg))) = 0x68;
            pixels_19.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_19.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_19,
                                       (int)((long)iVar12 * 0x3d) + 0x11,206,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite7_3Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite7_3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar19 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_20.seg))) = 0xd1;
            pixels_20.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_20.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_20,
                                       (int)((long)iVar12 * 0x3d) + 0x11,311,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite7_6Seg)[iVar12 * 2] = puVar19;
            ((undefined2 *)&csite7_6Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(534,0,0);
          puStack_8 = puVar19;
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puStack_8 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_21.seg))) = 1;
            pixels_21.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_21.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_21,
                                       (int)((long)iVar12 * 0x3d) + 0x11,103,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite8Seg)[iVar12 * 2] = puStack_8;
            ((undefined2 *)&csite8Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 2; iVar12 = iVar12 + 1) {
            puStack_8 = (uint8_t *)((ulong)((long)iVar12 * 0x3d) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_22.seg))) = 0x68;
            pixels_22.ofs = (psVar15->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_22.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_22,
                                       (int)((long)iVar12 * 0x3d) + 0x11,206,iVar12 * 0x3d + 0x49,-4
                                       ,-60,(int16_t)psVar15);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&csite8_3Seg)[iVar12 * 2] = puStack_8;
            ((undefined2 *)&csite8_3Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(psVar15);
          in_stack_0000fff6 = ovr_grabLbm(535,0,0);
          puVar20 = puStack_8;
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_23.seg))) = 6;
            pixels_23.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_23.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_23,
                                       (int)((long)iVar12 * 0x1b) + 8,33,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_24.seg))) = 0x23;
            pixels_24.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_24.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_24,
                                       (int)((long)iVar12 * 0x1b) + 8,62,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites9Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites9Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_25.seg))) = 0x4c;
            pixels_25.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_25.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_25,
                                       (int)((long)iVar12 * 0x1b) + 8,88,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites5Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites5Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_26.seg))) = 0x66;
            pixels_26.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_26.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_26,
                                       (int)((long)iVar12 * 0x1b) + 8,114,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites6Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites6Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_27.seg))) = 0x80;
            pixels_27.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_27.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_27,
                                       (int)((long)iVar12 * 0x1b) + 8,140,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites7Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites7Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_28.seg))) = 0x9a;
            pixels_28.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_28.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_28,
                                       (int)((long)iVar12 * 0x1b) + 8,163,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites4Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites4Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_29.seg))) = 0xb8;
            pixels_29.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_29.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_29,
                                       (int)((long)iVar12 * 0x1b) + 8,185,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites3Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites3Ofs)[iVar12 * 2] = pcVar10;
          }
          for (iVar12 = 0; iVar12 < 7; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_30.seg))) = 0xcf;
            pixels_30.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_30.seg) + 1)) = 0;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_30,
                                       (int)((long)iVar12 * 0x1b) + 8,223,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites2Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites2Ofs)[iVar12 * 2] = pcVar10;
          }
          (*(uint8_t *)((uint8_t *)&(pixels_31.seg))) = 0xeb;
          pixels_31.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_31.seg) + 1)) = 0;
          pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_31,8,251,19,0,0
                                     ,(int16_t)in_stack_0000fff6);
          anim_tmstrsCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          anim_tmstrsCut1Seg = puVar20;
          for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {
            puVar20 = (uint8_t *)((ulong)((long)iVar12 * 0x1b) >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_32.seg))) = 0xb;
            pixels_32.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_32.seg) + 1)) = 1;
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_32,
                                       (int)((long)iVar12 * 0x1b) + 8,286,iVar12 * 0x1b + 0x13,0,0,
                                       (int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&tmstrsSprites1Seg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&tmstrsSprites1Ofs)[iVar12 * 2] = pcVar10;
          }
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) != false) {
          in_stack_0000fff6 = ovr_grabLbm(35,0,0);
          puStack_8 = puVar20;
        }
        for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
          if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
            pfVar11 = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
            ((undefined2 *)&boltSpritesSeg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&boltSpritesOfs)[iVar12 * 2] = pfVar11;
          }
          else {
            lVar4 = (long)iVar12 * 0x16;
            puVar20 = (uint8_t *)((ulong)lVar4 >> 0x10);
            (*(uint8_t *)((uint8_t *)&(pixels_33.seg))) = (char)lVar4;
            pixels_33.ofs = (in_stack_0000fff6->aptr).seg;
            (*(uint8_t *)((uint8_t *)&(pixels_33.seg) + 1)) = (uint8_t)((ulong)lVar4 >> 8);
            pfVar11 = ovr_stshRleType2((far_t *)(&in_stack_0000fff6->aptr)->ofs,pixels_33,0,
                                       iVar12 * 0x16 + 0x15,14,11,7,(int16_t)in_stack_0000fff6);
            pcVar10 = ovr_stshStoreFile((uint8_t *)pfVar11);
            ((undefined2 *)&boltSpritesSeg)[iVar12 * 2] = puVar20;
            ((undefined2 *)&boltSpritesOfs)[iVar12 * 2] = pcVar10;
          }
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          gamfont1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          gamfont1Cut1Seg = puVar20;
          davfontCut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          davfontCut1Seg = puVar20;
          _davfont2Cut1Ofs = (cte_t *)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          davfont2Cut1Seg = puVar20;
          demfont1FontOfs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          demfont1FontSeg = puVar20;
          talkwin9Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          talkwin9Cut1Seg = puVar20;
          talkwin9Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          talkwin9Cut2Seg = puVar20;
          talkwin9Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          talkwin9Cut3Seg = puVar20;
          talkwin9Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          talkwin9Cut4Seg = puVar20;
          talkwin9Cut5Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          talkwin9Cut5Seg = puVar20;
          LbxButton2.ofs = (uint16_t)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          LbxButton2.seg = (uint16_t)puVar20;
          pcVar10 = (cte_t *)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          iVar12 = 0x2410;
code_r0x00083f6a:
          *(uint8_t **)&butt01Cut1Seg = puVar20;
          *(cte_t **)&butt01Cut1Ofs = pcVar10;
          butt01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          butt01Cut2Seg = puVar20;
          butt01Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          butt01Cut3Seg = puVar20;
          butt01Cut4Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          butt01Cut4Seg = puVar20;
          butt01Cut5Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          butt01Cut5Seg = puVar20;
          butt01Cut6Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          butt01Cut6Seg = puVar20;
        }
        else {
          ovr_stgFreeTmp(in_stack_0000fff6);
          psVar15 = ovr_grabLbm(8,0,0);
          src_16.seg = 0;
          src_16.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_16,0,319,199,(int16_t)psVar15)
          ;
          gamfont1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          gamfont1Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(6,0,0);
          src_17.seg = 0;
          src_17.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_17,0,319,199,(int16_t)psVar15)
          ;
          davfontCut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          davfontCut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(140,0,0);
          src_18.seg = 0;
          src_18.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_18,0,319,27,(int16_t)psVar15);
          _davfont2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          davfont2Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(411,0,0);
          FontSize.hi = 0;
          FontSize.lo = 0;
          hndl.seg = (uint16_t)psVar15;
          hndl.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshProcessFontSub((far_t *)(&psVar15->aptr)->ofs,hndl);
          demfont1FontOfs =
               (far_t *)ovr_stshWrite((uint32_t *)pfVar11,puVar20,
                                      CONCAT13((char)(FontSize.hi >> 8),
                                               CONCAT12((char)FontSize.hi,FontSize.lo)));
          demfont1FontSeg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(78,0,0);
          (*(uint8_t *)((uint8_t *)&(pixels_34.seg))) = 8;
          pixels_34.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_34.seg) + 1)) = 0;
          puVar19 = puVar20;
          pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_34,3,226,194,-8,-3,
                                     (int16_t)psVar15);
          talkwin9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(pixels_35.seg))) = 0xdd;
          pixels_35.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_35.seg) + 1)) = 0;
          talkwin9Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_35,157,229,198,-221,-157,
                                     (int16_t)psVar15);
          talkwin9Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(pixels_36.seg))) = 0xd0;
          pixels_36.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_36.seg) + 1)) = 0;
          talkwin9Cut2Seg = puVar19;
          pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_36,195,223,199,-208,-195,
                                     (int16_t)psVar15);
          talkwin9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(pixels_37.seg))) = 8;
          pixels_37.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(pixels_37.seg) + 1)) = 0;
          talkwin9Cut3Seg = puVar19;
          pfVar11 = ovr_stshRleType2((far_t *)(&psVar15->aptr)->ofs,pixels_37,117,226,194,-8,-117,
                                     (int16_t)psVar15);
          talkwin9Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          talkwin9Cut4Seg = puVar19;
          talkwin9Cut5Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          talkwin9Cut5Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(543,0,0);
          (*(uint8_t *)((uint8_t *)&(src_19.seg))) = 8;
          src_19.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_19.seg) + 1)) = 0;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_19,5,16,10,(int16_t)psVar15);
          LbxButton2.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar11);
          LbxButton2.seg = (uint16_t)puVar19;
          ovr_stgFreeTmp(psVar15);
          in_stack_0000fff6 = ovr_grabLbm(139,0,0);
          (*(uint8_t *)((uint8_t *)&(src_20.seg))) = 0x10;
          src_20.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_20.seg) + 1)) = 0;
          puVar20 = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_20,121,57,131,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_21.seg))) = 0x10;
          src_21.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_21.seg) + 1)) = 0;
          butt01Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_21,134,57,144,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_22.seg))) = 0xea;
          src_22.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_22.seg) + 1)) = 0;
          butt01Cut2Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_22,121,300,131,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_23.seg))) = 0xea;
          src_23.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_23.seg) + 1)) = 0;
          butt01Cut3Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_23,134,300,144,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut4Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_24.seg))) = 0x99;
          src_24.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_24.seg) + 1)) = 0;
          butt01Cut4Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_24,121,230,131,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut5Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_25.seg))) = 0x99;
          src_25.ofs = (in_stack_0000fff6->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_25.seg) + 1)) = 0;
          butt01Cut5Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_25,134,230,144,
                                   (int16_t)in_stack_0000fff6);
          butt01Cut6Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          butt01Cut6Seg = puVar20;
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          button1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          button1Cut1Seg = puVar20;
          button1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          button1Cut2Seg = puVar20;
          button1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          button1Cut3Seg = puVar20;
          back03Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          back03Cut1Seg = puVar20;
          back03Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          back03Cut2Seg = puVar20;
          midgrnd5Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          midgrnd5Cut1Seg = puVar20;
          midgrnd5Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          midgrnd5Cut2Seg = puVar20;
          strong4Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          strong4Cut1Seg = puVar20;
          strong4Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          strong4Cut2Seg = puVar20;
          marbleCut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          marbleCut1Seg = puVar20;
          marbleCut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          marbleCut2Seg = puVar20;
          far_t_2000_d3e4.ofs = (uint16_t)ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          far_t_2000_d3e4.seg = (uint16_t)puVar20;
          back2Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          back2Cut1Seg = puVar20;
          back2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          back2Cut2Seg = puVar20;
          midl3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          midl3Cut1Seg = puVar20;
          midl3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          midl3Cut2Seg = puVar20;
          frnt3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          frnt3Cut1Seg = puVar20;
          frnt3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          frnt3Cut2Seg = puVar20;
          winrebg1Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          winrebg1Cut1Seg = puVar20;
          winrebg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          winrebg1Cut2Seg = puVar20;
          winremg2Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          winremg2Cut1Seg = puVar20;
          winremg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          winremg2Cut2Seg = puVar20;
          winrefg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          winrefg1Cut1Seg = puVar20;
          winrefg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          winrefg1Cut2Seg = puVar20;
          captbg2Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          captbg2Cut1Seg = puVar20;
          captbg2Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          captbg2Cut2Seg = puVar20;
          captmg3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          captmg3Cut1Seg = puVar20;
          captmg3Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          captmg3Cut2Seg = puVar20;
          captfg1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          captfg1Cut1Seg = puVar20;
          captfg1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          captfg1Cut2Seg = puVar20;
          l1Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l1Cut1Seg = puVar20;
          l1Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l1Cut2Seg = puVar20;
          l1Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l1Cut3Seg = puVar20;
          l4Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l4Cut1Seg = puVar20;
          l4Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l4Cut2Seg = puVar20;
          l4Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l4Cut3Seg = puVar20;
          l7Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l7Cut1Seg = puVar20;
          l7Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l7Cut2Seg = puVar20;
          l7Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l7Cut3Seg = puVar20;
          l2Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l2Cut1Seg = puVar20;
          l2Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l2Cut2Seg = puVar20;
          l2Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l2Cut3Seg = puVar20;
          l5Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l5Cut1Seg = puVar20;
          l5Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l5Cut2Seg = puVar20;
          l5Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l5Cut3Seg = puVar20;
          l8Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l8Cut1Seg = puVar20;
          l8Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l8Cut2Seg = puVar20;
          l8Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l8Cut3Seg = puVar20;
          l3Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l3Cut1Seg = puVar20;
          l3Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l3Cut2Seg = puVar20;
          l3Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l3Cut3Seg = puVar20;
          l6Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l6Cut1Seg = puVar20;
          l6Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l6Cut2Seg = puVar20;
          l6Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l6Cut3Seg = puVar20;
          l9Cut1Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l9Cut1Seg = puVar20;
          l9Cut2Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l9Cut2Seg = puVar20;
          l9Cut3Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          l9Cut3Seg = puVar20;
        }
        else {
          psVar15 = ovr_grabLbm(179,0,0);
          (*(uint8_t *)((uint8_t *)&(src_26.seg))) = 0x5e;
          src_26.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_26.seg) + 1)) = 0;
          puVar19 = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_26,47,108,89,(int16_t)psVar15)
          ;
          button1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_27.seg))) = 0x72;
          src_27.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_27.seg) + 1)) = 0;
          button1Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_27,47,128,89,(int16_t)psVar15)
          ;
          button1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          (*(uint8_t *)((uint8_t *)&(src_28.seg))) = 0xdf;
          src_28.ofs = (psVar15->aptr).seg;
          (*(uint8_t *)((uint8_t *)&(src_28.seg) + 1)) = 0;
          button1Cut2Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_28,8,237,50,(int16_t)psVar15);
          button1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          button1Cut3Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(158,0,0);
          puVar20 = puVar19;
          back03Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300));
          src_29.seg = 0;
          src_29.ofs = (psVar15->aptr).seg;
          back03Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_29,0,319,80,(int16_t)psVar15);
          back03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          back03Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(159,0,0);
          src_30.seg = 0;
          src_30.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_30,0,219,143,(int16_t)psVar15)
          ;
          midgrnd5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          midgrnd5Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(159,220,0);
          src_31.seg = 0;
          src_31.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_31,0,219,143,(int16_t)psVar15)
          ;
          midgrnd5Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          midgrnd5Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(160,0,0);
          src_32.seg = 0;
          src_32.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_32,0,279,143,(int16_t)psVar15)
          ;
          strong4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          strong4Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(160,280,0);
          src_33.seg = 0;
          src_33.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_33,0,279,143,(int16_t)psVar15)
          ;
          strong4Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          strong4Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(161,0,0);
          puVar19 = puVar20;
          marbleCut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          src_34.seg = 0;
          src_34.ofs = (psVar15->aptr).seg;
          marbleCut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_34,144,319,199,
                                   (int16_t)psVar15);
          marbleCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          src_35.seg = 0;
          src_35.ofs = (psVar15->aptr).seg;
          marbleCut2Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_35,0,47,10,(int16_t)psVar15);
          far_t_2000_d3e4.ofs = (uint16_t)ovr_stshStoreFile((uint8_t *)pfVar11);
          far_t_2000_d3e4.seg = (uint16_t)puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(412,0,0);
          puVar20 = puVar19;
          back2Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300));
          src_36.seg = 0;
          src_36.ofs = (psVar15->aptr).seg;
          back2Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_36,0,319,80,(int16_t)psVar15);
          back2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          back2Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(414,0,0);
          src_37.seg = 0;
          src_37.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_37,0,219,143,(int16_t)psVar15)
          ;
          midl3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          midl3Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(414,220,0);
          src_38.seg = 0;
          src_38.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_38,0,219,143,(int16_t)psVar15)
          ;
          midl3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          midl3Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(413,0,0);
          src_39.seg = 0;
          src_39.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_39,0,279,143,(int16_t)psVar15)
          ;
          frnt3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          frnt3Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(413,280,0);
          src_40.seg = 0;
          src_40.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_40,0,279,143,(int16_t)psVar15)
          ;
          frnt3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          frnt3Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(422,0,0);
          puVar19 = puVar20;
          winrebg1Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          src_41.seg = 0;
          src_41.ofs = (psVar15->aptr).seg;
          winrebg1Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_41,0,319,113,(int16_t)psVar15)
          ;
          winrebg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          winrebg1Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(421,0,0);
          src_42.seg = 0;
          src_42.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_42,0,219,143,(int16_t)psVar15)
          ;
          winremg2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          winremg2Cut1Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(421,220,0);
          src_43.seg = 0;
          src_43.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_43,0,219,143,(int16_t)psVar15)
          ;
          winremg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          winremg2Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(420,0,0);
          src_44.seg = 0;
          src_44.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_44,0,279,143,(int16_t)psVar15)
          ;
          winrefg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          winrefg1Cut1Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(420,280,0);
          src_45.seg = 0;
          src_45.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_45,0,279,143,(int16_t)psVar15)
          ;
          winrefg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          winrefg1Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(437,0,0);
          puVar20 = puVar19;
          captbg2Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300));
          src_46.seg = 0;
          src_46.ofs = (psVar15->aptr).seg;
          captbg2Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_46,0,319,113,(int16_t)psVar15)
          ;
          captbg2Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          captbg2Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(438,0,0);
          src_47.seg = 0;
          src_47.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_47,0,219,143,(int16_t)psVar15)
          ;
          captmg3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          captmg3Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(438,220,0);
          src_48.seg = 0;
          src_48.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_48,0,219,143,(int16_t)psVar15)
          ;
          captmg3Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          captmg3Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(439,0,0);
          src_49.seg = 0;
          src_49.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_49,0,279,143,(int16_t)psVar15)
          ;
          captfg1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          captfg1Cut1Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(439,280,0);
          src_50.seg = 0;
          src_50.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_50,0,279,143,(int16_t)psVar15)
          ;
          captfg1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          captfg1Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
L_init_assets2_2FC9:
          psVar15 = ovr_grabLbm(305,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_51.seg = 0;
          src_51.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_51,0,319,59,(int16_t)psVar15);
          l1Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l1Cut1Seg = puVar19;
          l1Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l1Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(305,320,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_52.seg = 0;
          src_52.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_52,0,319,59,(int16_t)psVar15);
          l1Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l1Cut3Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(328,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_53.seg = 0;
          src_53.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_53,0,319,59,(int16_t)psVar15);
          l4Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l4Cut1Seg = puVar19;
          l4Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l4Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(328,320,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_54.seg = 0;
          src_54.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_54,0,319,59,(int16_t)psVar15);
          l4Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l4Cut3Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(331,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_55.seg = 0;
          src_55.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_55,0,319,59,(int16_t)psVar15);
          l7Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l7Cut1Seg = puVar19;
          l7Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l7Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(331,320,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_56.seg = 0;
          src_56.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_56,0,319,59,(int16_t)psVar15);
          l7Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l7Cut3Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(307,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_57.seg = 0;
          src_57.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_57,0,319,59,(int16_t)psVar15);
          l2Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l2Cut1Seg = puVar19;
          l2Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l2Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(307,320,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_58.seg = 0;
          src_58.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_58,0,319,59,(int16_t)psVar15);
          l2Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l2Cut3Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(329,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_59.seg = 0;
          src_59.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_59,0,319,59,(int16_t)psVar15);
          l5Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l5Cut1Seg = puVar19;
          l5Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l5Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(329,320,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_60.seg = 0;
          src_60.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_60,0,319,59,(int16_t)psVar15);
          l5Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l5Cut3Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(332,0,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_61.seg = 0;
          src_61.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_61,0,319,59,(int16_t)psVar15);
          l8Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l8Cut1Seg = puVar19;
          l8Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar20,0x90));
          l8Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(332,320,0);
          puVar21 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_62.seg = 0;
          src_62.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_62,0,319,59,(int16_t)psVar15);
          l8Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l8Cut3Seg = puVar21;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(306,0,0);
          puVar20 = puVar21;
          ovr_stshUniqueColorsRemap(psVar15);
          src_63.seg = 0;
          src_63.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_63,0,319,59,(int16_t)psVar15);
          l3Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l3Cut1Seg = puVar20;
          l3Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar21,0x90));
          l3Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(306,320,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_64.seg = 0;
          src_64.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_64,0,319,59,(int16_t)psVar15);
          l3Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l3Cut3Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(330,0,0);
          puVar20 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_65.seg = 0;
          src_65.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_65,0,319,59,(int16_t)psVar15);
          l6Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l6Cut1Seg = puVar20;
          l6Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar19,0x90));
          l6Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(330,320,0);
          puVar19 = puVar20;
          ovr_stshUniqueColorsRemap(psVar15);
          src_66.seg = 0;
          src_66.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_66,0,319,59,(int16_t)psVar15);
          l6Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l6Cut3Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(333,0,0);
          puVar21 = puVar19;
          ovr_stshUniqueColorsRemap(psVar15);
          src_67.seg = 0;
          src_67.ofs = (psVar15->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_67,0,319,59,(int16_t)psVar15);
          l9Cut1Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l9Cut1Seg = puVar21;
          l9Cut2Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)(psVar15->cmap + 0x1e0),puVar19,0x90));
          l9Cut2Seg = puVar21;
          ovr_stgFreeTmp(psVar15);
          in_stack_0000fff6 = ovr_grabLbm(333,320,0);
          puVar20 = puVar21;
          ovr_stshUniqueColorsRemap(in_stack_0000fff6);
          src_68.seg = 0;
          src_68.ofs = (in_stack_0000fff6->aptr).seg;
          pfVar11 = ovr_stshRleCut((far_t *)(&in_stack_0000fff6->aptr)->ofs,src_68,0,319,59,
                                   (int16_t)in_stack_0000fff6);
          l9Cut3Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          l9Cut3Seg = puVar20;
          ovr_stgFreeTmp(in_stack_0000fff6);
        }
        ovr_stshInitAudioAssets((*(uint8_t *)((uint8_t *)&(agnt))));
        ovr_stshLoadAudioDrivers((*(uint8_t *)((uint8_t *)&(agnt))));
        ovr_stshInitSprites((*(uint8_t *)((uint8_t *)&(agnt))));
        stshInitTxtFiles((*(uint8_t *)((uint8_t *)&(agnt))));
        if ((*(uint8_t *)((uint8_t *)&(agnt))) == false) {
          sky06FliOfs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          sky06FliSeg = puVar20;
          l9Cut4Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          l9Cut4Seg = puVar20;
          ssilogoCut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          ssilogoCut1Seg = puVar20;
          ssilogoCut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          ssilogoCut2Seg = puVar20;
          youlose1Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          youlose1Cut1Seg = puVar20;
          youlose1Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          youlose1Cut2Seg = puVar20;
          cred01Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          cred01Cut1Seg = puVar20;
          cred01Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          cred01Cut2Seg = puVar20;
          cred02Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          cred02Cut1Seg = puVar20;
          cred02Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          cred02Cut2Seg = puVar20;
          cred03Cut1Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          cred03Cut1Seg = puVar20;
          cred03Cut2Ofs = (uint16_t)(ovr_stshAllocStub((far_t *)in_stack_0000fff6));
          cred03Cut2Seg = puVar20;
          cred03Cut3Ofs = ovr_stshAllocStub((far_t *)in_stack_0000fff6);
          cred03Cut3Seg = puVar20;
        }
        else {
          sky06FliOfs = ovr_stshStoreFile_2_2
                                  ((far_t *)(char *)StshNames[0x19f],(*(uint16_t *)((uint8_t *)&(StshNames[0x19f]) + 2)),0);
          sky06FliSeg = puVar20;
          l9Cut4Ofs = ovr_stshStoreFile_2_2((far_t *)"bolt12.fli",(char *)"puppetmaker" + 3,0);
          l9Cut4Seg = puVar20;
          psVar15 = ovr_grabLbm(417,0,0);
          puVar19 = puVar20;
          ssilogoCut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          src_69.seg = 0;
          src_69.ofs = (psVar15->aptr).seg;
          ssilogoCut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_69,0,319,199,(int16_t)psVar15)
          ;
          ssilogoCut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          ssilogoCut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(542,0,0);
          puVar20 = puVar19;
          youlose1Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300));
          src_70.seg = 0;
          src_70.ofs = (psVar15->aptr).seg;
          youlose1Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_70,0,319,144,(int16_t)psVar15)
          ;
          youlose1Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          youlose1Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(539,0,0);
          puVar19 = puVar20;
          cred01Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          src_71.seg = 0;
          src_71.ofs = (psVar15->aptr).seg;
          cred01Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_71,0,319,199,(int16_t)psVar15)
          ;
          cred01Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          cred01Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(540,0,0);
          puVar20 = puVar19;
          cred02Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar19,0x300));
          src_72.seg = 0;
          src_72.ofs = (psVar15->aptr).seg;
          cred02Cut1Seg = puVar20;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_72,0,319,199,(int16_t)psVar15)
          ;
          cred02Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          cred02Cut2Seg = puVar20;
          ovr_stgFreeTmp(psVar15);
          psVar15 = ovr_grabLbm(541,0,0);
          puVar19 = puVar20;
          cred03Cut1Ofs = (uint16_t)(ovr_stshWrite((uint32_t *)psVar15,puVar20,0x300));
          src_73.seg = 0;
          src_73.ofs = (psVar15->aptr).seg;
          cred03Cut1Seg = puVar19;
          pfVar11 = ovr_stshRleCut((far_t *)(&psVar15->aptr)->ofs,src_73,0,319,199,(int16_t)psVar15)
          ;
          cred03Cut2Ofs = ovr_stshStoreFile((uint8_t *)pfVar11);
          cred03Cut2Seg = puVar19;
          ovr_stgFreeTmp(psVar15);
          cred03Cut3Ofs = ovr_stshStoreFile_2_2((far_t *)"save.999",(char *)"puppetmaker" + 3,0);
          cred03Cut3Seg = puVar19;
        }
        return (uint)cred03Cut3Ofs;
      case (cte_t *)0x4:
        *count = *count + (0x44 < bVar30);
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
    if (((uVar13 != 0) || (uVar14 = ovr_randBelow(4), (uVar14 & 0xff) != 0)) &&
       ((-1 < *(char *)((int)&paVar22->targetX + 1) && (paVar22->moveState == 0x1)))) {
      uVar14 = ovr_randBelow(8);
      if ((uVar14 & 0xff) != 0) {
        return uVar14 & 0xff;
      }
    }
    paVar22->moveState = 0x1;
    uVar14 = ovr_randBelow(2);
    *(undefined1 *)((int)&paVar22->targetX + 1) = (char)uVar14;
    uVar14 = ovr_randBelow(2);
    cVar6 = (char)uVar14 * '\x02' + -1;
    uVar13 = CONCAT11((char)(uVar14 >> 8),cVar6);
    *(char *)&paVar22->targetX = cVar6;
    if ((int)agnt->x < 0x2a) {
      *(undefined1 *)&paVar22->targetX = 0xff;
      return uVar13;
    }
    if (0xb4 < (int)agnt->x) {
      *(undefined1 *)&paVar22->targetX = 1;
      return uVar13;
    }
    *(undefined1 *)((int)&paVar22->targetX + 1) = 1;
    return uVar13;
  case 2:
    break;
  case 3:
    break;
  case 4:
    uVar35 = 9;
    uVar39 = 0;
    if (paVar22->level != 0x0) {
      cVar6 = -1;
      uVar13 = ((int)((-*(int *)(CONCAT11(uVar31,uVar18) + 0x17) -
                      (int)(*(((agntG_t *)paVar22->gdata)->extents + 1))[0]) + agnt->x) >> 1) + 1;
      uVar17 = uVar13 - ((int)((agntG_t *)paVar22->gdata)->extents[1][1] -
                         (int)(*(((agntG_t *)paVar22->gdata)->extents + 1))[0] >> 1);
      goto L_OVC49_8699_0000_0121;
    }
    break;
  case 5:
    goto code_r0x00088b64;
  }
  cVar6 = '\x01';
  uVar13 = ((int)((int)(*(((agntG_t *)paVar22->gdata)->extents + 1))[0] +
                  *(int *)(CONCAT11(uVar31,uVar18) + 0x17) + agnt->x) >> 1) - 1;
  uVar17 = uVar13 + ((int)((agntG_t *)paVar22->gdata)->extents[1][1] -
                     (int)(*(((agntG_t *)paVar22->gdata)->extents + 1))[0] >> 1);
L_OVC49_8699_0000_0121:
  if ((int)uVar13 < 0) {
    uVar13 = 0;
  }
  uVar38 = uVar17;
  if ((int)uVar17 < 0) {
    uVar38 = 0;
  }
  if (0x68 < (int)uVar13) {
    uVar13 = 0x68;
  }
  if (0x68 < (int)uVar38) {
    uVar38 = 0x68;
  }
  do {
    if (uVar13 == uVar38) {
      *_pcStack0008 = '\0';
                    /* WARNING: Read-only address (ram,0x0002db84) is written */
      return uVar17 & 0xff00;
    }
    for (puStack_8 = (uint8_t *)0x0;
        (int)puStack_8 <= (int)((agntG_t *)paVar22->gdata)->extents[1][2] >> 1;
        puStack_8 = (uint8_t *)((int)puStack_8 + 1)) {
      cVar37 = -1;
      while (((cVar37 < '\x02' && (puStack_8 != (uint8_t *)0x0)) ||
             ((cVar37 == -1 && (puStack_8 == (uint8_t *)0x0))))) {
        iVar12 = CONCAT11(uVar39,uVar35) + (int)puStack_8 * (int)cVar37;
        if ((-1 < iVar12) && (iVar12 < 10)) {
          if ((*(char *)(iVar12 * 0x69 + uVar13 + 0x8fa) != '\0') &&
             (((*(byte *)(iVar12 * 0x69 + uVar13 + 0x8fa) <= AgntCount &&
               (*(char *)((uint)*(byte *)(iVar12 * 0x69 + uVar13 + 0x8fa) * 0x34 + -5) !=
                (char)(in_stack_0000fffc >> 8))) &&
              (*(char *)((uint)*(byte *)(iVar12 * 0x69 + uVar13 + 0x8fa) * 0x34 + -0x10) == '\0'))))
          {
            *_pcStack0008 = *(char *)(iVar12 * 0x69 + uVar13 + 0x8fa);
            bVar5 = ovr_agnt_compute4(pcStack0008);
            if (bVar5) {
              return CONCAT11(extraout_AH,*_pcStack0008);
            }
          }
          if (((*(char *)(iVar12 * 0x69 + uVar13 + 0x4e0) != '\0') &&
              (*(byte *)(iVar12 * 0x69 + uVar13 + 0x4e0) <= AgntCount)) &&
             ((*(char *)((uint)*(byte *)(iVar12 * 0x69 + uVar13 + 0x4e0) * 0x34 + -5) !=
               (char)(in_stack_0000fffc >> 8) &&
              (*(char *)((uint)*(byte *)(iVar12 * 0x69 + uVar13 + 0x4e0) * 0x34 + -0x10) == '\0'))))
          {
            *_pcStack0008 = *(char *)(iVar12 * 0x69 + uVar13 + 0x4e0);
            return CONCAT11((char)((uint)(iVar12 * 0x69) >> 8),*_pcStack0008);
          }
        }
        cVar37 = cVar37 + '\x02';
      }
    }
    uVar17 = (uint)cVar6;
    uVar13 = uVar13 + uVar17;
  } while( true );
L_OVC49_8699_1e09_3BDE:
  if ((int)(uint)AgntCount <= (int)uStackY_22) goto L_OVC49_8699_1e09_3BF1;
  uVar27 = *(undefined2 *)((int)uStackY_22 * 0x34 + 0x15);
  iVar12 = *(int *)((int)uStackY_22 * 0x34 + 0x13);
  in_stack_0000ffe4 =
       CONCAT11(*(undefined1 *)((int)uStackY_22 * 0x34 + 0x12),(byte)in_stack_0000ffe4);
  GGameState = 0x37;
  if (DebugVerbose != false) {
    uVar28 = 0x1000;
    printf("%d \r");
  }
  iVar23 = iVar12 + (in_stack_0000ffe4 >> 8) * 4;
  uVar18 = (undefined1)uVar28;
  uVar7 = (undefined1)((uint)uVar28 >> 8);
  psVar15 = ovr_stash_usesStExit
                      ((stg_tmp_t *)*(undefined2 *)(iVar23 + 0x58),
                       (byte)*(undefined2 *)(iVar23 + 0x5a));
  GGameState = 0x38;
  if (DebugVerbose != false) {
    uVar18 = 0x37;
    uVar7 = 0x23;
    printf("%d \r");
  }
  uVar14 = *(int *)((int)uStackY_22 * 0x34) + 0xc;
  if (*(char *)((int)uStackY_22 * 0x34 + 0x11) == '\0') {
    bVar8 = 0x3e;
    uVar32 = 0x95;
    iVar23 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
    iStackY_28 = *(int *)(iVar23 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) + 3;
  }
  else {
    bVar8 = 0xd9;
    uVar32 = 0x94;
    iVar23 = ovr_agnt_clampX(*(int *)((int)uStackY_22 * 0x34));
    uVar29 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
    iStackY_28 = *(int *)(iVar23 * 2 + 0x34c) + *(int *)((int)uStackY_22 * 0x34 + 2) +
                 (int)*(char *)((int)uVar29 + 0x52) + -0x16;
  }
  pbVar34 = (brect_t *)CONCAT11(uVar7,uVar18);
  uVar28 = 0x22ff;
  *(uint16_t *)((int)uStackY_22 * 0x34 + 0x26) = uVar14;
  *(int *)((int)uStackY_22 * 0x34 + 0x28) = iStackY_28;
  if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0') {
      GGameState = 0x32;
      pbVar34 = &bStackY_32;
      in_stack_0000ffe4 = 0x22ff;
      uVar28 = 0x22d3;
      gfx.seg = uVar14;
      gfx.ofs = (uint16_t)(psVar15->cmap + 6);
      bVar8 = bVar43;
      uVar32 = uVar42;
      ovr_blitGfxRect(gfx,uVar14,iStackY_28,pbVar34,bVar43,true);
      GGameState = 0x33;
      if ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 100) != 0) {
        pbVar34 = &bStackY_32;
        bVar8 = *(byte *)((int)uStackY_22 * 0x34 + 0x23);
        pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
        *pcVar1 = *pcVar1 + -1;
        uVar13 = bVar8 & 3;
        in_stack_0000ffe4 = 0x22d3;
        uVar28 = 0x22d3;
        gfx_00.seg = ((undefined2 *)&crossBlitType2Seg)[uVar13 * 2];
        gfx_00.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar13 * 2];
        bVar8 = bVar43;
        uVar32 = uVar42;
        ovr_blitGfxRect(gfx_00,uVar14,iStackY_28 - stack0xffdb,pbVar34,bVar43,true);
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x01') {
      uVar29 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
      if ((*(uint *)((int)uVar29 + 0x40) & 2) == 0) {
        gfx_02.seg = uVar14;
        gfx_02.ofs = (uint16_t)(psVar15->cmap + 6);
        ovr_blitGfxRect(gfx_02,uVar14,iStackY_28,&bStackY_32,bVar43,true);
        pbVar34 = &bStackY_32;
        uVar13 = *(byte *)((int)uStackY_22 * 0x34 + 0x23) & 3;
        in_stack_0000ffe4 = 0x22d3;
        uVar28 = 0x22d3;
        gfx_03.seg = ((undefined2 *)&crossBlitType2Seg)[uVar13 * 2];
        gfx_03.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar13 * 2];
        bVar8 = bVar43;
        uVar32 = uVar42;
        ovr_blitGfxRect(gfx_03,uVar14,iStackY_28 - stack0xffdb,pbVar34,bVar43,true);
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
        else {
          pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
          *pcVar1 = *pcVar1 + -1;
        }
      }
      else {
        pbVar34 = &bStackY_32;
        in_stack_0000ffe4 = 0x22ff;
        uVar28 = 0x22d3;
        gfx_01.seg = uVar14;
        gfx_01.ofs = (uint16_t)(psVar15->cmap + 6);
        bVar8 = bVar43;
        uVar32 = uVar42;
        ovr_blitGfxRect(gfx_01,uVar14,iStackY_28,pbVar34,bVar43,true);
        if ((int)(uint)*(byte *)((int)&pbVar34[2].h + 1) <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1
           ) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x24) = 0;
        }
      }
    }
    else if (*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\x02') {
      if ((char)(in_stack_0000ffe4 >> 8) == '\x12') {
        pbVar34 = &bStackY_32;
        in_stack_0000ffe4 = 0x22ff;
        uVar28 = 0x22d3;
        gfx_04.seg = uVar14;
        gfx_04.ofs = (uint16_t)(psVar15->cmap + 6);
        bVar8 = bVar43;
        uVar32 = uVar42;
        ovr_blitGfxRect(gfx_04,uVar14,iStackY_28,pbVar34,bVar43,true);
        if ((int)(uint)*(byte *)((int)&pbVar34[2].h + 1) <= *(int *)((int)uStackY_22 * 0x34 + 6) + 1
           ) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          uVar28 = 0x23d5;
          bVar8 = 0x9a;
          uVar32 = 0x99;
          ovr_ovc41_paralyzeNearbyAgents((int)uStackY_22);
        }
      }
      else {
        ovr_randBelow(0x100);
        bVar8 = 1;
        uVar32 = 0;
        cVar6 = *(char *)((int)uStackY_22 * 0x34 + 0xf);
        uVar18 = (undefined1)((uint)((int)uStackY_22 * 0x34) >> 8);
        gfx_09.seg = (uint16_t)unaff_SS;
        gfx_09.ofs = (uint16_t)&bStackY_32.h;
        uStackY_22 = (cte_t *)0x2337;
        uVar28 = 0x22d3;
        _auStackY_26 = CONCAT22(0x98d2,auStackY_26);
        in_stack_0000ffe4 = uVar14;
        ovr_gfxRlePrepare(gfx_09,uVar14,iStackY_28,&bStackY_32.x,bVar43,'\x10',cVar6);
        pbVar34 = (brect_t *)CONCAT11(uVar18,cVar6);
        if (*(char *)((int)uStackY_22 * 0x34 + 0x23) == '\0') {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0x25) = 2;
          uVar28 = 0x23d5;
          bVar8 = 0x20;
          uVar32 = 0x99;
          ovr_ovc41_paralyzeNearbyAgents((int)uStackY_22);
          pbVar34 = (brect_t *)CONCAT11(uVar18,cVar6);
        }
        else {
          pcVar1 = (char *)((int)uStackY_22 * 0x34 + 0x23);
          *pcVar1 = *pcVar1 + -1;
        }
      }
    }
  }
  else {
    bVar8 = 0xff;
    uVar32 = 0;
    cVar6 = *(char *)((int)uStackY_22 * 0x34 + 0xf);
    uVar18 = (undefined1)((uint)((int)uStackY_22 * 0x34) >> 8);
    gfx_08.seg = (uint16_t)unaff_SS;
    gfx_08.ofs = (uint16_t)&bStackY_32.h;
    uStackY_22 = (cte_t *)0x22ff;
    uVar28 = 0x22d3;
    _auStackY_26 = CONCAT22(0x95e4,auStackY_26);
    in_stack_0000ffe4 = uVar14;
    ovr_gfxRlePrepare(gfx_08,uVar14,iStackY_28,&bStackY_32.x,bVar43,'\x10',cVar6);
    pbVar34 = (brect_t *)CONCAT11(uVar18,cVar6);
  }
  if (*(char *)((int)uStackY_22 * 0x34 + 0x30) != '\0') {
    uVar32 = (undefined1)((uint)&bStackY_32 >> 8);
    uVar18 = (undefined1)uVar28;
    uVar7 = (undefined1)((uint)uVar28 >> 8);
    uVar28 = 0x22ff;
    bVar8 = (byte)uStackY_22;
    ovr_agnt_drawSpriteFrame((byte)uStackY_22,&bStackY_32,(uint16_t)unaff_SS);
    pbVar34 = (brect_t *)CONCAT11(uVar7,uVar18);
  }
  bVar30 = (byte)in_stack_0000ffe4;
  if (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 8) == 0) ||
     ((uint)*(byte *)((int)&pbVar34[2].w + 1) != *(uint *)((int)uStackY_22 * 0x34 + 6))) {
    if (((uint)*(byte *)((int)&pbVar34[2].w + 1) == *(uint *)((int)uStackY_22 * 0x34 + 6)) &&
       ((*(char *)((int)uStackY_22 * 0x34 + 0x24) == '\0' &&
        (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)))) {
      if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') {
        cVar6 = ovc49_usesFrameIndex2
                          ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                           &stack0xffe4);
        if (cVar6 == '\0') {
          if ((*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x03') ||
             (*(char *)((int)uStackY_22 * 0x34 + 0x12) == '\x0f')) {
            uVar16 = ovr_audio_panFromX((agnt_t *)
                                        CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
            ovr_play_sfxU(0x33,0,uVar16);
          }
          animBranchCode = 9;
          uVar28 = 0x22ff;
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = bVar30 - 1;
        }
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        cVar6 = ovc49_usesFrameIndex
                          ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                           &stack0xffe4);
        bVar8 = (byte)in_stack_0000ffe4;
        if (cVar6 != '\0') {
          uVar28 = 0x2389;
          uVar13 = ovr_ovc27_compute1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34))
                                      ,(in_stack_0000ffe4 & 0xff) - 1);
          if ((char)uVar13 != '\0') {
            *(char *)((int)uStackY_22 * 0x34 + 0xc) = bVar8 - 1;
            goto L_OVC49_8699_1e09_3310;
          }
        }
        animBranchCode = 10;
        uVar28 = 0x22ff;
        ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) ||
              (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05')) {
        uVar28 = 0x22ff;
        cVar6 = ovr_agnt_computeFrameExtents
                          ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                           &stack0xffe4);
        if (cVar6 == '\0') {
          animBranchCode = 0xb;
          uVar28 = 0x22ff;
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        }
        else {
          *(char *)((int)uStackY_22 * 0x34 + 0xc) = bVar30 - 1;
        }
      }
L_OVC49_8699_1e09_3310:
      bVar8 = *(char *)((int)uStackY_22 * 0x34 + 0xc) + 1;
      in_stack_0000ffe4 = (uint16_t)bVar8;
      uVar18 = (undefined1)uVar28;
      uVar7 = (undefined1)((uint)uVar28 >> 8);
      if (((bVar8 == 0) || (*(char *)((uint)bVar8 * 0x34 + -0x10) != '\0')) ||
         ((*(char *)((int)uStackY_22 * 0x34 + 0xd) != '\x06' &&
          ((0x14 < *(int *)((int)uStackY_22 * 0x34 + 2) ||
           (0x14 < *(int *)((uint)bVar8 * 0x34 + -0x32))))))) {
        animBranchCode = 0xc;
        uVar28 = 0x22ff;
        ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x01') {
        uVar28 = 0x2389;
        uVar13 = ovr_ovc27_spellNotice((int)uStackY_22);
        if ((uVar13 & 0xff) == 0) {
          animBranchCode = 0xf;
          uVar28 = 0x22ff;
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        }
      }
      else if (((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x02') ||
               (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x04')) &&
              (*(char *)((int)uStackY_22 * 0x34 + 0xe) == -1)) {
        uVar32 = 5;
        uVar35 = 0x9e;
        uVar16 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        uVar39 = (undefined1)(uVar16 >> 8);
        bVar8 = *(byte *)(CONCAT11(uVar35,uVar32) + 0x1d);
        uVar18 = 0xf8;
        uVar7 = 0x22;
        uVar28 = 0x22f8;
        ovr_play_sfxU(bVar8,0,uVar16);
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 0;
        *(char *)((int)uStackY_22 * 0x34 + 10) =
             *(char *)(CONCAT11(uVar7,uVar18) + 0x15) + (char)iStackY_28;
        if (*(char *)((int)uStackY_22 * 0x34 + 0xf) == '\0') {
          *(int *)((int)uStackY_22 * 0x34 + 8) = *(int *)(CONCAT11(uVar7,uVar18) + 0x13) + uVar14;
        }
        else {
          *(int *)((int)uStackY_22 * 0x34 + 8) = uVar14 - *(int *)(CONCAT11(uVar7,uVar18) + 0x13);
        }
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xb) =
             *(undefined1 *)((int)uStackY_22 * 0x34 + 0xf);
      }
      else if ((*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\0') &&
              (uVar29 = *(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d),
              (*(uint *)((int)uVar29 + 0x3c) & 8) == 0)) {
        uVar32 = 0x2c;
        uVar35 = 0x9f;
        uVar14 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        ovr_play_sfxU(*(byte *)(CONCAT11(uVar35,uVar32) + 0x1d),0,uVar14);
        uVar28 = 0x23d5;
        ovr_ovc41_resolveSpecialAttack_2
                  ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                   (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x03') {
        uVar13 = ovr_agnt_compute12((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                                    (agnt_t *)
                                    CONCAT13(0x17,CONCAT12(0x26,(uint)bVar8 * 0x34 + -0x34)));
        if (((char)uVar13 != '\0') &&
           ((*(uint *)((in_stack_0000ffe4 & 0xff) * 0x34 + -9) & 0x800) == 0)) {
          uVar29 = *(undefined4 *)((in_stack_0000ffe4 & 0xff) * 0x34 + -0x1d);
          if (((*(uint *)((int)uVar29 + 0x14) & 2) == 0) ||
             ((uVar14 = ovr_randBelow(2), (uVar14 & 0xff) != 0 ||
              ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
            ovr_OVC41_6a8f_01e7_entry
                      ((agnt_t *)
                       CONCAT13(0x17,CONCAT12(0x26,(in_stack_0000ffe4 & 0xff) * 0x34 + -0x34)));
            puVar3 = (uint *)((in_stack_0000ffe4 & 0xff) * 0x34 + -9);
            *puVar3 = *puVar3 | 0x800;
            uVar14 = ovr_audio_panFromX((agnt_t *)
                                        CONCAT13(0x17,CONCAT12(0x26,(in_stack_0000ffe4 & 0xff) *
                                                                    0x34 + -0x34)));
            ovr_play_sfxU(0x1b,0,uVar14);
          }
          else {
            uVar14 = ovr_audio_panFromX((agnt_t *)
                                        CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
            ovr_play_sfxU(0x1b,0,uVar14);
            ovr_OVC41_6a8f_01e7_entry
                      ((agnt_t *)
                       CONCAT13(0x17,CONCAT12(0x26,(in_stack_0000ffe4 & 0xff) * 0x34 + -0x34)));
            puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
            *puVar3 = *puVar3 | 0x800;
          }
        }
        animBranchCode = 0xd;
        uVar28 = 0x22ff;
        ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x05') {
        uVar32 = 0x21;
        uVar35 = 0xa1;
        uVar14 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        uVar28 = 0x22f8;
        ovr_play_sfxU(*(byte *)(CONCAT11(uVar35,uVar32) + 0x1d),0,uVar14);
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = 0xf5;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2e) = 1;
      }
      else if (*(char *)((int)uStackY_22 * 0x34 + 0xd) == '\x06') {
        uVar32 = 0x8f;
        uVar35 = 0xa1;
        uVar14 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        ovr_play_sfxU(*(byte *)(CONCAT11(uVar35,uVar32) + 0x1d),0,uVar14);
        uVar28 = 0x23d5;
        ovr_ovc41_resolveSpecialAttack_2
                  ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                   (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
      }
      else {
        animBranchCode = 0xe;
        uVar28 = 0x22ff;
        ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
      }
    }
  }
  else {
    uVar28 = 0x23d5;
    ovr_ovc41_resolveSpecialAttack_2
              ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
               (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
  }
  GGameState = 0x39;
  if (DebugVerbose != false) {
    uVar28 = 0x1000;
    printf("%d \r");
  }
  piVar2 = (int *)((int)uStackY_22 * 0x34 + 6);
  *piVar2 = *piVar2 + 1;
  if (*(char *)((int)uStackY_22 * 0x34 + 0xe) != -1) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0xc) == -1) {
      uVar28 = 0x22ff;
      ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
      animBranchCode = 7;
    }
    else if ((*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') ||
            (*(char *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
      uVar32 = (undefined1)uVar27;
      uVar35 = (undefined1)((uint)uVar27 >> 8);
      uVar18 = (undefined1)iVar12;
      uVar7 = (undefined1)((uint)iVar12 >> 8);
      if (*(char *)((int)uStackY_22 * 0x34 + 0x2e) == '\0') {
        bVar8 = 6;
      }
      else {
        bVar8 = *(byte *)((uint)*(byte *)((int)uStackY_22 * 0x34 + 0x2e) * 0x21 + -0x16);
      }
      uVar28 = (undefined2)(CONCAT13(uVar35,CONCAT12(uVar32,iVar12)) >> 0x10);
      piVar24 = (int *)(iVar12 + (uint)bVar8 * 4);
      if (*piVar24 == 0 && piVar24[1] == 0) {
        uVar32 = (undefined1)SprProjectiles.seg;
        uVar35 = (undefined1)(SprProjectiles.seg >> 8);
        uVar18 = (undefined1)SprProjectiles.ofs;
        uVar7 = (undefined1)(SprProjectiles.ofs >> 8);
      }
      uVar28 = (undefined2)(CONCAT13(uVar35,CONCAT12(uVar32,CONCAT11(uVar7,uVar18))) >> 0x10);
      puVar25 = (uint *)(CONCAT11(uVar7,uVar18) + (uint)bVar8 * 4);
      uVar13 = *puVar25 | puVar25[1];
      if (uVar13 == 0) {
                    /* WARNING: Subroutine does not return */
        ovr_stExit(0xf);
      }
      uVar28 = (undefined2)
               (CONCAT13((char)(uVar13 >> 8),
                         CONCAT12(*(undefined1 *)((int)uStackY_22 * 0x34 + 0xe),
                                  CONCAT11(uVar7,uVar18))) >> 0x10);
      iVar12 = CONCAT11(uVar7,uVar18) + (uint)bVar8 * 4;
      psVar15 = ovr_stash_usesStExit
                          ((stg_tmp_t *)*(undefined2 *)(iVar12 + 0x58),
                           (byte)*(undefined2 *)(iVar12 + 0x5a));
      GGameState = 0x30;
      pbVar34 = &bStackY_32;
      uVar14 = *(uint16_t *)((int)uStackY_22 * 0x34 + 8);
      uVar7 = (undefined1)uVar14;
      uVar31 = (uint8_t)(uVar14 >> 8);
      puVar20 = psVar15->cmap + 6;
      in_stack_0000ffe4 = 0x2337;
      uVar28 = 0x22d3;
      gfx_05.seg = uVar14;
      gfx_05.ofs = (uint16_t)puVar20;
      bVar8 = bVar43;
      uVar18 = uVar42;
      ovr_blitGfxRect(gfx_05,uVar14,(uint)*(byte *)((int)uStackY_22 * 0x34 + 10),pbVar34,bVar43,true
                     );
      iVar12 = CONCAT11(uVar18,bVar8);
      GGameState = 0x31;
      if ((pbVar34[2].seg & 2) == 0) {
        if (*(char *)((int)uStackY_22 * 0x34 + 0xb) == '\0') {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 + (int)*(char *)(uVar14 + 5);
        }
        else {
          piVar2 = (int *)((int)uStackY_22 * 0x34 + 8);
          *piVar2 = *piVar2 - (int)*(char *)(uVar14 + 5);
        }
        puVar20 = puVar20 + 1;
        if ((undefined1 *)(*(byte *)((int)&pbVar34[2].w + 1) + 1) == puVar20) {
          iVar12 = (int)uStackY_22 * 0x34;
          uVar18 = 0xd3;
          uVar7 = 0x22;
          uVar28 = 0x23d5;
          ovr_ovc41_specialAttack
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,iVar12)),
                     (uint)*(byte *)((int)uStackY_22 * 0x34 + 0xc));
          pbVar34 = (brect_t *)CONCAT11(uVar7,uVar18);
        }
        if ((int)puVar20 < (int)(uint)*(byte *)((int)&pbVar34[2].h + 1)) {
          *(undefined1 *)((int)uStackY_22 * 0x34 + 0xe) = (char)puVar20;
        }
        else {
          animBranchCode = 8;
          uVar28 = 0x22ff;
          ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
        }
      }
      else {
        uVar28 = 0x22ff;
        ovr_agnt_usesStExit((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)),
                            (anm_t *)CONCAT13(uVar18,CONCAT12(bVar8,pbVar34)),
                            (stg_tmp_t *)CONCAT13(uVar31,CONCAT12(uVar7,uVar14)));
      }
    }
    else {
      uVar28 = 0x2389;
      ovr_ovc27_usesBlitGfxRect((int)uStackY_22,&bStackY_32,(uint16_t)unaff_SS);
    }
  }
  uStackY_22 = (cte_t *)((int)uStackY_22 + 1);
  goto L_OVC49_8699_1e09_3BDE;
L_OVC49_8699_1e09_3BF1:
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects(&bStackY_32,(uint16_t)unaff_SS);
  GGameState = 0x2f;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  if (AgentsChanged != '\0') {
    ovr_attact_usesEntityCount();
    AgentsChanged = '\0';
  }
  cVar6 = '\0';
  cVar37 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  do {
    do {
      uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      if ((int)uStackY_22 < 0) goto L_OVC49_8699_1e09_3CF7;
    } while (((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0) ||
            (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02'));
    if (*(char *)((int)uStackY_22 * 0x34 + 0x2f) == '\0') {
      cVar37 = '\x01';
    }
    else {
      cVar6 = '\x01';
    }
  } while ((cVar6 == '\0') || (cVar37 == '\0'));
L_OVC49_8699_1e09_3CF7:
  if ((cVar37 == '\0') || (cVar6 == '\0')) {
    cVar41 = '\x01';
  }
  else {
    cVar41 = '\0';
  }
  cVar40 = '\0';
  uStackY_22 = (cte_t *)(uint)AgntCount;
  while (uStackY_22 = (cte_t *)((int)uStackY_22 - 1), -1 < (int)uStackY_22) {
    if (*(char *)((int)uStackY_22 * 0x34 + 0x25) == '\x02') {
      ovr_ovc41_removeAgent((uint)uStackY_22,0);
      AgentsChanged = '\x01';
    }
    else if ((cVar41 != '\0') && ((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0xae4) != 0)) {
      cVar40 = '\x01';
      *(undefined1 *)((int)uStackY_22 * 0x34 + 0x30) = 0;
      if ((((*(uint *)((int)uStackY_22 * 0x34 + 0x2b) & 0x800) == 0) &&
          ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) == '\0' || (cVar6 != '\0')))) &&
         ((*(char *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d) != '\0' || (cVar37 != '\0')))) {
        puVar3 = (uint *)((int)uStackY_22 * 0x34 + 0x2b);
        *puVar3 = *puVar3 & 0xf51b;
        *(undefined1 *)((int)uStackY_22 * 0x34 + 0x2f) =
             *(undefined1 *)*(undefined4 *)((int)uStackY_22 * 0x34 + 0x1d);
        ovr_ovc41_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(int)uStackY_22 * 0x34)));
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
    ovr_play_sfxU(0x3b,0,0x80);
  }
  uVar17 = EntityCount - 1;
  for (uVar13 = uVar17; -1 < (int)uVar13; uVar13 = uVar13 - 1) {
    uVar28 = (undefined2)((ulong)Entities >> 0x10);
    peVar26 = (entity_t *)Entities;
    uVar17 = (uint)peVar26[uVar13].base.animFrame;
    if ((uVar17 == 0) &&
       (uVar17 = ovr_ovc23_isCursorAt(((peVar26 + uVar13)->base).x,peVar26[uVar13].base.y),
       (char)uVar17 != '\0')) {
      uVar17 = AgntCount - 1;
      uStackY_22 = (cte_t *)uVar17;
      while ((-1 < (int)uStackY_22 &&
             (uVar17 = (int)uStackY_22 * 0x34, *(uint *)(uVar17 + 0x1b) != uVar13))) {
        uStackY_22 = (cte_t *)((int)uStackY_22 - 1);
      }
      if ((int)uStackY_22 < 0) {
        ovr_ovc15_removeEntity(uVar13);
        uVar17 = 0x2410;
        constructionDirty = 1;
      }
    }
  }
  ovr_ovc41_usesDebugVerbose();
  return uVar17;
}



/* 8699:1e09 */

/* Per-frame agent pass: updates each agent's grid cells and AI state, resolves its animation and
   sprite, and draws it (also sets BothFactions and GGameState). */

void __cdecl16far ovc49_drawAgents(void)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  undefined4 uVar5;
  far_t gfx;
  far_t gfx_00;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  bool bVar6;
  bool bVar7;
  far_t gfx_01;
  far_t gfx_02;
  bool bVar8;
  char cVar9;
  uint uVar10;
  stg_tmp_t *psVar11;
  uint16_t uVar12;
  undefined2 uVar13;
  int iVar14;
  undefined2 uVar15;
  undefined2 *puVar16;
  int iVar17;
  anm_t *paVar18;
  int *piVar19;
  uint16_t *puVar20;
  entity_t *peVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  uint16_t unaff_SS;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t gfx_08;
  far_t gfx_09;
  byte rectSeg;
  undefined1 uVar24;
  brect_t agentRect;
  int iStack_28;
  uint uStack_22;
  byte bStack_1e;
  uint8_t agntIndex;
  byte bStack_1b;
  uint uStack_1a;
  undefined4 uStack_18;
  uint8_t factionSeen;
  char cStack_13;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined4 uStack_a;
  char cStack_6;
  char cStack_5;
  char cStack_4;
  char cStack_3;
  
  rectSeg = (byte)unaff_SS;
  uVar24 = (undefined1)(unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = rectSeg;
  dst.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar24;
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
  ovr_blitLoadRleGfx(gfx,dst_00);
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)audioSaveCut2Seg;
  gfx_00.ofs = audioSaveCut2Ofs;
  (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)audioSaveCut2Seg >> 8);
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = (char)agentRect.seg;
  dst_01.ofs = 0x618c;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = (char)(agentRect.seg >> 8);
  ovr_blitLoadRleGfx(gfx_00,dst_01);
  GGameState = 0x2c;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = rectSeg;
  dst_02.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar24;
  ovr_ovc23_textBuildThfres01Lbm(dst_02);
  _fmemset(&factionSeen,unaff_SS,0);
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
    ovc49_fillGridCells(0,(agnt_t *)(uStack_22 * 0x34));
    ovc49_textLongerParalyzed
              ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),(byte)uStack_22);
    uVar13 = *(undefined2 *)(uStack_22 * 0x34);
    uVar23 = *(undefined2 *)(uStack_22 * 0x34 + 2);
    uVar10 = ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
    bStack_1b = (byte)uVar10;
    uVar22 = (undefined2)((ulong)uStack_a >> 0x10);
    puVar16 = (undefined2 *)((int)uStack_a + (uVar10 & 0xff) * 4);
    uStack_12 = (anm_t *)CONCAT22(puVar16[1],(anm_t *)*puVar16);
    uVar15 = 0x1726;
    iVar17 = (int)uStack_a + (uVar10 & 0xff) * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                         (byte)*(undefined2 *)(iVar17 + 0x5a));
    uStack_18 = (stg_tmp_t *)CONCAT22(uVar15,psVar11);
    if (*(char *)(uStack_22 * 0x34 + 4) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 4) < '\0') {
        *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) - (int)(char)psVar11->cmap[5];
      }
    }
    else {
      *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) + (int)(char)psVar11->cmap[5];
    }
    bVar8 = true;
    paVar18 = (anm_t *)uStack_12;
    uVar15 = (undefined2)((ulong)uStack_12 >> 0x10);
    if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 - paVar18->maxDy;
      }
      else {
        bVar8 = false;
      }
    }
    else {
      piVar1 = (int *)(uStack_22 * 0x34 + 2);
      *piVar1 = *piVar1 + paVar18->maxDy;
    }
    if (0x14 < *(int *)(uStack_22 * 0x34 + 2)) {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
        if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
          piVar1 = (int *)(uStack_22 * 0x34 + 2);
          *piVar1 = *piVar1 - paVar18->maxDy;
        }
      }
      else {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 + paVar18->maxDy;
      }
    }
    if ((((*(int *)(uStack_22 * 0x34) < 0) || (0xd2 < *(int *)(uStack_22 * 0x34))) ||
        (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0' &&
        (uVar10 = ovc49_compute1(*(int *)(uStack_22 * 0x34)), (char)uVar10 != '\0')))) {
      bVar6 = false;
    }
    else {
      bVar6 = true;
    }
    if ((bVar6) && (*(int *)(uStack_22 * 0x34 + 2) < 0x15)) {
      bVar7 = true;
    }
    else {
      bVar7 = false;
    }
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar17 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar17 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + -0x16;
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
         ((uint)(*(int *)(uStack_22 * 0x34 + 0x28) - *(int *)(((stg_tmp_t *)uStack_18)->cmap + 9)) <
          0x96)))))) {
      if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') &&
         (uVar10 = ovc49_compute1(*(int *)(uStack_22 * 0x34)), (char)uVar10 != '\0')) {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar23;
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
        bVar8 = false;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
      }
      else if ((bVar6) &&
              (((bVar7 || (*(char *)(uStack_22 * 0x34 + 5) < '\0')) ||
               (uVar10 = ovc49_agentIsActive((agnt_t *)
                                             CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34))),
               (uVar10 & 0xff) != 0)))) {
        iVar17 = ovc49_usesStExit((agnt_t *)(uStack_22 * 0x34));
        if ((char)iVar17 != '\0') {
          *(undefined2 *)(uStack_22 * 0x34) = uVar13;
          *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar23;
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
          bVar8 = false;
          ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x25) != '\x02') {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar23;
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
        bVar8 = false;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        ovc49_body1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
      }
    }
    else {
      *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
    }
    ovc49_fillGridCells((byte)uStack_22 + 1,(agnt_t *)(uStack_22 * 0x34));
    if ((bVar8) && (uVar13 = ovr_agnt_usesAgntSaved(uStack_22), (char)uVar13 != '\0')) {
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
    uStack_12 = (anm_t *)CONCAT22(puVar16[1],(anm_t *)*puVar16);
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar13 = 0x1726;
    uVar23 = (undefined2)((ulong)uStack_a >> 0x10);
    iVar17 = (int)uStack_a + (uint)bStack_1b * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                         (byte)*(undefined2 *)(iVar17 + 0x5a));
    uStack_18 = (stg_tmp_t *)CONCAT22(uVar13,psVar11);
    GGameState = 0x38;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    iVar17 = *(int *)(uStack_22 * 0x34) + 0xc;
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar14 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar14 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar14 = ovr_agnt_clampX(*(int *)(uStack_22 * 0x34));
      uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
      iStack_28 = *(int *)(iVar14 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) +
                  (int)*(char *)((int)uVar5 + 0x52) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x26) = iVar17;
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) {
      if (*(char *)(uStack_22 * 0x34 + 0x24) == '\0') {
        GGameState = 0x32;
        gfx_04.seg = (*(uint16_t *)((uint8_t *)&(uStack_18) + 2));
        gfx_04.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
        ovr_blitGfxRect(gfx_04,iVar17,iStack_28,&agentRect,rectSeg,true);
        GGameState = 0x33;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 100) != 0) {
          iVar14 = ((anm_t *)uStack_12)->y;
          bVar4 = *(byte *)(uStack_22 * 0x34 + 0x23);
          pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
          *pcVar2 = *pcVar2 + -1;
          uVar10 = bVar4 & 3;
          gfx_05.seg = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_05.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_05,iVar17,iStack_28 - iVar14,&agentRect,rectSeg,true);
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x01') {
        uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        if ((*(uint *)((int)uVar5 + 0x40) & 2) == 0) {
          gfx_07.seg = (*(uint16_t *)((uint8_t *)&(uStack_18) + 2));
          gfx_07.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
          ovr_blitGfxRect(gfx_07,iVar17,iStack_28,&agentRect,rectSeg,true);
          uVar10 = *(byte *)(uStack_22 * 0x34 + 0x23) & 3;
          gfx_08.seg = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          gfx_08.ofs = ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2];
          ovr_blitGfxRect(gfx_08,iVar17,iStack_28 - ((anm_t *)uStack_12)->y,&agentRect,rectSeg,true)
          ;
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          gfx_06.seg = (*(uint16_t *)((uint8_t *)&(uStack_18) + 2));
          gfx_06.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
          ovr_blitGfxRect(gfx_06,iVar17,iStack_28,&agentRect,rectSeg,true);
          if ((int)(uint)((anm_t *)uStack_12)->nframes <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x02') {
        if (bStack_1b == 0x12) {
          gfx_09.seg = (*(uint16_t *)((uint8_t *)&(uStack_18) + 2));
          gfx_09.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
          ovr_blitGfxRect(gfx_09,iVar17,iStack_28,&agentRect,rectSeg,true);
          if ((int)(uint)((anm_t *)uStack_12)->nframes <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_ovc41_paralyzeNearbyAgents(uStack_22);
          }
        }
        else {
          ovr_randBelow(0x100);
          gfx_01.seg = (uint16_t)((ulong)uStack_18 >> 0x10);
          gfx_01.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
          ovr_gfxRlePrepare(gfx_01,iVar17,iStack_28,&agentRect.x,rectSeg,'\x10',
                            *(char *)(uStack_22 * 0x34 + 0xf));
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
      gfx_03.seg = (*(uint16_t *)((uint8_t *)&(uStack_18) + 2));
      gfx_03.ofs = (uint16_t)(((stg_tmp_t *)uStack_18)->cmap + 6);
      ovr_gfxRlePrepare(gfx_03,iVar17,iStack_28,&agentRect.x,rectSeg,'\x10',
                        *(char *)(uStack_22 * 0x34 + 0xf));
    }
    if (*(char *)(uStack_22 * 0x34 + 0x30) != '\0') {
      ovr_agnt_drawSpriteFrame((byte)uStack_22,&agentRect,unaff_SS);
    }
    uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
    if (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 8) == 0) ||
       ((uint)((anm_t *)uStack_12)->eventFrame != *(uint *)(uStack_22 * 0x34 + 6))) {
      if (((uint)((anm_t *)uStack_12)->eventFrame == *(uint *)(uStack_22 * 0x34 + 6)) &&
         ((*(char *)(uStack_22 * 0x34 + 0x24) == '\0' && (*(char *)(uStack_22 * 0x34 + 0xe) == -1)))
         ) {
        if (*(char *)(uStack_22 * 0x34 + 0xd) == '\0') {
          cVar9 = ovc49_usesFrameIndex2
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),&agntIndex);
          if (cVar9 == '\0') {
            if ((*(char *)(uStack_22 * 0x34 + 0x12) == '\x03') ||
               (*(char *)(uStack_22 * 0x34 + 0x12) == '\x0f')) {
              uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
              ovr_play_sfxU(0x33,0,uVar12);
            }
            animBranchCode = 9;
            ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar9 = ovc49_usesFrameIndex
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),&agntIndex);
          if ((cVar9 == '\0') ||
             (uVar10 = ovr_ovc27_compute1((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                                          agntIndex - 1), (char)uVar10 == '\0')) {
            animBranchCode = 10;
            ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) ||
                (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05')) {
          cVar9 = ovr_agnt_computeFrameExtents
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),&agntIndex);
          if (cVar9 == '\0') {
            animBranchCode = 0xb;
            ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
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
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          uVar10 = ovr_ovc27_spellNotice(uStack_22);
          if ((uVar10 & 0xff) == 0) {
            animBranchCode = 0xf;
            ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) &&
                (*(char *)(uStack_22 * 0x34 + 0xe) == -1)) {
          uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          ovr_play_sfxU(((anm_t *)uStack_12)->sfxId,0,uVar12);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 0;
          uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
          paVar18 = (anm_t *)uStack_12;
          *(char *)(uStack_22 * 0x34 + 10) = (char)paVar18->missileDy + (char)iStack_28;
          if (*(char *)(uStack_22 * 0x34 + 0xf) == '\0') {
            *(int *)(uStack_22 * 0x34 + 8) = paVar18->missileDx + iVar17;
          }
          else {
            *(int *)(uStack_22 * 0x34 + 8) = iVar17 - paVar18->missileDx;
          }
          *(undefined1 *)(uStack_22 * 0x34 + 0xb) = *(undefined1 *)(uStack_22 * 0x34 + 0xf);
        }
        else if ((*(char *)(uStack_22 * 0x34 + 0xd) == '\0') &&
                (uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d),
                (*(uint *)((int)uVar5 + 0x3c) & 8) == 0)) {
          uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          ovr_play_sfxU(((anm_t *)uStack_12)->sfxId,0,uVar12);
          ovr_ovc41_resolveSpecialAttack_2
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x03') {
          uVar10 = ovr_agnt_compute12((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                                      (agnt_t *)
                                      CONCAT13(0x17,CONCAT12(0x26,(uint)agntIndex * 0x34 + -0x34)));
          if (((char)uVar10 != '\0') && ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) {
            uVar5 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x1d);
            if (((*(uint *)((int)uVar5 + 0x14) & 2) == 0) ||
               ((uVar12 = ovr_randBelow(2), (uVar12 & 0xff) != 0 ||
                ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
              ovr_OVC41_6a8f_01e7_entry
                        ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(uint)agntIndex * 0x34 + -0x34)));
              puVar3 = (uint *)((uint)agntIndex * 0x34 + -9);
              *puVar3 = *puVar3 | 0x800;
              uVar12 = ovr_audio_panFromX((agnt_t *)
                                          CONCAT13(0x17,CONCAT12(0x26,(uint)agntIndex * 0x34 + -0x34
                                                                )));
              ovr_play_sfxU(0x1b,0,uVar12);
            }
            else {
              uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
              ovr_play_sfxU(0x1b,0,uVar12);
              ovr_OVC41_6a8f_01e7_entry
                        ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,(uint)agntIndex * 0x34 + -0x34)));
              puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
              *puVar3 = *puVar3 | 0x800;
            }
          }
          animBranchCode = 0xd;
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05') {
          uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          ovr_play_sfxU(((anm_t *)uStack_12)->sfxId,0,uVar12);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0xf5;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 1;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x06') {
          uVar12 = ovr_audio_panFromX((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          ovr_play_sfxU(((anm_t *)uStack_12)->sfxId,0,uVar12);
          ovr_ovc41_resolveSpecialAttack_2
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else {
          animBranchCode = 0xe;
          ovr_agnt_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        }
      }
    }
    else {
      ovr_ovc41_resolveSpecialAttack_2
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
        ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        animBranchCode = 7;
      }
      else if ((*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') ||
              (*(char *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16) != '\0')) {
        uStack_1a = (uint)*(byte *)(uStack_22 * 0x34 + 0xe);
        uVar13 = (undefined2)((ulong)uStack_a >> 0x10);
        uStack_e = uStack_a;
        if (*(char *)(uStack_22 * 0x34 + 0x2e) == '\0') {
          bStack_1e = 6;
        }
        else {
          bStack_1e = *(byte *)((uint)*(byte *)(uStack_22 * 0x34 + 0x2e) * 0x21 + -0x16);
        }
        piVar19 = (int *)((int)uStack_a + (uint)bStack_1e * 4);
        if (*piVar19 == 0 && piVar19[1] == 0) {
          uStack_e = CONCAT22(SprProjectiles.seg,SprProjectiles.ofs);
        }
        uVar13 = (undefined2)((ulong)uStack_e >> 0x10);
        iVar17 = (int)uStack_e;
        puVar20 = (uint16_t *)(iVar17 + (uint)bStack_1e * 4);
        paVar18 = (anm_t *)*puVar20;
        uStack_12 = (anm_t *)CONCAT22(puVar20[1],paVar18);
        piVar19 = (int *)(iVar17 + (uint)bStack_1e * 4);
        if (*piVar19 == 0 && piVar19[1] == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(0xf);
        }
        iVar17 = iVar17 + (uint)bStack_1e * 4;
        psVar11 = ovr_stash_usesStExit
                            ((stg_tmp_t *)*(undefined2 *)(iVar17 + 0x58),
                             (byte)*(undefined2 *)(iVar17 + 0x5a));
        uStack_18 = (stg_tmp_t *)CONCAT22(paVar18,psVar11);
        GGameState = 0x30;
        gfx_02.seg = (uint16_t)paVar18;
        gfx_02.ofs = (uint16_t)(psVar11->cmap + 6);
        ovr_blitGfxRect(gfx_02,*(int16_t *)(uStack_22 * 0x34 + 8),
                        (uint)*(byte *)(uStack_22 * 0x34 + 10),&agentRect,rectSeg,true);
        GGameState = 0x31;
        uVar13 = (undefined2)((ulong)uStack_12 >> 0x10);
        if ((((anm_t *)uStack_12)->flags & 2) == 0) {
          uVar23 = (undefined2)((ulong)uStack_18 >> 0x10);
          if (*(char *)(uStack_22 * 0x34 + 0xb) == '\0') {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 + (int)(char)((stg_tmp_t *)uStack_18)->cmap[5];
          }
          else {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 - (int)(char)((stg_tmp_t *)uStack_18)->cmap[5];
          }
          uStack_1a = uStack_1a + 1;
          if (((anm_t *)uStack_12)->eventFrame + 1 == uStack_1a) {
            ovr_ovc41_specialAttack
                      ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                       (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
          }
          if ((int)uStack_1a < (int)(uint)((anm_t *)uStack_12)->nframes) {
            *(undefined1 *)(uStack_22 * 0x34 + 0xe) = (undefined1)uStack_1a;
          }
          else {
            animBranchCode = 8;
            ovr_agnt_usesAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
          }
        }
        else {
          ovr_agnt_usesStExit((agnt_t *)CONCAT22(0x1726,(agnt_t *)(uStack_22 * 0x34)),uStack_12,
                              uStack_18);
        }
      }
      else {
        ovr_ovc27_usesBlitGfxRect(uStack_22,&agentRect,unaff_SS);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects(&agentRect,unaff_SS);
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
      ovr_ovc41_removeAgent(uStack_22,0);
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
        ovr_ovc41_advanceAnimFrame((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
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
    ovr_play_sfxU(0x3b,0,0x80);
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
      peVar21 = (entity_t *)Entities;
    } while ((peVar21[uVar10].base.animFrame != 0x0) ||
            (uVar13 = ovr_ovc23_isCursorAt(((peVar21 + uVar10)->base).x,peVar21[uVar10].base.y),
            (char)uVar13 == '\0'));
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


