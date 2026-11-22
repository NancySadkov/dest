void __cdecl16far ovc41_specialAttack(agnt_t *agnt,int targetIndex,...)

{
  uint *puVar1;
  agntG_t *paVar2;
  entity_t *peVar3;
  byte bVar4;
  undefined2 uVar5;
  agnt_t *agnt_00;
  int iVar6;
  char *pcVar7;
  uint8_t *puVar8;
  uint16_t uVar9;
  uint16_t uVar10;
  uint uVar11;
  char *unaff_SS;
  int in_stack_00000008;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  uint8_t actorName;
  uint8_t targetName;
  uint8_t msg;
  agnt_t far *uStack_8;   /* was undefined4: assigned agnt_t * values */
  char cStack_3;
  
  uVar13 = (undefined1)targetIndex;
  uVar14 = (undefined1)((uint)targetIndex >> 8);
  uVar5 = ovc41_turnUndeadNotice((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)));
  if ((((char)uVar5 == '\0') && (-1 < in_stack_00000008)) &&
     (in_stack_00000008 < (int)(uint)AgntCount)) {
    uVar10 = (uint16_t)((ulong)((long)in_stack_00000008 * 0x34) >> 0x10);
    agnt_00 = (agnt_t *)(agnt_t *)((long)in_stack_00000008 * 0x34);
    uStack_8 = (agnt_t *)CONCAT22(0x1726,agnt_00);
    if (agnt_00->animVariant == 0x0) {
      *(undefined1 *)&agnt_00->targetX = 0;
      *(undefined1 *)((int)&agnt_00->targetX + 1) = 0;
    }
    if ((agnt->flags & 8) == 0) {
      if (agnt->variant == 0x0) {
        if ((agnt->gindex == 0x4) && ((((agntG_t *)agnt->gdata)->flags2 & 0x200) != 0)) {
          bVar4 = agnt->strength;
          uVar5 = ovr_ovc27_breathHalfDamage(agnt_00,0x26);
          uVar11 = (uint)bVar4;
          if ((char)uVar5 != '\0') {
            uVar11 = (int)(uint)bVar4 >> 1;
          }
        }
        else {
          bVar4 = ovr_manage_rollDice(((agntG_t *)agnt->gdata)->dmgDice,
                                      ((agntG_t *)agnt->gdata)->dmgSides);
          iVar6 = (uint)bVar4 + (uint)((agntG_t *)agnt->gdata)->dmgBonus;
          bVar4 = ovr_agnt_compute9(agnt,uVar13);
          uVar10 = iVar6 + (char)bVar4;
          uVar11 = uVar10;
        }
        if ((uVar11 != 0) && ((((agntG_t *)agnt->gdata)->flags3 & 8) != 0)) {
          uVar5 = ovr_agnt_abilityModifier
                            (*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3),0);
          uVar11 = uVar11 + (int)(char)uVar5;
          if ((int)uVar11 < 1) {
            uVar11 = 1;
          }
        }
        paVar2 = ((agnt_t *)uStack_8)->gdata;
        if (((((agntG_t *)paVar2)->flags2 & 8) == 0) ||
           (bVar4 = ovr_agnt_compute9(agnt,uVar13), '\0' < (char)bVar4)) {
          paVar2 = ((agnt_t *)uStack_8)->gdata;
          if (((((agntG_t *)paVar2)->flags3 & 0x40) == 0) ||
             (bVar4 = ovr_agnt_compute9(agnt,uVar13), '\x01' < (char)bVar4)) {
            uVar5 = (undefined2)((ulong)uStack_8 >> 0x10);
            paVar2 = ((agnt_t *)uStack_8)->gdata;
            if (((((agntG_t *)paVar2)->flags2 & 0x10) == 0) || (agnt->gindex != 0x2)) {
              cStack_3 = ovc41_textParalyzed((agnt_t *)CONCAT22(targetIndex,agnt),(agnt_t *)uStack_8,uVar11,
                                             (char)uStack_8,(char)((ulong)uStack_8 >> 0x10),
                                             (char)uVar11);
              if ((cStack_3 == '\0') &&
                 (((agnt->gindex == 0x0 && ((((agntG_t *)agnt->gdata)->flags2 & 2) != 0)) &&
                  (uVar11 = ovr_ovc27_rollToHitEntity((uint32_t)uStack_8,0), (uVar11 & 0xff) == 0)))
                 ) {
                uVar16 = (undefined1)GSavedBlitSeg;
                pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                             (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                              CONCAT12((char)&actorName,
                                                                       (*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))));
                uVar15 = (undefined1)uVar10;
                uVar12 = SUB21(pcVar7,0);
                pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar12,uVar15,uVar16);
                pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70b5,unaff_SS),
                                       (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                uVar9 = ovr_audio_panFromX(agnt,uVar13);
                ovr_play_sfxU(0x55,0,uVar9,0,(char)uVar9);
                ovc41_settleAgentCombat
                          ((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)),(agnt_t *)uStack_8,(char)uStack_8)
                ;
                cStack_3 = '\x01';
              }
              if (((cStack_3 == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 4) != 0)) &&
                 (uVar11 = ovr_ovc27_rollToHitEntity((uint32_t)uStack_8,0), (uVar11 & 0xff) == 0)) {
                uVar5 = (undefined2)((ulong)uStack_8 >> 0x10);
                peVar3 = ((agnt_t *)uStack_8)->entity;
                if ((*(uint *)((int)&(((entity_t *)peVar3)->base).frames + 1) & 1) == 0) {
                  uVar12 = (undefined1)GSavedBlitSeg;
                  pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                               (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,uVar5)));
                  uVar14 = (undefined1)uVar10;
                  uVar13 = SUB21(pcVar7,0);
                  pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                  puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar13,uVar14,uVar12);
                  pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70c4,unaff_SS),
                                         (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                  ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                  uVar9 = ovr_audio_panFromX((agnt_t *)uStack_8,(char)((ulong)uStack_8 >> 0x10));
                  ovr_play_sfxU(5,0,uVar9,0,(char)uVar9);
                  peVar3 = ((agnt_t *)uStack_8)->entity;
                  puVar1 = (uint *)((int)&(((entity_t *)peVar3)->base).frames + 1);
                  *puVar1 = *puVar1 | 1;
                }
              }
              if (((cStack_3 == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 0x400) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame),
                 (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,uStack_8,0x1,(char)uStack_8,
                                   (char)((ulong)uStack_8 >> 0x10));
                uVar13 = (undefined1)GSavedBlitSeg;
                if ((char)uVar5 == '\0') {
                  pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                               (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))));
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(pcVar7,0);
                  pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                  puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar14,uVar12,uVar13);
                  pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7107,unaff_SS),
                                         (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                  ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                }
                else {
                  pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                               (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))));
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(pcVar7,0);
                  pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                  puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar14,uVar12,uVar13);
                  pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x70ec,unaff_SS),
                                         (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                  ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                }
              }
              if (((cStack_3 == '\0') && ((((agntG_t *)agnt->gdata)->flags2 & 0x800) != 0)) &&
                 (uVar9 = ovr_randBelow((uint)(((entity_t *)agnt->entity)->base).animFrame),
                 (uVar9 & 0xff) == 0)) {
                uVar5 = ovr_ovc27_usesPlay_sfxU
                                  ((uint16_t)agnt,targetIndex,uStack_8,0x2,(char)uStack_8,
                                   (char)((ulong)uStack_8 >> 0x10));
                uVar13 = (undefined1)GSavedBlitSeg;
                if ((char)uVar5 == '\0') {
                  pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                               (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))));
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(pcVar7,0);
                  pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                  puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar14,uVar12,uVar13);
                  pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7107,unaff_SS),
                                         (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                  ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                }
                else {
                  pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                               (char *)CONCAT13((char)((uint)&actorName >> 8),
                                                                CONCAT12((char)&actorName,
                                                                         (*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))));
                  uVar12 = (undefined1)uVar10;
                  uVar14 = SUB21(pcVar7,0);
                  pcVar7 = ovr_agnt_statusText(agnt,(char *)CONCAT22(&targetName,targetIndex));
                  puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,uVar10,uVar14,uVar12,uVar13);
                  pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7125,unaff_SS),
                                         (char *)CONCAT22(puVar8,(char *)0x2410),uVar10);
                  ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
                }
              }
            }
            else {
              uVar13 = (undefined1)GSavedBlitSeg;
              pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                           (char *)CONCAT13((char)((uint)&targetName >> 8),
                                                            CONCAT12((char)&targetName,uVar5)));
              puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,(char)uVar10,uVar13);
              pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x708c,unaff_SS),
                                     (char *)CONCAT13((char)((uint)puVar8 >> 8),
                                                      CONCAT12((char)puVar8,0x2410)),(char)puVar8,
                                     (char)uVar10);
              ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
              uVar10 = ovr_audio_panFromX((agnt_t *)uStack_8,(char)((ulong)uStack_8 >> 0x10));
              ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
            }
          }
          else {
            uVar13 = (undefined1)GSavedBlitSeg;
            pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                         (char *)CONCAT13((char)((uint)&targetName >> 8),
                                                          CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))
                                                         ));
            puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,(char)uVar10,uVar13);
            pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x705e,unaff_SS),
                                   (char *)CONCAT13((char)((uint)puVar8 >> 8),
                                                    CONCAT12((char)puVar8,0x2410)),(char)puVar8,
                                   (char)uVar10);
            ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
            uVar10 = ovr_audio_panFromX((agnt_t *)uStack_8,(char)((ulong)uStack_8 >> 0x10));
            ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
          }
        }
        else {
          uVar13 = (undefined1)GSavedBlitSeg;
          pcVar7 = ovr_agnt_statusText((agnt_t *)uStack_8,
                                       (char *)CONCAT13((char)((uint)&targetName >> 8),
                                                        CONCAT12((char)&targetName,(*(uint16_t *)((uint8_t *)&(uStack_8) + 2)))))
          ;
          puVar8 = ovr_ovc15_usesStshRealloc(pcVar7,(char)uVar10,uVar13);
          pcVar7 = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x7031,unaff_SS),
                                 (char *)CONCAT13((char)((uint)puVar8 >> 8),
                                                  CONCAT12((char)puVar8,0x2410)),(char)puVar8,
                                 (char)uVar10);
          ovr_uiNotify(pcVar7,uVar10,(char)uVar10);
          uVar10 = ovr_audio_panFromX((agnt_t *)uStack_8,(char)((ulong)uStack_8 >> 0x10));
          ovr_play_sfxU(0x16,0,uVar10,0,(char)uVar10);
        }
      }
      else {
        ovr_ovc27_textTakesHalfDamage3(agnt,targetIndex,uVar13,(char)in_stack_00000008);
      }
    }
    else {
      ovc41_textOnlyPlaceSingle((agnt_t *)CONCAT13(uVar14,CONCAT12(uVar13,agnt)),in_stack_00000008);
    }
  }
  return;
}
