bool __cdecl16far ovc23_textConstructionAbandoned(char *ofs,uint8_t *seg,byte dir)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  byte bVar4;
  uint8_t *puVar6;
  uint8_t uVar7;
  uint16_t play_id;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined2 uVar11;
  char *pcVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  undefined1 uVar16;
  byte bVar21;
  undefined1 extraout_AH;
  int iVar17;
  uint uVar18;
  undefined4 *puVar19;
  byte *pbVar20;
  undefined1 *in_CX;
  byte bVar22;
  byte bVar23;
  byte bVar25;
  char *pcVar24;
  uint *puVar26;
  uint *puVar27;
  int iVar28;
  uint *puVar30;
  undefined2 *puVar31;
  undefined2 *puVar32;
  char *unaff_BP;
  uint uVar33;
  uint unaff_SI;
  uint uVar34;
  uint8_t *puVar35;
  undefined2 unaff_SS;
  undefined2 uVar36;
  bool bVar37;
  bool bVar38;
  bool bVar39;
  byte in_AF;
  bool bVar40;
  bool bVar41;
  bool bVar42;
  far_t dst;
  brect_t *in_stack_00000000;
  ulong uVar43;
  char cVar44;
  agnt_t *in_stack_0000fffc;
  byte bVar5;
  byte bVar29;
  
  puVar35 = seg;
  pcVar12 = ofs;
  pcVar24 = ofs + *(char *)(dir + 0x885);
  uVar43 = CONCAT22(pcVar24,0x55fe);
  uVar18 = ovr_attact_usesGUnits((int)pcVar24,(int)(seg + *(char *)(dir + 0x889)));
  if (((uVar18 & 0xff) != 0) &&
     (puVar19 = (undefined4 *)(uint)dir, puVar19 <= (undefined4 *)((int)(undefined4 *)&_DATA + 3)))
  {
    iVar28 = (int)puVar19 * 2;
    switch((uint16_t)(uint)puVar19)   /* hand fix: int switch */ {
    case (uint16_t)0x0:
      (**(code **)(pcVar12 + iVar28 + -0x70))();
      break;
    case (uint16_t)0x2:
      uVar18 = 0x1000 << (*(byte *)((int)*puVar19 + 0x3f) & 0x1f);
      uVar10 = *(undefined4 *)((uint)(byte)(uVar43 >> 0x10) << 2);
      uVar33 = 0x1000 << ((*(byte *)((int)uVar10 + 0x3f) ^ 1) & 0x1f);
      uVar34 = 0;
      for (uVar43 = uVar43 & 0xffffff; bVar22 = (byte)(uVar43 >> 0x18), bVar22 < 4;
          uVar43 = CONCAT13(bVar22 + 1,(int3)uVar43)) {
        iVar28 = (int)&in_stack_0000fffc->x + (uint)bVar22;
        uVar33 = iVar28 * 2;
        uVar34 = uVar34 | ((short (*) [60] [148])GMapFlags)[-1][unaff_SI + 0x3b][iVar28 + 0x92] &
                          0x3000U;
      }
      if ((((*(byte *)((int)pcVar12 * 0x12 + 0xd) & 3) != 1) || (uVar34 != uVar33)) ||
         (uVar10 = *(undefined4 *)((uint)(byte)(uVar43 >> 0x10) << 2),
         bVar37 = ovr_ovc24_textArena((uint16_t)in_stack_0000fffc,unaff_SI,
                                      *(char *)((int)uVar10 + 0x3f)), bVar37)) {
        bVar22 = *(byte *)((int)pcVar12 * 0x12 + 0xd);
        pbVar20 = (byte *)(uint)bVar22;
        if (((bVar22 & 1) == 0) && ((uVar18 & uVar34) != 0)) {
          pbVar20 = (byte *)((int)pcVar12 * 0x12);
          pbVar20[0xd] = pbVar20[0xd] | 1;
        }
      }
      else {
        uVar36 = ovc23_isCursorAt((uint16_t)in_stack_0000fffc,unaff_SI);
        if ((char)uVar36 != '\0') {
          ovr_say((char *)"Construction abandoned.");
        }
        if (pcVar12 + 1 < GRecordCount) {
          _fmemmove((char *)CONCAT22(0x21f2,(char *)((int)pcVar12 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)((int)pcVar12 * 0x12 + 0x12)),
                    (int)(GRecordCount + (-1 - (int)pcVar12)) * 0x12);
        }
        GRecordCount = GRecordCount + -1;
        pbVar20 = ovc23_textAdlibNone(uVar18,unaff_SI,in_stack_0000fffc);
      }
      return SUB21(pbVar20,0);
    case (uint16_t)0x3:
      pcVar24 = pcVar24 + -1;
      bVar23 = (byte)iVar28;
      bVar15 = bVar23 - AgntAnms[0xf].frmid;
      bVar13 = (byte)((uint)iVar28 >> 8);
      bVar22 = bVar13 - dir;
      bVar29 = bVar22 - (bVar23 < AgntAnms[0xf].frmid);
      puVar26 = (uint *)CONCAT11(bVar29,bVar15);
      puVar8 = (undefined1 *)(uint)(bVar13 < dir || bVar22 < (bVar23 < AgntAnms[0xf].frmid));
      puVar31 = (undefined2 *)(&stack0xfffe + -(int)in_CX + -(int)puVar8);
      puVar2 = (uint *)(puVar35 + -0x57e7);
      uVar33 = (uint)(&stack0xfffe < in_CX || &stack0xfffe + -(int)in_CX < puVar8);
      puVar32 = (undefined2 *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)puVar31) - uVar33;
      puVar2 = (uint *)((int)puVar31 + 0x7419);
      uVar33 = (uint)(puVar32 < puVar31 || uVar18 - (int)puVar31 < uVar33);
      puVar8 = (undefined1 *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)in_CX) - uVar33;
      puVar2 = (uint *)(pcVar12 + 0x19);
      uVar33 = (uint)(puVar8 < in_CX || uVar18 - (int)in_CX < uVar33);
      puVar27 = (uint *)*puVar2;
      uVar18 = *puVar2;
      *puVar2 = (uVar18 - (int)puVar26) - uVar33;
                    /* WARNING: Read-only address (ram,0x00026a19) is written */
      uVar18 = (uint)(puVar27 < puVar26 || uVar18 - (int)puVar26 < uVar33);
      (*(uint16_t *)((uint8_t *)&(s_Peaceful_2410_2915) + 4)) = (0x6665U - (int)puVar35) - uVar18;
      uVar18 = (uint)((uint)0x6665 < puVar35 || (uint)(0x6665U - (int)puVar35) < uVar18);
      bVar37 = (uint)AgntAnms[6].y < pcVar24;
      uVar33 = AgntAnms[6].y - (int)pcVar24;
      AgntAnms[6].y = uVar33 - uVar18;
      puVar8 = (undefined1 *)(uint)(bVar37 || uVar33 < uVar18);
      puVar9 = &stack0xfff6 + -(int)puVar35;
      bVar37 = &stack0xfff6 < puVar35 || puVar9 < puVar8;
      iVar28 = -(int)puVar8;
      puVar30 = (uint *)(puVar9 + iVar28);
      bVar13 = (byte)((uint)in_CX >> 8);
      bVar22 = (byte)pcVar24 - bVar13;
      bVar38 = (byte)pcVar24 < bVar13 || bVar22 < bVar37;
      bVar25 = (byte)((uint)pcVar24 >> 8);
      bVar22 = bVar22 - bVar37;
      bVar37 = bVar15 != 0 || (byte)-bVar15 < bVar38;
      bVar21 = -bVar15 - bVar38;
      bVar23 = bVar22 - dir;
      bVar38 = bVar22 < dir || bVar23 < bVar37;
      bVar23 = bVar23 - bVar37;
      pbVar3 = (byte *)((char *)((int)puVar26 + (int)pcVar12) + -0x60e8);
      bVar37 = *pbVar3 < bVar13 || (byte)(*pbVar3 - bVar13) < bVar38;
      *pbVar3 = (*pbVar3 - bVar13) - bVar38;
      pbVar3 = (byte *)(puVar31 + -0x3974);
      bVar38 = *pbVar3 < bVar23 || (byte)(*pbVar3 - bVar23) < bVar37;
      *pbVar3 = (*pbVar3 - bVar23) - bVar37;
      pbVar3 = (byte *)(pcVar12 + 31000);
      bVar39 = *pbVar3 < dir || (byte)(*pbVar3 - dir) < bVar38;
      *pbVar3 = (*pbVar3 - dir) - bVar38;
      pbVar3 = (byte *)(puVar31 + 0xc);
      bVar22 = *pbVar3;
      bVar13 = *pbVar3 - bVar25;
      bVar38 = bVar22 < bVar25 || bVar13 < bVar39;
      bVar42 = SBORROW1(*pbVar3,bVar25) != SBORROW1(bVar13,bVar39);
      *pbVar3 = bVar13 - bVar39;
      bVar41 = (char)*pbVar3 < '\0';
      bVar40 = *pbVar3 == 0;
      bVar37 = !bVar42;
      bVar14 = (byte)in_CX;
      puVar32 = puVar31;
      if (!bVar37) {
        puVar6 = puVar35;
        puVar35 = puVar35 + 1;
        uVar7 = in(CONCAT11(bVar25,bVar23));
        *puVar6 = uVar7;
        pbVar3 = (byte *)(pcVar12 + 0x18);
        bVar4 = *pbVar3;
        bVar5 = *pbVar3;
        *pbVar3 = (bVar5 - bVar21) - bVar38;
        *(uint **)(puVar9 + iVar28 + -2) = puVar26;
        ((char *)((int)puVar31 + (int)pcVar12))[0x18] =
             (((char *)((int)puVar31 + (int)pcVar12))[0x18] - bVar14) -
             (bVar4 < bVar21 || (byte)(bVar5 - bVar21) < bVar38);
        *(uint *)((int)puVar26 + (int)pcVar12) =
             *(uint *)((int)puVar26 + (int)pcVar12) ^ (uint)puVar26;
        *(uint *)((int)puVar26 + (int)pcVar12) =
             *(uint *)((int)puVar26 + (int)pcVar12) | (uint)puVar26;
        *(char *)((int)puVar26 + (int)pcVar12) = *(char *)((int)puVar26 + (int)pcVar12) + bVar15;
        *puVar26 = ~*puVar26;
        puVar32 = (undefined2 *)*puVar31;
        uVar18 = CONCAT11(bVar21,dir - 0x18) & 0x9e1f;
        bVar41 = (int)uVar18 < 0;
        bVar40 = uVar18 == 0;
        puVar30 = puVar31 + 3;
      }
      bVar38 = bVar37 && bVar38;
      uVar36 = *puVar30;
      if (bVar40 || (bVar37 && bVar42) != bVar41) {
        bVar41 = bVar38;
        if ((!bVar37 || bVar22 >= bVar25 && bVar13 >= bVar39) && !bVar40) {
          *puVar30 = (uint)puVar32;
          uVar36 = *puVar30;
          uVar18 = (int)(char)bVar14 + 0xe299;
          iVar28 = uVar18 - bVar38;
          *puVar30 = iVar28;
          *pcVar12 = -*pcVar12;
          return (bool)(((char)iVar28 + -0x32) -
                       ((uint)(int)(char)bVar14 < 0x1d67 || uVar18 < bVar38));
        }
      }
      else {
        bVar41 = bVar14 < 0x74 || (byte)(bVar14 + 0x8c) < bVar38;
        bVar14 = (bVar14 + 0x8c) - bVar38;
      }
      bVar37 = bVar14 < 100 || (byte)(bVar14 + 0x9c) < bVar41;
      bVar13 = (bVar14 + 0x9c) - bVar41;
      bVar22 = bVar13 - 0x39;
      bVar38 = bVar13 < 0x39 || bVar22 < bVar37;
      bVar22 = bVar22 - bVar37;
      bVar13 = bVar22 - 0x14;
      bVar37 = bVar22 < 0x14 || bVar13 < bVar38;
      bVar13 = bVar13 - bVar38;
      bVar22 = bVar13 - 8;
      bVar38 = bVar13 < 8 || bVar22 < bVar37;
      bVar22 = bVar22 - bVar37;
      bVar13 = bVar22 - 5;
      bVar14 = bVar13 - bVar38;
      iVar28 = -(uint)(bVar14 < 0xfa || (byte)(bVar14 + 6) < (bVar22 < 5 || bVar13 < bVar38)) -
               (int)puVar26;
      uVar33 = (uint)pcVar12 & *(uint *)((char *)((int)puVar26 + (int)pcVar12) + -0x6bdd);
      uVar34 = (uint)puVar35 & *(uint *)((uint8_t *)((int)puVar26 + (int)puVar35) + 0x23);
      *puVar30 = uVar33;
      uVar33 = uVar33 & *(uint *)((int)puVar26 + uVar34);
      uVar18 = CONCAT11(bVar25,bVar23) & *(uint *)((int)puVar32 + uVar33 + iVar28);
      puVar27 = (uint *)CONCAT11(bVar29,bVar15 & bVar29 &
                                        *(byte *)((int)&_streams[0xc].curp +
                                                 CONCAT11(bVar29,bVar15 & bVar29)));
      uVar11 = *puVar30;
      puVar2 = (uint *)((int)puVar32 + uVar33 + iVar28);
      *puVar2 = *puVar2 ^ (uint)(puVar30 + 1);
      piVar1 = (int *)((int)puVar32 + uVar33 + iVar28);
      *piVar1 = *piVar1 - (int)(puVar30 + 1);
      bVar22 = in(uVar18);
      uVar33 = uVar33 & uVar18;
      puVar2 = (uint *)((int)puVar27 + (int)((char *)0x2a321 + uVar33));
      *puVar2 = *puVar2 & uVar34;
      *(uint *)(uVar34 + 0x21) = *(uint *)(uVar34 + 0x21) & (uint)puVar27;
      *puVar27 = *puVar27 & uVar34;
      puVar2 = (uint *)&AgntAnms[0x5c].sx;
      *puVar2 = *puVar2 & (uint)(puVar30 + 1);
      puVar2 = (uint *)((int)puVar27 + uVar33);
      *puVar2 = *puVar2 & CONCAT11((char)((uint)uVar11 >> 8),bVar22);
      bVar15 = -(0x99 < bVar22);
      return (bool)(bVar15 + (9 < (bVar15 & 0xf) | 9 < (bVar22 & 0xf) | in_AF) * '\x06' +
                   (0x99 < bVar15 || 0x99 < bVar22) * '`');
    }
    do {
      ovc23_usesBlitGfxRect2
                (unaff_SI,(int)in_stack_0000fffc,(int)unaff_BP,in_stack_00000000,(uint16_t)ofs);
      cVar44 = '\x01';
      do {
        while( true ) {
          do {
            do {
              puVar35 = puVar35 + 1;
              uVar16 = 0x10;
              if (rowMapSquareEnd[0] <= puVar35) {
                if (cVar44 != '\0') {
                  uVar16 = 0x10;
                  ovr_constr_usesScreenOriginY((uint16_t)ofs,(uint16_t)seg);
                }
                return (bool)uVar16;
              }
              play_id = *(uint16_t *)((int)puVar35 * 2 + 0x360);
            } while (((int)play_id < -2) || (1 < (int)play_id));
            in_stack_00000000 = (brect_t *)((ulong)in_stack_00000000 & 0xffff0000);
            bVar22 = ovr_constr_setHighlightAtOffset(play_id,0);
            iVar28 = CONCAT11(extraout_AH,bVar22);
            if (((char *)0x28048)[iVar28 * 3 + *(int *)((int)puVar35 * 2)] !=
                '\0') {
              uVar18 = (uint)((ulong)in_stack_00000000 >> 0x10);
              iVar17 = ovc23_usesCornerBR(play_id,iVar28);
              dst.seg = (uint16_t)seg;
              dst.ofs = (uint16_t)ofs;
              in_stack_00000000 = (brect_t *)((ulong)uVar18 << 0x10);
              ovr_animAdvance(play_id,((char *)0x28048)
                                      [iVar28 * 3 + *(int *)((int)puVar35 * 2)],
                              *(uint16_t *)((int)puVar35 * 2 + 0xa20),(uint)bandOrigin[0] - iVar17,
                              dst);
              cVar44 = '\x01';
            }
          } while (*(int *)(play_id * 2 + -0x6e25) == -1);
          uVar36 = (undefined2)((ulong)in_stack_00000000 >> 0x10);
          if (*(char *)(play_id + 0x90ec) != '\0') break;
          iVar28 = 0x6964;
          ovc23_usesCornerBR2(play_id,(uint)*(byte *)(*(int *)(play_id * 2 + -0x6e25) * 0x12 + 7));
          in_stack_00000000 = (brect_t *)CONCAT22(uVar36,seg);
          ovc23_usesBlitGfxRect2
                    ((uint)bandOrigin[0] - iVar28,iVar28,(int)ofs,in_stack_00000000,(uint16_t)ofs);
          cVar44 = '\x01';
        }
      } while (play_id != 0xfffe);
      in_stack_0000fffc = (agnt_t *)((int)&GSeasonNames[1].seg + 1);
      ovc23_usesCornerBR2(-2,(uint)*(byte *)(iRam0002d2d7 * 0x12 + 7));
      in_stack_00000000 = (brect_t *)CONCAT22(uVar36,seg);
      unaff_SI = (uint)bandOrigin[0] - (int)in_stack_0000fffc;
      unaff_BP = ofs;
    } while( true );
  }
  return false;
}
