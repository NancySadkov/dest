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
  int iVar2;
  bool bVar3;
  int iVar4;
  agnt_t *paVar5;
  int *piVar6;
  uint unaff_DI;
  undefined2 uVar7;
  char *flag;
  undefined2 uVar8;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar7 = (undefined2)((ulong)agnt >> 0x10);
  paVar5 = (agnt_t *)agnt;
  if (((agntG_t *)paVar5->gdata)->extents[1][1] == 0) {
    *out = 0;
  }
  else {
    uVar1 = paVar5->faction;
    uVar8 = *(undefined2 *)((int)&paVar5->frames + 2);
    piVar6 = (int *)(*(int *)&paVar5->frames + (uint)paVar5->frameIndex * 4);
    iVar4 = piVar6[1];
    iVar2 = *piVar6;
    iStack_6 = (int)paVar5->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (paVar5->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*(((agntG_t *)paVar5->gdata)->extents + 1))[0] +
                        *(int *)(iVar2 + 0x17) + agnt->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)paVar5->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar5->gdata)->extents + 1))[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar2 + 0x17) -
                        (int)(*(((agntG_t *)paVar5->gdata)->extents + 1))[0]) + agnt->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)paVar5->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar5->gdata)->extents + 1))[0] >> 1);
    }
    flag = (char *)((ulong)unaff_DI << 0x10);
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
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)paVar5->gdata)->extents[1][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          uVar8 = (undefined2)((ulong)flag >> 0x10);
          flag = (char *)CONCAT22(uVar8,(char *)(int)cStack_e);
          iVar4 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar4) && (iVar4 < 10)) {
            if ((*(char *)(iVar4 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) !=
                  uVar1)) &&
                (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *out = *(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa);
              flag = (char *)CONCAT22(uVar8,(*(uint16_t *)((uint8_t *)&(out) + 2)));
              bVar3 = ovr_agnt_compute4(flag,(byte *)out);
              if (bVar3) {
                return *out;
              }
            }
            if (((*(char *)(iVar4 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *out = *(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0);
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
  int iVar2;
  bool bVar3;
  int iVar4;
  agnt_t *paVar5;
  int *piVar6;
  uint unaff_DI;
  undefined2 uVar7;
  char *flag;
  undefined2 uVar8;
  char cStack_e;
  char cStack_d;
  int iStack_c;
  int iStack_a;
  int iStack_8;
  int iStack_6;
  
  uVar7 = (undefined2)((ulong)agnt >> 0x10);
  paVar5 = (agnt_t *)agnt;
  if (((agntG_t *)paVar5->gdata)->extents[0][1] == 0) {
    *out = 0;
  }
  else {
    uVar1 = paVar5->faction;
    uVar8 = *(undefined2 *)((int)&paVar5->frames + 2);
    piVar6 = (int *)(*(int *)&paVar5->frames + (uint)paVar5->frameIndex * 4);
    iVar4 = piVar6[1];
    iVar2 = *piVar6;
    iStack_6 = (int)paVar5->y >> 1;
    if (iStack_6 < 0) {
      iStack_6 = 0;
    }
    if (9 < iStack_6) {
      iStack_6 = 9;
    }
    if (paVar5->level == 0x0) {
      cStack_d = '\x01';
      iStack_a = ((int)((int)(*((agntG_t *)paVar5->gdata)->extents)[0] + *(int *)(iVar2 + 0x17) +
                       agnt->x) >> 1) + -1;
      iStack_c = iStack_a +
                 ((int)((agntG_t *)paVar5->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)paVar5->gdata)->extents)[0] >> 1);
    }
    else {
      cStack_d = -1;
      iStack_a = ((int)((-*(int *)(iVar2 + 0x17) - (int)(*((agntG_t *)paVar5->gdata)->extents)[0]) +
                       agnt->x) >> 1) + 1;
      iStack_c = iStack_a -
                 ((int)((agntG_t *)paVar5->gdata)->extents[0][1] -
                  (int)(*((agntG_t *)paVar5->gdata)->extents)[0] >> 1);
    }
    flag = (char *)((ulong)unaff_DI << 0x10);
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
      for (iStack_8 = 0; iStack_8 <= (int)((agntG_t *)paVar5->gdata)->extents[0][2] >> 1;
          iStack_8 = iStack_8 + 1) {
        cStack_e = -1;
        while (((cStack_e < '\x02' && (iStack_8 != 0)) || ((cStack_e == -1 && (iStack_8 == 0))))) {
          uVar8 = (undefined2)((ulong)flag >> 0x10);
          flag = (char *)CONCAT22(uVar8,(char *)(int)cStack_e);
          iVar4 = iStack_6 + iStack_8 * cStack_e;
          if ((-1 < iVar4) && (iVar4 < 10)) {
            if ((*(char *)(iVar4 * 0x69 + iStack_a + 0x8fa) != '\0') &&
               (((*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -5) !=
                  uVar1)) &&
                (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *out = *(byte *)(iVar4 * 0x69 + iStack_a + 0x8fa);
              flag = (char *)CONCAT22(uVar8,(*(uint16_t *)((uint8_t *)&(out) + 2)));
              bVar3 = ovr_agnt_compute4(flag,(byte *)out);
              if (bVar3) {
                return *out;
              }
            }
            if (((*(char *)(iVar4 * 0x69 + iStack_a + 0x4e0) != '\0') &&
                (*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -5) != uVar1
                && (*(char *)((uint)*(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *out = *(byte *)(iVar4 * 0x69 + iStack_a + 0x4e0);
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
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar5;
  uint uVar4;
  int *piVar6;
  int unaff_DI;
  int *in_stack_00000004;
  int iStack_6;
  int iStack_4;
  
  piVar6 = (int *)(*(int *)((int)in_stack_00000004 + 0x13) +
                  (uint)*(byte *)(in_stack_00000004 + 9) * 4);
  iVar3 = piVar6[1];
  iVar1 = *piVar6;
  iVar2 = in_stack_00000004[1] >> 1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (7 < iVar2) {
    iVar2 = 7;
  }
  iStack_4 = *in_stack_00000004 - *(int *)(iVar1 + 0x17) >> 1;
  iStack_6 = *in_stack_00000004 + *(int *)(iVar1 + 0x17) >> 1;
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
    ovr_stExit(unaff_DI,0x1e);
  }
  uVar4 = (uint)*(byte *)((int)in_stack_00000004 + 0x11);
  if (uVar4 == 0) {
    iVar3 = 0;
    for (; bVar5 = (byte)((uint)iVar3 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x8fa) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      iVar3 = iVar2 * 0x69;
      if (*(char *)(iVar3 + iStack_4 + 0x963) != '\0') {
        return CONCAT11((char)((uint)iVar3 >> 8),1);
      }
    }
  }
  else {
    for (; bVar5 = (byte)(uVar4 >> 8), iStack_4 <= iStack_6; iStack_4 = iStack_4 + 1) {
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x4e0) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      if (*(char *)(iVar2 * 0x69 + iStack_4 + 0x549) != '\0') {
        return CONCAT11((char)((uint)(iVar2 * 0x69) >> 8),1);
      }
      uVar4 = iVar2 * 0x69;
      if (*(char *)(uVar4 + iStack_4 + 0x5b2) != '\0') {
        return CONCAT11((char)(uVar4 >> 8),1);
      }
    }
  }
  return (uint)bVar5 << 8;
}



/* 8699:0849 */

/* [R7] body shape: compute */

uint __cdecl16far ovc49_compute1(int x,...)

{
  uint in_AX;
  uint uVar1;
  int in_stack_00000004;
  
  if ((in_stack_00000004 < 0) || (0xd2 < in_stack_00000004)) {
    uVar1 = in_AX & 0xff00;
  }
  else {
    uVar1 = (uint)(*(int *)(in_stack_00000004 * 2) == 0);
  }
  return uVar1;
}



/* 8699:0874 */

/* WARNING: Variable defined which should be unmapped: text */
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
  char *pcVar10;
  char *in_DX;
  agnt_t *param_00;
  agnt_t *paVar11;
  uint16_t *unaff_SS;
  undefined1 uVar12;
  uint8_t uVar13;
  uint8_t text;
  undefined1 uStack_a9;
  uint8_t msg;
  uint8_t dirY;
  uint8_t dx;
  uint8_t agntIndex;
  uint16_t distance;
  
  paVar11 = (agnt_t *)((ulong)agnt >> 0x10);
  param_00 = (agnt_t *)agnt;
  if ((param_00->combatState == 0x0) && (param_00->animFrame == 0xff)) {
    uVar12 = SUB41(agnt,0);
    if (((param_00->flags & 0x200) != 0) &&
       (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0xc), (uVar4 & 0xff) == 0)) {
      param_00->flags = param_00->flags & 0xfdff;
      uVar8 = GSavedBlitSeg;
      pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(&text,paVar11),param_00);
      puVar6 = ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar8,in_DX),pcVar5);
      pcVar5 = ovr_stsprintf((char *)CONCAT22(0x8436,unaff_SS),
                             (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),in_DX,&msg,
                             (char)in_DX);
      ovr_uiNotify((char *)CONCAT22(uVar8,in_DX),(uint16_t)pcVar5);
      ovr_ovc41_advanceAnimFrame((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12);
      ovr_attact_usesLDIV_at_2();
    }
    if (((param_00->flags & 0x100) != 0) &&
       ((uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x40), (uVar4 & 0xff) == 0 ||
        (((((agntG_t *)param_00->gdata)->flags3 & 0x2000) != 0 &&
         (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x20), (uVar4 & 0xff) == 0)))))) {
      param_00->flags = param_00->flags & 0xfeff;
      uVar8 = GSavedBlitSeg;
      pcVar5 = ovr_agnt_statusText((agnt_t *)CONCAT22(&text,paVar11),param_00);
      puVar6 = ovr_ovc15_usesStshRealloc((char *)CONCAT22(uVar8,in_DX),pcVar5);
      pcVar5 = ovr_stsprintf((char *)CONCAT22(0x8451,unaff_SS),
                             (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),in_DX,&msg,
                             (char)in_DX);
      ovr_uiNotify((char *)CONCAT22(uVar8,in_DX),(uint16_t)pcVar5);
      *(undefined1 *)&param_00->state = 0;
      ovr_agnt_compute13((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12);
      ovr_attact_usesLDIV_at_2();
    }
    if ((param_00->flags & 0xbc0) == 0) {
      if (((*(char *)((int)&param_00->targetX + 1) < '\0') || ((int)param_00->y < 0x15)) ||
         (uVar7 = ovc49_agentIsActive(agnt), (uVar7 & 0xff) != 0)) {
        uVar8 = ovc49_agentIsActive(agnt);
        if ((char)uVar8 == '\0') {
          if ((param_00->animVariant == 0x0) ||
             (cVar2 = ovr_agnt_usesAnimFrame2
                                ((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12),
             cVar2 == '\0')) {
            if ((((param_00->animVariant == 0x0) &&
                 (cVar2 = ovr_agnt_usesAnimFrame2
                                    ((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12),
                 cVar2 != '\0')) && (param_00->moveState == 0x0)) && (param_00->animFrame == 0xff))
            {
              if ((((((agntG_t *)param_00->gdata)->flags & 1) == 0) ||
                  (iVar9 = ovr_ovc27_rollAgainstStat((agnt_t *)CONCAT22(2,paVar11),text,param_00),
                  (char)iVar9 == '\0')) ||
                 (uVar8 = ovr_agnt_acquireTarget
                                    ((agnt_t *)
                                     CONCAT13((char)((uint)&agntIndex >> 8),
                                              CONCAT12((char)&agntIndex,paVar11)),
                                     (char *)CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),param_00),
                 (char)uVar8 == '\0')) {
                if ((((((agntG_t *)param_00->gdata)->flags & 1) == 0) ||
                    ((((entity_t *)param_00->entity)->base).level < 2)) ||
                   ((iVar9 = ovr_ovc27_rollAgainstStat((agnt_t *)CONCAT22(2,paVar11),text,param_00),
                    (char)iVar9 == '\0' ||
                    (cVar2 = ovr_agnt_usesStrengthMax
                                       ((agnt_t *)CONCAT22(&agntIndex,paVar11),param_00),
                    cVar2 == '\0')))) {
                  if (((((((agntG_t *)param_00->gdata)->flags & 0x400) == 0) ||
                       (0x14 < (int)param_00->y)) ||
                      (cVar2 = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                      cVar2 == '\0')) ||
                     ((0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32) ||
                      (uVar7 = ovr_ovc27_compute2((agnt_t *)CONCAT22(agntIndex - 1,paVar11),
                                                  (int)param_00), (char)uVar7 == '\0')))) {
                    if (((int)param_00->y < 0x15) &&
                       (iVar9 = ovr_ovc27_rollAgainstStat
                                          ((agnt_t *)CONCAT22(3,paVar11),text,param_00),
                       (char)iVar9 != '\0')) {
                      cVar2 = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex));
                      if ((cVar2 == '\0') || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                        if ((((((((agntG_t *)param_00->gdata)->flags2 & 1) == 0) ||
                              (cVar2 = ovr_agnt_computeFrameExtents
                                                 ((agnt_t *)
                                                  CONCAT13((char)((uint)&agntIndex >> 8),
                                                           CONCAT12((char)&agntIndex,paVar11)),
                                                  (uint8_t *)
                                                  CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                                  param_00), cVar2 == '\0')) ||
                             (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) ||
                            (((((agntG_t *)param_00->gdata)->flags3 & 0x400) != 0 &&
                             (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x14),
                             (uVar4 & 0xff) != 0)))) ||
                           (cVar2 = ovr_agnt_compute16(agnt,(agnt_t *)
                                                            CONCAT22(0x1726,(agnt_t *)
                                                                            ((uint)agntIndex * 0x34
                                                                            + -0x34))),
                           cVar2 == '\0')) {
                          if (((((((agntG_t *)param_00->gdata)->flags2 & 0x200) == 0) ||
                               (cVar2 = ovr_agnt_computeFrameExtents
                                                  ((agnt_t *)
                                                   CONCAT13((char)((uint)&agntIndex >> 8),
                                                            CONCAT12((char)&agntIndex,paVar11)),
                                                   (uint8_t *)
                                                   CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                                   param_00), cVar2 == '\0')) ||
                              (((((agntG_t *)param_00->gdata)->flags3 & 0x400) != 0 &&
                               (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x14),
                               (uVar4 & 0xff) != 0)))) ||
                             (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) {
                            if ((((((agntG_t *)param_00->gdata)->flags3 & 1) != 0) &&
                                (cVar2 = ovr_agnt_computeFrameExtents
                                                   ((agnt_t *)
                                                    CONCAT13((char)((uint)&agntIndex >> 8),
                                                             CONCAT12((char)&agntIndex,paVar11)),
                                                    (uint8_t *)
                                                    CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                                    param_00), cVar2 != '\0')) &&
                               (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)) {
                              param_00->health = 0x2;
                              param_00->targetY = 0;
                              param_00->target = agntIndex + 0xff;
                              param_00->gindex = 0x5;
                            }
                          }
                          else {
                            param_00->health = 0x2;
                            param_00->targetY = 0;
                            param_00->target = agntIndex + 0xff;
                            param_00->gindex = 0x4;
                          }
                        }
                        else {
                          param_00->health = 0x2;
                          param_00->targetY = 0;
                          param_00->target = agntIndex + 0xff;
                          param_00->gindex = 0x2;
                        }
                      }
                      else {
                        param_00->health = 0x2;
                        param_00->targetY = 0;
                        param_00->target = agntIndex + 0xff;
                        param_00->gindex = 0x0;
                      }
                    }
                    else if ((((int)param_00->y < 0x15) &&
                             (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x20),
                             (uVar4 & 0xff) == 0)) &&
                            (((((agntG_t *)param_00->gdata)->flags & 0x4000) != 0 &&
                             ((param_00->health != 0x4 &&
                              (*(char *)((int)&(((entity_t *)param_00->entity)->base).entity + 1) !=
                               '\0')))))) {
                      param_00->health = 0x4;
                      param_00->targetY = 0;
                      iVar9 = ovr_audio_panFromX((agnt_t *)
                                                 CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12);
                      ovr_play_sfxU(0,iVar9,0x32);
                    }
                    else if (((((int)param_00->y < 0x15) &&
                              (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),8),
                              (uVar4 & 0xff) == 0)) &&
                             ((((agntG_t *)param_00->gdata)->flags2 & 0x40) != 0)) &&
                            (((param_00->health != 0x5 &&
                              (cVar2 = ovc49_usesFrameIndex
                                                 (agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                              cVar2 != '\0')) &&
                             (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                             (*(uint *)((int)uVar1 + 0x3e) & 0x80) != 0)))) {
                      iVar9 = ovr_audio_panFromX((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,0x1726))
                                                 ,param * '4');
                      ovr_play_sfxU(0,iVar9,0x1e);
                      param_00->target = agntIndex + 0xff;
                      param_00->health = 0x5;
                      param_00->targetY = 0;
                    }
                    else if ((((int)param_00->y < 0x15) &&
                             ((((agntG_t *)param_00->gdata)->flags2 & 0x100) != 0)) &&
                            ((param_00->health != 0x6 &&
                             ((((cVar2 = ovc49_usesFrameIndex
                                                   (agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                                cVar2 != '\0' &&
                                (iVar9 = (uint)agntIndex * 0x34 + -0x34,
                                uVar7 = ovr_agnt_compute12((agnt_t *)
                                                           CONCAT13((char)((uint)iVar9 >> 8),
                                                                    CONCAT12((char)iVar9,paVar11)),
                                                           (agnt_t *)
                                                           CONCAT13(uStack_a9,CONCAT12(text,0x1726))
                                                           ,param_00), (char)uVar7 != '\0')) &&
                               ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) &&
                              (uVar1 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x17),
                              (*(uint *)((int)uVar1 + 0x3c) & 4) != 0)))))) {
                      iVar9 = ovr_audio_panFromX((agnt_t *)CONCAT13(uStack_a9,CONCAT12(text,0x1726))
                                                 ,param * '4');
                      ovr_play_sfxU(0,iVar9,0x1f);
                      param_00->target = agntIndex + 0xff;
                      param_00->health = 0x6;
                      param_00->targetY = 0;
                      param_00->gindex = 0x3;
                    }
                    else if ((((((agntG_t *)param_00->gdata)->flags3 & 0x200) == 0) ||
                             (pcVar5 = (char *)(uint)param_00->strengthMax,
                             pcVar5 < (char *)(param_00->strength + 3))) ||
                            (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0x40),
                            (uVar4 & 0xff) != 0)) {
                      if (((((char)param_00->targetX == '\0') &&
                           (*(char *)((int)&param_00->targetX + 1) == '\0')) ||
                          (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),8), (uVar4 & 0xff) == 0))
                         && (param_00->health != 0x4)) {
                        uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),0xc);
                        if ((uVar4 & 0xff) == 0) {
                          if (((char)param_00->targetX == '\0') &&
                             (*(char *)((int)&param_00->targetX + 1) == '\0')) {
                            uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
                            *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
                            uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),3);
                            *(char *)((int)&param_00->targetX + 1) = (char)uVar4 + -1;
                          }
                          else {
                            *(undefined1 *)&param_00->targetX = 0;
                            *(undefined1 *)((int)&param_00->targetX + 1) = 0;
                          }
                        }
                        else {
                          uVar12 = SUB21(&distance,0);
                          bVar3 = ovr_agnt_usesAgntCount2
                                            ((agnt_t *)CONCAT22(&dx,paVar11),
                                             (uint16_t *)CONCAT22(&dirY,unaff_SS),
                                             (uint16_t *)
                                             CONCAT13((char)((uint)&distance >> 8),
                                                      CONCAT12(uVar12,unaff_SS)),
                                             (uint16_t *)CONCAT13(uStack_a9,CONCAT12(text,unaff_SS))
                                             ,param_00,uVar12);
                          if (bVar3) {
                            *(uint8_t *)((int)&param_00->targetX + 1) = dirY;
                            if ((distance < 0x6e) &&
                               ((((agntG_t *)param_00->gdata)->flags3 & 0x10) != 0)) {
                              if (distance < 0x30) {
                                if ((param_00->screenX < 0x14) || (0xbe < param_00->screenX)) {
                                  uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
                                  *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
                                  uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),3);
                                  *(char *)((int)&param_00->targetX + 1) = (char)uVar4 + -1;
                                }
                                else if (_dx == 0) {
                                  uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
                                  *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
                                }
                                else {
                                  *(uint8_t *)&param_00->targetX = -dx;
                                }
                              }
                              else {
                                if (_dx < 0) {
                                  param_00->level = 0x1;
                                }
                                else {
                                  param_00->level = 0x0;
                                }
                                *(undefined1 *)&param_00->targetX = 0;
                                *(undefined1 *)((int)&param_00->targetX + 1) = 0;
                              }
                            }
                            else if (distance < 6) {
                              if (_dx < 0) {
                                param_00->level = 0x1;
                              }
                              else {
                                param_00->level = 0x0;
                              }
                              *(undefined1 *)&param_00->targetX = 0;
                              *(undefined1 *)((int)&param_00->targetX + 1) = 0;
                            }
                            else if (_dx == 0) {
                              uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
                              *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
                            }
                            else {
                              *(uint8_t *)&param_00->targetX = dx;
                            }
                          }
                          else {
                            uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),8);
                            if ((uVar4 & 0xff) == 0) {
                              if ((char)param_00->targetX == '\0') {
                                uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
                                *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
                              }
                              else {
                                *(undefined1 *)&param_00->targetX = 0;
                              }
                            }
                            *(undefined1 *)((int)&param_00->targetX + 1) = 0;
                          }
                        }
                        if ((((char)param_00->targetX < '\x01') || (param_00->level == 0x0)) &&
                           ((-1 < (char)param_00->targetX || (param_00->level != 0x0)))) {
                          param_00->health = 0x0;
                        }
                        else {
                          param_00->health = 0x1;
                        }
                      }
                    }
                    else {
                      param_00->strength = param_00->strength + 0x3;
                      iVar9 = ovr_audio_panFromX((agnt_t *)
                                                 CONCAT13(uStack_a9,CONCAT12(text,paVar11)),uVar12);
                      ovr_play_sfxU(0,iVar9,0x4a);
                      uVar13 = param_00->strength;
                      uVar12 = 0;
                      uVar8 = GSavedBlitSeg;
                      pcVar10 = ovr_agnt_statusText((agnt_t *)CONCAT22(&text,paVar11),
                                                    (char *)(ulong)CONCAT12(uVar13,unaff_SS),
                                                    param_00);
                      puVar6 = ovr_ovc15_usesStshRealloc
                                         ((char *)CONCAT13(uVar12,CONCAT12(uVar13,pcVar5)),pcVar10);
                      pcVar10 = ovr_stsprintf((char *)CONCAT22(0x846c,unaff_SS),
                                              (char *)CONCAT22(puVar6,(char *)"puppetmaker" + 3),
                                              pcVar5,&msg);
                      ovr_uiNotify((char *)CONCAT22(uVar8,pcVar5),(uint16_t)pcVar10);
                    }
                  }
                  else {
                    param_00->health = 0x2;
                    param_00->targetY = 0;
                    param_00->target = agntIndex + 0xff;
                    param_00->gindex = 0x1;
                  }
                }
                else {
                  param_00->health = 0x3;
                  param_00->targetY = 0;
                  param_00->target = agntIndex + 0xff;
                  param_00->flags = param_00->flags | 0x18;
                  param_00->gindex = 0x0;
                }
              }
              else {
                param_00->health = 0x3;
                param_00->targetY = 0;
                param_00->target = agntIndex + 0xff;
                param_00->gindex = 0x6;
              }
            }
          }
          else if (((((((agntG_t *)param_00->gdata)->flags & 0x400) == 0) ||
                    ((0x14 < (int)param_00->y ||
                     (cVar2 = ovc49_usesFrameIndex(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                     cVar2 == '\0')))) || (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))) ||
                  (uVar7 = ovr_ovc27_compute2((agnt_t *)CONCAT22(agntIndex - 1,paVar11),
                                              (int)param_00), (char)uVar7 == '\0')) {
            if (((((int)param_00->y < 0x15) &&
                 (iVar9 = ovr_ovc27_rollAgainstStat((agnt_t *)CONCAT22(3,paVar11),text,param_00),
                 (char)iVar9 != '\0')) &&
                (cVar2 = ovc49_usesFrameIndex2(agnt,(byte *)CONCAT22(unaff_SS,&agntIndex)),
                cVar2 != '\0')) && (*(int *)((uint)agntIndex * 0x34 + -0x32) < 0x15)) {
              param_00->health = 0x2;
              param_00->targetY = 0;
              param_00->target = agntIndex + 0xff;
              param_00->gindex = 0x0;
            }
            else if ((((((agntG_t *)param_00->gdata)->flags2 & 0x200) == 0) ||
                     (0x14 < (int)param_00->y)) ||
                    ((cVar2 = ovr_agnt_computeFrameExtents
                                        ((agnt_t *)
                                         CONCAT13((char)((uint)&agntIndex >> 8),
                                                  CONCAT12((char)&agntIndex,paVar11)),
                                         (uint8_t *)CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                         param_00), cVar2 == '\0' ||
                     (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
              if ((((((agntG_t *)param_00->gdata)->flags3 & 1) == 0) || (0x14 < (int)param_00->y))
                 || ((cVar2 = ovr_agnt_computeFrameExtents
                                        ((agnt_t *)
                                         CONCAT13((char)((uint)&agntIndex >> 8),
                                                  CONCAT12((char)&agntIndex,paVar11)),
                                         (uint8_t *)CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                         param_00), cVar2 == '\0' ||
                     (0x14 < *(int *)((uint)agntIndex * 0x34 + -0x32))))) {
                if (((('\0' < (char)param_00->targetX) && (0xaa < (int)agnt->x)) ||
                    (((char)param_00->targetX < '\0' && ((int)agnt->x < 0x34)))) &&
                   (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),8), (uVar4 & 0xff) == 0)) {
                  uVar12 = SUB21(&distance,0);
                  bVar3 = ovr_agnt_usesAgntCount2
                                    ((agnt_t *)CONCAT22(&dx,paVar11),
                                     (uint16_t *)CONCAT22(&dirY,unaff_SS),
                                     (uint16_t *)
                                     CONCAT13((char)((uint)&distance >> 8),CONCAT12(uVar12,unaff_SS)
                                             ),
                                     (uint16_t *)CONCAT13(uStack_a9,CONCAT12(text,unaff_SS)),
                                     param_00,uVar12);
                  if (bVar3) {
                    *(uint8_t *)((int)&param_00->targetX + 1) = dirY;
                  }
                  else {
                    *(undefined1 *)((int)&param_00->targetX + 1) = 0;
                  }
                  *(char *)&param_00->targetX = -(char)param_00->targetX;
                  *(undefined1 *)((uint)param * 0x34 + 0x10) = 1;
                  param_00->targetY = 0;
                }
              }
              else {
                param_00->health = 0x2;
                param_00->targetY = 0;
                param_00->target = agntIndex + 0xff;
                param_00->gindex = 0x5;
              }
            }
            else {
              param_00->health = 0x2;
              param_00->targetY = 0;
              param_00->target = agntIndex + 0xff;
              param_00->gindex = 0x4;
            }
          }
          else {
            param_00->health = 0x2;
            param_00->targetY = 0;
            param_00->target = agntIndex + 0xff;
            param_00->gindex = 0x1;
          }
        }
        else if ((param_00->moveState != 0x2) &&
                ((((*(char *)((int)&param_00->targetX + 1) == '\0' &&
                   ((char)param_00->targetX == '\0')) &&
                  (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),4), (uVar4 & 0xff) == 0)) ||
                 (((*(char *)((int)&param_00->targetX + 1) < '\0' || (param_00->moveState != 0x1))
                  || (uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),8), (uVar4 & 0xff) == 0)))))) {
          param_00->moveState = 0x1;
          uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
          *(undefined1 *)((int)&param_00->targetX + 1) = (char)uVar4;
          uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),2);
          *(char *)&param_00->targetX = (char)uVar4 * '\x02' + -1;
          if ((int)agnt->x < 0x2a) {
            *(undefined1 *)&param_00->targetX = 0xff;
          }
          else if ((int)agnt->x < 0xb5) {
            *(undefined1 *)((int)&param_00->targetX + 1) = 1;
          }
          else {
            *(undefined1 *)&param_00->targetX = 1;
          }
        }
      }
      else {
        *(undefined1 *)((int)&param_00->targetX + 1) = 0xff;
        if ((char)param_00->targetX == '\0') {
          uVar4 = ovr_randBelow(CONCAT11(uStack_a9,text),3);
          *(char *)&param_00->targetX = (char)uVar4 + -1;
        }
      }
    }
    else {
      *(undefined1 *)&param_00->targetX = 0;
      *(undefined1 *)((int)&param_00->targetX + 1) = 0;
      param_00->health = 0x0;
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
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  uint16_t unaff_DI;
  undefined1 in_stack_00000004;
  int iStack_4;
  
  piVar5 = (int *)(*(int *)((int)count + 0x13) + (uint)*(byte *)(count + 9) * 4);
  iVar1 = piVar5[1];
  iVar2 = *piVar5;
  iVar3 = *count - *(int *)(iVar2 + 0x17) >> 1;
  iStack_4 = *count + *(int *)(iVar2 + 0x17) >> 1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iStack_4 < 0) {
    iStack_4 = 0;
  }
  if (0x68 < iVar3) {
    iVar3 = 0x68;
  }
  if (0x68 < iStack_4) {
    iStack_4 = 0x68;
  }
  if (*(char *)((int)count + 0x11) == '\0') {
    _fmemset((void *)(ulong)CONCAT12(in_stack_00000004,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar3) + 1,unaff_DI);
    pvVar4 = _fmemset((void *)(ulong)CONCAT12(in_stack_00000004,(int)&AgntAnms[0x75].halfWidth + 1),
                      (iStack_4 - iVar3) + 1,unaff_DI);
  }
  else {
    _fmemset((void *)(ulong)CONCAT12(in_stack_00000004,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar3) + 1,unaff_DI);
    _fmemset((void *)(ulong)CONCAT12(in_stack_00000004,(int)&AgntAnms[0x75].halfWidth + 1),
             (iStack_4 - iVar3) + 1,unaff_DI);
    pvVar4 = _fmemset((void *)(ulong)CONCAT12(in_stack_00000004,(int)&AgntAnms[0x75].halfWidth + 1),
                      (iStack_4 - iVar3) + 1,unaff_DI);
  }
  return pvVar4;
}



/* 8699:18c4 */
/* DECOMPILATION FAILED: 
Low-level Error: Unlinked join address */
void ovc49_body1(void) { /* failed */ }

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
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  far_t gfx_05;
  far_t gfx_06;
  far_t gfx_07;
  far_t dst;
  far_t dst_00;
  far_t dst_01;
  far_t dst_02;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  uint uVar10;
  stg_tmp_t *psVar11;
  uint16_t uVar12;
  undefined2 uVar13;
  uint16_t uVar14;
  undefined2 uVar15;
  undefined2 *puVar16;
  int iVar17;
  int *piVar18;
  uint16_t *puVar19;
  uint *puVar20;
  entity_t *peVar21;
  uint16_t unaff_SI;
  undefined2 unaff_DI;
  undefined2 uVar22;
  undefined2 uVar23;
  int *unaff_SS;
  far_t gfx_08;
  far_t gfx_09;
  undefined1 uVar24;
  undefined1 uVar25;
  undefined1 uVar26;
  undefined1 uVar27;
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
  
  uVar26 = (undefined1)unaff_DI;
  uVar27 = (undefined1)((uint)unaff_DI >> 8);
  uVar24 = SUB21(unaff_SS,0);
  uVar25 = (undefined1)((uint)unaff_SS >> 8);
  (*(uint8_t *)((uint8_t *)&(dst.seg))) = uVar24;
  dst.ofs = (uint16_t)&agentRect;
  (*(uint8_t *)((uint8_t *)&(dst.seg) + 1)) = uVar25;
  F_SCOPY(far_from_u32((uint32_t)(0x2410842c)),dst);
  AgentsChanged = '\0';
  agentRect.seg = GSavedBlitSeg;
  GGameState = 0x2b;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  (*(uint8_t *)((uint8_t *)&(gfx_06.seg))) = 0xcc;
  gfx_06.ofs = audioSaveCut1Seg;
  (*(uint8_t *)((uint8_t *)&(gfx_06.seg) + 1)) = 8;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg))) = uVar26;
  dst_00.ofs = agentRect.seg;
  (*(uint8_t *)((uint8_t *)&(dst_00.seg) + 1)) = uVar27;
  ovr_blitLoadRleGfx(gfx_06,dst_00,(char)audioSaveCut1Ofs,(char)agentRect.seg);
  (*(uint8_t *)((uint8_t *)&(gfx_07.seg))) = 0x8c;
  gfx_07.ofs = audioSaveCut2Seg;
  (*(uint8_t *)((uint8_t *)&(gfx_07.seg) + 1)) = 0x61;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg))) = uVar26;
  dst_01.ofs = agentRect.seg;
  (*(uint8_t *)((uint8_t *)&(dst_01.seg) + 1)) = uVar27;
  ovr_blitLoadRleGfx(gfx_07,dst_01,(char)audioSaveCut2Ofs,(char)agentRect.seg);
  GGameState = 0x2c;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg))) = uVar26;
  dst_02.ofs = (uint16_t)unaff_SS;
  (*(uint8_t *)((uint8_t *)&(dst_02.seg) + 1)) = uVar27;
  ovr_ovc23_textBuildThfres01Lbm(dst_02,(char)&agentRect);
  _fmemset((void *)ZEXT24(unaff_SS),2,CONCAT11(uVar27,uVar26));
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
    ovc49_fillGridCells((byte)(uStack_22 * 0x34),(agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                        0,0x26);
    ovc49_textLongerParalyzed
              ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),(byte)uStack_22);
    uVar13 = *(undefined2 *)(uStack_22 * 0x34);
    uVar23 = *(undefined2 *)(uStack_22 * 0x34 + 2);
    uVar10 = ovc49_body1((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34)
                        );
    bStack_1b = (byte)uVar10;
    uVar22 = (undefined2)((ulong)uStack_a >> 0x10);
    puVar16 = (undefined2 *)((int)uStack_a + (uVar10 & 0xff) * 4);
    _uStack_12 = CONCAT22(puVar16[1],*puVar16);
    uVar15 = 0x1726;
    iVar17 = (int)uStack_a + (uVar10 & 0xff) * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)
                         CONCAT13((char)(uStack_22 * 0x34 >> 8),
                                  CONCAT12(*(undefined1 *)(uStack_22 * 0x34 + 6),
                                           *(undefined2 *)(iVar17 + 0x5a))),
                         (char)*(undefined2 *)(iVar17 + 0x58));
    _psStack_18 = (stg_tmp_t *)CONCAT22(uVar15,psVar11);
    if (*(char *)(uStack_22 * 0x34 + 4) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 4) < '\0') {
        *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) - (int)(char)psVar11->cmap[5];
      }
    }
    else {
      *(int *)(uStack_22 * 0x34) = *(int *)(uStack_22 * 0x34) + (int)(char)psVar11->cmap[5];
    }
    bVar8 = true;
    iVar17 = (int)_uStack_12;
    uVar15 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (*(char *)(uStack_22 * 0x34 + 5) < '\x01') {
      if (*(char *)(uStack_22 * 0x34 + 5) < '\0') {
        piVar1 = (int *)(uStack_22 * 0x34 + 2);
        *piVar1 = *piVar1 - *(int *)(iVar17 + 0x11);
      }
      else {
        bVar8 = false;
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
        (uVar10 = ovc49_compute1(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34)),
        (char)uVar10 != '\0')))) {
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
      iVar17 = ovr_agnt_clampX(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar17 = ovr_agnt_clampX(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + -0x16;
    }
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(char *)(uStack_22 * 0x34 + 0x10) == '\x05') && (*(char *)(uStack_22 * 0x34 + 0xc) != -1))
    {
      ovr_ovc41_usesXOfs(CONCAT11(uVar27,uVar26),(byte)uStack_22);
    }
    uVar15 = ovc49_agentIsActive((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
    if ((((char)uVar15 == '\0') || (*(int *)(uStack_22 * 0x34 + 2) < 0)) ||
       ((-1 < *(int *)(uStack_22 * 0x34) &&
        ((*(int *)(uStack_22 * 0x34) < 0xd3 &&
         ((uint)(*(int *)(uStack_22 * 0x34 + 0x28) - *(int *)(((stg_tmp_t *)_psStack_18)->cmap + 9))
          < 0x96)))))) {
      if ((*(char *)(uStack_22 * 0x34 + 0x11) == '\0') &&
         (uVar10 = ovc49_compute1(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34)),
         (char)uVar10 != '\0')) {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar23;
        if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
          uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),3);
          *(char *)(uStack_22 * 0x34 + 4) = (char)uVar12 + -1;
        }
        else {
          *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
        }
        uVar13 = ovc49_agentIsActive((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)));
        if ((char)uVar13 == '\0') {
          uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar12 + -1;
        }
        else {
          uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),2);
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
        ovc49_body1((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
      }
      else if ((bVar6) &&
              (((bVar7 || (*(char *)(uStack_22 * 0x34 + 5) < '\0')) ||
               (uVar10 = ovc49_agentIsActive((agnt_t *)
                                             CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34))),
               (uVar10 & 0xff) != 0)))) {
        iVar17 = ovc49_usesStExit((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                  (char)(uStack_22 * 0x34));
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
            uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),2);
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
          ovc49_body1((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x25) != '\x02') {
        *(undefined2 *)(uStack_22 * 0x34) = uVar13;
        *(undefined2 *)(uStack_22 * 0x34 + 2) = uVar23;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0xbc0) == 0) {
          if (*(char *)(uStack_22 * 0x34 + 4) == '\0') {
            uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),2);
            *(char *)(uStack_22 * 0x34 + 4) = (char)uVar12 * '\x02' + -1;
          }
          else {
            *(char *)(uStack_22 * 0x34 + 4) = -*(char *)(uStack_22 * 0x34 + 4);
          }
          uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),3);
          *(char *)(uStack_22 * 0x34 + 5) = (char)uVar12 + -1;
        }
        if ((('\0' < *(char *)(uStack_22 * 0x34 + 4)) && (*(char *)(uStack_22 * 0x34 + 0xf) != '\0')
            ) || ((*(char *)(uStack_22 * 0x34 + 4) < '\0' &&
                  (*(char *)(uStack_22 * 0x34 + 0xf) == '\0')))) {
          *(undefined1 *)(uStack_22 * 0x34 + 0x10) = 1;
        }
        bVar8 = false;
        *(undefined2 *)(uStack_22 * 0x34 + 6) = 0;
        ovc49_body1((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
      }
    }
    else {
      *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
    }
    ovc49_fillGridCells((byte)(uStack_22 * 0x34),(agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                        (byte)uStack_22 + 1,0x26);
    if ((bVar8) &&
       (uVar13 = ovr_agnt_usesAgntSaved(CONCAT11(uVar27,uVar26),(byte)uStack_22),
       (char)uVar13 != '\0')) {
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
    _uStack_12 = CONCAT22(puVar16[1],*puVar16);
    GGameState = 0x37;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar13 = 0x1726;
    uVar23 = (undefined2)((ulong)uStack_a >> 0x10);
    iVar17 = (int)uStack_a + (uint)bStack_1b * 4;
    psVar11 = ovr_stash_usesStExit
                        ((stg_tmp_t *)
                         CONCAT13((char)(uStack_22 * 0x34 >> 8),
                                  CONCAT12(*(undefined1 *)(uStack_22 * 0x34 + 6),
                                           *(undefined2 *)(iVar17 + 0x5a))),
                         (char)*(undefined2 *)(iVar17 + 0x58));
    _psStack_18 = (stg_tmp_t *)CONCAT22(uVar13,psVar11);
    GGameState = 0x38;
    if (DebugVerbose != false) {
      printf("%d \r");
    }
    uVar12 = *(int *)(uStack_22 * 0x34) + 0xc;
    if (*(char *)(uStack_22 * 0x34 + 0x11) == '\0') {
      iVar17 = ovr_agnt_clampX(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34));
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) + 3;
    }
    else {
      iVar17 = ovr_agnt_clampX(CONCAT11(uVar27,uVar26),(char)*(undefined2 *)(uStack_22 * 0x34));
      uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
      iStack_28 = *(int *)(iVar17 * 2 + 0x34c) + *(int *)(uStack_22 * 0x34 + 2) +
                  (int)*(char *)((int)uVar5 + 0x52) + -0x16;
    }
    *(uint16_t *)(uStack_22 * 0x34 + 0x26) = uVar12;
    *(int *)(uStack_22 * 0x34 + 0x28) = iStack_28;
    if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0) {
      if (*(char *)(uStack_22 * 0x34 + 0x24) == '\0') {
        GGameState = 0x32;
        gfx.seg = uVar12;
        gfx.ofs = uStack_16;
        ovr_blitGfxRect(gfx,iStack_28,(int16_t)&agentRect,psStack_18->cmap + 6,(uint8_t)&agentRect);
        GGameState = 0x33;
        if ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 100) != 0) {
          iVar17 = *(int *)((int)_uStack_12 + 0xd);
          bVar4 = *(byte *)(uStack_22 * 0x34 + 0x23);
          pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
          *pcVar2 = *pcVar2 + -1;
          uVar10 = bVar4 & 3;
          gfx_00.seg = uVar12;
          gfx_00.ofs = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          ovr_blitGfxRect(gfx_00,iStack_28 - iVar17,(int16_t)&agentRect,
                          ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2],(uint8_t)&agentRect);
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x01') {
        uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d);
        if ((*(uint *)((int)uVar5 + 0x40) & 2) == 0) {
          gfx_02.seg = uVar12;
          gfx_02.ofs = uStack_16;
          ovr_blitGfxRect(gfx_02,iStack_28,(int16_t)&agentRect,psStack_18->cmap + 6,
                          (uint8_t)&agentRect);
          uVar10 = *(byte *)(uStack_22 * 0x34 + 0x23) & 3;
          gfx_03.seg = uVar12;
          gfx_03.ofs = ((undefined2 *)&crossBlitType2Seg)[uVar10 * 2];
          ovr_blitGfxRect(gfx_03,iStack_28 - *(int *)((int)_uStack_12 + 0xd),(int16_t)&agentRect,
                          ((undefined2 *)&crossBlitType2Ofs)[uVar10 * 2],(uint8_t)&agentRect);
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
        else {
          gfx_01.seg = uVar12;
          gfx_01.ofs = uStack_16;
          ovr_blitGfxRect(gfx_01,iStack_28,(int16_t)&agentRect,psStack_18->cmap + 6,
                          (uint8_t)&agentRect);
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x24) = 0;
          }
        }
      }
      else if (*(char *)(uStack_22 * 0x34 + 0x24) == '\x02') {
        if (bStack_1b == 0x12) {
          gfx_04.seg = uVar12;
          gfx_04.ofs = uStack_16;
          ovr_blitGfxRect(gfx_04,iStack_28,(int16_t)&agentRect,psStack_18->cmap + 6,
                          (uint8_t)&agentRect);
          if ((int)(uint)*(byte *)((int)_uStack_12 + 0x1b) <= *(int *)(uStack_22 * 0x34 + 6) + 1) {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_ovc41_paralyzeNearbyAgents(CONCAT11(uVar27,uVar26),(byte)uStack_22);
          }
        }
        else {
          uVar14 = ovr_randBelow(CONCAT11(uVar27,uVar26),0);
          cVar9 = *(char *)(uStack_22 * 0x34 + 0xf);
          gfx_09.seg = uVar12;
          gfx_09.ofs = uStack_16;
          ovr_gfxRlePrepare(gfx_09,iStack_28,(int)&agentRect,(int *)CONCAT22(0x10,unaff_SS),cVar9,
                            '\x01',psStack_18->cmap + 6,cVar9,1,
                            *(char *)(uStack_22 * 0x34 + 0x23) * '\x19',(char)uVar14);
          if (*(char *)(uStack_22 * 0x34 + 0x23) == '\0') {
            *(undefined1 *)(uStack_22 * 0x34 + 0x25) = 2;
            ovr_ovc41_paralyzeNearbyAgents(CONCAT11(uVar27,uVar26),(byte)uStack_22);
          }
          else {
            pcVar2 = (char *)(uStack_22 * 0x34 + 0x23);
            *pcVar2 = *pcVar2 + -1;
          }
        }
      }
    }
    else {
      cVar9 = *(char *)(uStack_22 * 0x34 + 0xf);
      gfx_08.seg = uVar12;
      gfx_08.ofs = uStack_16;
      ovr_gfxRlePrepare(gfx_08,iStack_28,(int)&agentRect,(int *)CONCAT22(0x10,unaff_SS),cVar9,-1,
                        psStack_18->cmap + 6,cVar9,0xff,0,0);
    }
    if (*(char *)(uStack_22 * 0x34 + 0x30) != '\0') {
      ovr_agnt_drawSpriteFrame((byte)&agentRect,(byte)uStack_22);
    }
    uVar13 = (undefined2)((ulong)_uStack_12 >> 0x10);
    if (((*(uint *)(uStack_22 * 0x34 + 0x2b) & 8) == 0) ||
       ((uint)*(byte *)((int)_uStack_12 + 0x19) != *(uint *)(uStack_22 * 0x34 + 6))) {
      if (((uint)*(byte *)((int)_uStack_12 + 0x19) == *(uint *)(uStack_22 * 0x34 + 6)) &&
         ((*(char *)(uStack_22 * 0x34 + 0x24) == '\0' && (*(char *)(uStack_22 * 0x34 + 0xe) == -1)))
         ) {
        if (*(char *)(uStack_22 * 0x34 + 0xd) == '\0') {
          cVar9 = ovc49_usesFrameIndex2
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                             (byte *)CONCAT13(uVar25,CONCAT12(uVar24,&agntIndex)));
          if (cVar9 == '\0') {
            if ((*(char *)(uStack_22 * 0x34 + 0x12) == '\x03') ||
               (*(char *)(uStack_22 * 0x34 + 0x12) == '\x0f')) {
              iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                          (char)(uStack_22 * 0x34));
              ovr_play_sfxU(0,iVar17,0x33,(char)iVar17);
            }
            animBranchCode = 9;
            ovr_agnt_advanceAnimFrame
                      ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          cVar9 = ovc49_usesFrameIndex
                            ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                             (byte *)CONCAT13(uVar25,CONCAT12(uVar24,&agntIndex)));
          if ((cVar9 == '\0') ||
             (uVar10 = ovr_ovc27_compute1((agnt_t *)
                                          CONCAT13((char)(agntIndex - 1 >> 8),
                                                   CONCAT12((char)(agntIndex - 1),0x1726)),
                                          (char)(uStack_22 * 0x34)), (char)uVar10 == '\0')) {
            animBranchCode = 10;
            ovr_agnt_advanceAnimFrame
                      ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
          }
          else {
            *(char *)(uStack_22 * 0x34 + 0xc) = agntIndex + 0xff;
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) ||
                (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05')) {
          cVar9 = ovr_agnt_computeFrameExtents
                            ((agnt_t *)
                             CONCAT13((char)((uint)&agntIndex >> 8),
                                      CONCAT12((char)&agntIndex,0x1726)),(char)(uStack_22 * 0x34));
          if (cVar9 == '\0') {
            animBranchCode = 0xb;
            ovr_agnt_advanceAnimFrame
                      ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
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
          ovr_agnt_advanceAnimFrame
                    ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x01') {
          uVar10 = ovr_ovc27_spellNotice(CONCAT11(uVar27,uVar26),(byte)uStack_22);
          if ((uVar10 & 0xff) == 0) {
            animBranchCode = 0xf;
            ovr_agnt_advanceAnimFrame
                      ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
          }
        }
        else if (((*(char *)(uStack_22 * 0x34 + 0xd) == '\x02') ||
                 (*(char *)(uStack_22 * 0x34 + 0xd) == '\x04')) &&
                (*(char *)(uStack_22 * 0x34 + 0xe) == -1)) {
          iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                      (char)(uStack_22 * 0x34));
          ovr_play_sfxU(0,iVar17,*(undefined1 *)((int)_uStack_12 + 0x1d),(char)iVar17);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 0;
          uVar13 = (undefined2)((ulong)_uStack_12 >> 0x10);
          iVar17 = (int)_uStack_12;
          *(char *)(uStack_22 * 0x34 + 10) = *(char *)(iVar17 + 0x15) + (char)iStack_28;
          if (*(char *)(uStack_22 * 0x34 + 0xf) == '\0') {
            *(int *)(uStack_22 * 0x34 + 8) = *(int *)(iVar17 + 0x13) + uVar12;
          }
          else {
            *(int *)(uStack_22 * 0x34 + 8) = uVar12 - *(int *)(iVar17 + 0x13);
          }
          *(undefined1 *)(uStack_22 * 0x34 + 0xb) = *(undefined1 *)(uStack_22 * 0x34 + 0xf);
        }
        else if ((*(char *)(uStack_22 * 0x34 + 0xd) == '\0') &&
                (uVar5 = *(undefined4 *)(uStack_22 * 0x34 + 0x1d),
                (*(uint *)((int)uVar5 + 0x3c) & 8) == 0)) {
          iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                      (char)(uStack_22 * 0x34));
          ovr_play_sfxU(0,iVar17,*(undefined1 *)((int)_uStack_12 + 0x1d),(char)iVar17);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x03') {
          iVar17 = (uint)agntIndex * 0x34 + -0x34;
          uVar10 = ovr_agnt_compute12((agnt_t *)
                                      CONCAT13((char)((uint)iVar17 >> 8),
                                               CONCAT12((char)iVar17,0x1726)),
                                      (agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                      (char)(uStack_22 * 0x34),0x26);
          if (((char)uVar10 != '\0') && ((*(uint *)((uint)agntIndex * 0x34 + -9) & 0x800) == 0)) {
            uVar5 = *(undefined4 *)((uint)agntIndex * 0x34 + -0x1d);
            if (((*(uint *)((int)uVar5 + 0x14) & 2) == 0) ||
               ((uVar12 = ovr_randBelow(CONCAT11(uVar27,uVar26),2), (uVar12 & 0xff) != 0 ||
                ((*(uint *)(uStack_22 * 0x34 + 0x2b) & 0x800) == 0)))) {
              ovr_OVC41_6a8f_01e7_entry
                        ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),agntIndex * '4' + -0x34)
              ;
              puVar3 = (uint *)((uint)agntIndex * 0x34 + -9);
              *puVar3 = *puVar3 | 0x800;
              iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                          agntIndex * '4' + -0x34);
              ovr_play_sfxU(0,iVar17,0x1b,(char)iVar17);
            }
            else {
              iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                          (char)(uStack_22 * 0x34));
              ovr_play_sfxU(0,iVar17,0x1b,(char)iVar17);
              ovr_OVC41_6a8f_01e7_entry
                        ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),agntIndex * '4' + -0x34)
              ;
              puVar3 = (uint *)(uStack_22 * 0x34 + 0x2b);
              *puVar3 = *puVar3 | 0x800;
            }
          }
          animBranchCode = 0xd;
          ovr_agnt_advanceAnimFrame
                    ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x05') {
          iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                      (char)(uStack_22 * 0x34));
          ovr_play_sfxU(0,iVar17,*(undefined1 *)((int)_uStack_12 + 0x1d),(char)iVar17);
          *(undefined1 *)(uStack_22 * 0x34 + 0xe) = 0xf5;
          *(undefined1 *)(uStack_22 * 0x34 + 0x2e) = 1;
        }
        else if (*(char *)(uStack_22 * 0x34 + 0xd) == '\x06') {
          iVar17 = ovr_audio_panFromX((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),
                                      (char)(uStack_22 * 0x34));
          ovr_play_sfxU(0,iVar17,*(undefined1 *)((int)_uStack_12 + 0x1d),(char)iVar17);
          ovr_ovc41_resolveSpecialAttack
                    ((agnt_t *)CONCAT13(0x17,CONCAT12(0x26,uStack_22 * 0x34)),
                     (uint)*(byte *)(uStack_22 * 0x34 + 0xc));
        }
        else {
          animBranchCode = 0xe;
          ovr_agnt_advanceAnimFrame
                    ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
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
        ovr_agnt_usesAnimFrame
                  ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
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
        _uStack_12 = CONCAT22(puVar19[1],uVar12);
        puVar20 = (uint *)(iVar17 + (uint)bStack_1e * 4);
        uVar10 = *puVar20 | puVar20[1];
        if (uVar10 == 0) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(CONCAT11(uVar27,uVar26),0xf);
        }
        iVar17 = iVar17 + (uint)bStack_1e * 4;
        psVar11 = ovr_stash_usesStExit
                            ((stg_tmp_t *)
                             CONCAT13((char)(uVar10 >> 8),
                                      CONCAT12(bVar4,*(undefined2 *)(iVar17 + 0x5a))),
                             (char)*(undefined2 *)(iVar17 + 0x58));
        _psStack_18 = (stg_tmp_t *)CONCAT22(uVar12,psVar11);
        GGameState = 0x30;
        gfx_05.seg = *(uint16_t *)(uStack_22 * 0x34 + 8);
        gfx_05.ofs = uVar12;
        ovr_blitGfxRect(gfx_05,(uint)*(byte *)(uStack_22 * 0x34 + 10),(int16_t)&agentRect,
                        psVar11->cmap + 6,(uint8_t)&agentRect);
        GGameState = 0x31;
        uVar13 = (undefined2)((ulong)_uStack_12 >> 0x10);
        if ((*(byte *)((int)_uStack_12 + 0x1c) & 2) == 0) {
          if (*(char *)(uStack_22 * 0x34 + 0xb) == '\0') {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 + (int)(char)psStack_18->cmap[5];
          }
          else {
            piVar1 = (int *)(uStack_22 * 0x34 + 8);
            *piVar1 = *piVar1 - (int)(char)psStack_18->cmap[5];
          }
          uStack_1a = uStack_1a + 1;
          if (*(byte *)((int)_uStack_12 + 0x19) + 1 == uStack_1a) {
            ovr_ovc41_specialAttack
                      ((agnt_t *)(ulong)CONCAT12(*(undefined1 *)(uStack_22 * 0x34 + 0xc),0x1726),
                       (char)(uStack_22 * 0x34));
          }
          if ((int)uStack_1a < (int)(uint)*(byte *)((int)_uStack_12 + 0x1b)) {
            *(undefined1 *)(uStack_22 * 0x34 + 0xe) = (undefined1)uStack_1a;
          }
          else {
            animBranchCode = 8;
            ovr_agnt_usesAnimFrame
                      ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
          }
        }
        else {
          ovr_agnt_usesStExit((agnt_t *)
                              CONCAT13((char)((ulong)_uStack_12 >> 8),
                                       CONCAT12((char)_uStack_12,0x1726)),
                              (anm_t *)CONCAT13((char)((ulong)_psStack_18 >> 8),
                                                CONCAT12((char)_psStack_18,uVar13)),
                              (stg_tmp_t *)CONCAT13(uVar27,CONCAT12(uVar26,uStack_16)),
                              uStack_22 * 0x34,(char)((ulong)_uStack_12 >> 0x10),(char)_psStack_18,
                              (char)((ulong)_psStack_18 >> 0x10));
        }
      }
      else {
        ovr_ovc27_usesBlitGfxRect((int)&agentRect,(byte)uStack_22);
      }
    }
  }
  GGameState = 0x3a;
  if (DebugVerbose != false) {
    printf("%d \r");
  }
  ovr_constr_blitRowObjects
            ((brect_t *)CONCAT13(uVar27,CONCAT12(uVar26,unaff_SS)),unaff_SI,(char)&agentRect);
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
      ovr_ovc41_removeAgent(0,(char)uStack_22);
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
        ovr_ovc41_advanceAnimFrame
                  ((agnt_t *)CONCAT13(uVar27,CONCAT12(uVar26,0x1726)),(char)(uStack_22 * 0x34));
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
  iVar17 = EntityCount;
  if (cStack_6 != '\0') {
    ovr_play_sfxU(0,0x80,0x3b,0x80);
    iVar17 = EntityCount;
  }
  do {
    do {
      iVar17 = iVar17 + -1;
      if (iVar17 < 0) {
        ovr_ovc41_usesDebugVerbose();
        return;
      }
      uVar13 = (undefined2)((ulong)Entities >> 0x10);
      peVar21 = (entity_t *)Entities;
    } while ((peVar21[iVar17].base.animFrame != 0x0) ||
            (uVar13 = ovr_ovc23_isCursorAt
                                (peVar21[iVar17].base.y,(char)((peVar21 + iVar17)->base).x),
            (char)uVar13 == '\0'));
    uStack_22 = (uint)AgntCount;
    do {
      uStack_22 = uStack_22 - 1;
      if ((int)uStack_22 < 0) break;
    } while (*(int *)(uStack_22 * 0x34 + 0x1b) != iVar17);
    if ((int)uStack_22 < 0) {
      ovr_ovc15_removeEntity(CONCAT11(uVar27,uVar26),(char)iVar17);
      constructionDirty = 1;
    }
  } while( true );
}


