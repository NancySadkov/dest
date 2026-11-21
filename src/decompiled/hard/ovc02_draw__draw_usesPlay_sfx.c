void __cdecl16far draw_usesPlay_sfx(void)

{
  char *pcVar1;
  char cVar2;
  uint16_t x;
  ulong *puVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  word count;
  int in_DX;
  undefined2 unaff_SI;
  uint uVar7;
  ulong prevTick;
  uint16_t outFlag;
  agnt_t *in_stack_0000fffa;
  byte bStack_4;
  
  prevTick = CONCAT22(unaff_SI,(*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)));
  puVar3 = ovr_attact_usesBDADailyTimeCounter((ulong *)recordUpdateTick,prevTick);
  if ((in_DX != 0) || ((ulong *)((int)(undefined4 *)&_DATA + 1U) < puVar3)) {
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick) + 2)) = (uint16_t)*(undefined2 *)(BDA_DailyTimeCounter.ofs + 2);
    (*(uint16_t *)((uint8_t *)&(recordUpdateTick))) = (uint16_t)*(ulong **)BDA_DailyTimeCounter;
    outFlag = 0;
    for (uVar7 = 0; uVar6 = (uint)(prevTick >> 0x10), uVar7 < GRecordCount; uVar7 = uVar7 + 1) {
      *(int *)(uVar7 * 0x12) = *(int *)(uVar7 * 0x12) + 1;
      if (20000 < *(uint *)(uVar7 * 0x12)) {
        *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0x14;
      }
      cVar2 = *(char *)(uVar7 * 0x12 + 0xe);
      if (cVar2 == '\0') {
        uVar4 = *(byte *)(uVar7 * 0x12 + 0x11) + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if ((uVar4 < *(byte *)(uVar7 * 0x12 + 6)) && (0x13 < *(uint *)(uVar7 * 0x12))) {
          *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
          pcVar1 = (char *)(uVar7 * 0x12 + 0x11);
          *pcVar1 = *pcVar1 + '\x01';
        }
      }
      else if (cVar2 == '\x01') {
        uVar4 = *(byte *)(uVar7 * 0x12 + 0x11) + 1;
        prevTick = CONCAT22(uVar6,uVar4);
        if (uVar4 < *(byte *)(uVar7 * 0x12 + 6)) {
          if (0x13 < *(uint *)(uVar7 * 0x12)) {
            *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
            pcVar1 = (char *)(uVar7 * 0x12 + 0x11);
            *pcVar1 = *pcVar1 + '\x01';
          }
        }
        else {
          *(undefined1 *)(uVar7 * 0x12 + 0xe) = 2;
          x = *(uint16_t *)(uVar7 * 0x12 + 2);
          in_stack_0000fffa = (agnt_t *)*(int *)(uVar7 * 0x12 + 4);
          uVar5 = ovr_ovc23_isCursorAt(x,(int)in_stack_0000fffa);
          if (((char)uVar5 != '\0') && (*(char *)(uVar7 * 0x12 + 8) != '\0')) {
            ovr_play_sfx(80,0);
          }
          bStack_4 = (byte)x;
          uVar5 = ovr_ovc22_usesGOngoingBattle(bStack_4,(byte)in_stack_0000fffa);
          if ((char)uVar5 != '\0') {
            outFlag = CONCAT11(1,(char)outFlag);
          }
          prevTick = (ulong)uVar6 << 0x10;
          uVar6 = ovr_ovc23_compute1(x,(int)in_stack_0000fffa,*(byte *)(uVar7 * 0x12 + 8),
                                     *(uint8_t *)(uVar7 * 0x12 + 9));
          if ((uVar6 & 0xff) == 0) {
            prevTick = prevTick & 0xffff0000;
            ovr_ovc23_placeBuilding
                      (x,(int)in_stack_0000fffa,*(byte *)(uVar7 * 0x12 + 8),
                       *(uint8_t *)(uVar7 * 0x12 + 9));
          }
          *(undefined2 *)(uVar7 * 0x12) = (uint16_t)0;
        }
      }
      else if ((cVar2 == '\x02') && (9 < *(uint *)(uVar7 * 0x12))) {
        if (uVar7 + 1 < GRecordCount) {
          count = ((GRecordCount - uVar7) + -1) * 0x12;
          prevTick = CONCAT22(uVar6,count);
          _fmemmove((char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12)),
                    (char *)CONCAT22(0x21f2,(char *)(uVar7 * 0x12 + 0x12)),count);
          uVar7 = uVar7 - 1;
        }
        GRecordCount = GRecordCount - 1;
        outFlag = CONCAT11((char)(outFlag >> 8),1);
      }
    }
    if ((char)outFlag != '\0') {
      ovr_ovc23_textAdlibNone(uVar6,outFlag,in_stack_0000fffa);
    }
    if ((char)(outFlag >> 8) != '\0') {
      ovr_constr_flushDirtyRects();
    }
  }
  return;
}
