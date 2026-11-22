/* ovc49_usesFrameIndex - stack locals named from their roles in the body
   (row = y>>1 clamped to 9, x/xEnd = clamped 0..0x68 scan bounds, step =
   scan direction, radius/side = the two-row neighbourhood scan, faction =
   agnt->faction, ok = ovr_agnt_compute4() result).  The grid reads at
   0x8fa/0x4e0 and the frame record via iVar3 are still raw, so those keep
   their decompiler forms. */
undefined1 __cdecl16far ovc49_usesFrameIndex(agnt_t *agnt,byte *out)

{
  uint8_t faction;
  uint16_t uVar2;
  int iVar3;
  bool ok;
  int iVar5;
  agnt_t *paVar6;
  int *piVar7;
  uint16_t uVar8;
  char side;
  char step;
  int xEnd;
  int x;
  int radius;
  int row;
  
  uVar8 = (uint16_t)((ulong)agnt >> 0x10);
  paVar6 = (agnt_t *)agnt;
  if (((agntG_t *)paVar6->gdata)->extents[1][1] == 0) {
    *out = 0;
  }
  else {
    faction = paVar6->faction;
    uVar2 = *(uint16_t *)((int)&paVar6->frames + 2);
    piVar7 = (int *)(*(int *)&paVar6->frames + (uint)paVar6->frameIndex * 4);
    iVar5 = piVar7[1];
    iVar3 = *piVar7;
    row = (int)paVar6->y >> 1;
    if (row < 0) {
      row = 0;
    }
    if (9 < row) {
      row = 9;
    }
    if (paVar6->level == 0x0) {
      step = '\x01';
      x = ((int)((int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] +
                        *(int *)(iVar3 + 0x17) + agnt->x) >> 1) + -1;
      xEnd = x +
                 ((int)((agntG_t *)paVar6->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] >> 1);
    }
    else {
      step = -1;
      x = ((int)((-*(int *)(iVar3 + 0x17) -
                        (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0]) + agnt->x) >> 1) + 1;
      xEnd = x -
                 ((int)((agntG_t *)paVar6->gdata)->extents[1][1] -
                  (int)(*(((agntG_t *)paVar6->gdata)->extents + 1))[0] >> 1);
    }
    if (x < 0) {
      x = 0;
    }
    if (xEnd < 0) {
      xEnd = 0;
    }
    if (0x68 < x) {
      x = 0x68;
    }
    if (0x68 < xEnd) {
      xEnd = 0x68;
    }
    for (; x != xEnd; x = x + step) {
      for (radius = 0; radius <= (int)((agntG_t *)paVar6->gdata)->extents[1][2] >> 1;
          radius = radius + 1) {
        side = -1;
        while (((side < '\x02' && (radius != 0)) || ((side == -1 && (radius == 0))))) {
          iVar5 = row + radius * side;
          if ((-1 < iVar5) && (iVar5 < 10)) {
            if ((*(char *)(iVar5 * 0x69 + x + 0x8fa) != '\0') &&
               (((*(byte *)(iVar5 * 0x69 + x + 0x8fa) <= AgntCount &&
                 (*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + x + 0x8fa) * 0x34 + -5) !=
                  faction)) &&
                (*(char *)((uint)*(byte *)(iVar5 * 0x69 + x + 0x8fa) * 0x34 + -0x10) == '\0')
                ))) {
              *out = *(byte *)(iVar5 * 0x69 + x + 0x8fa);
              ok = ovr_agnt_compute4((char *)out);
              if (ok) {
                return *out;
              }
            }
            if (((*(char *)(iVar5 * 0x69 + x + 0x4e0) != '\0') &&
                (*(byte *)(iVar5 * 0x69 + x + 0x4e0) <= AgntCount)) &&
               ((*(uint8_t *)((uint)*(byte *)(iVar5 * 0x69 + x + 0x4e0) * 0x34 + -5) != faction
                && (*(char *)((uint)*(byte *)(iVar5 * 0x69 + x + 0x4e0) * 0x34 + -0x10) ==
                    '\0')))) {
              *out = *(byte *)(iVar5 * 0x69 + x + 0x4e0);
              return *out;
            }
          }
          side = side + '\x02';
        }
      }
    }
    *out = 0;
  }
  return 0;
}
