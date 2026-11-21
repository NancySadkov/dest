uint __cdecl16far stLoad(int handle)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  uint unaff_SI;
  uint16_t unaff_DI;
  void *unaff_SS;
  uint8_t header;
  
  ovr_stop_audio();
  ovr_drawTextAt((char *)"Loading...",0x2410);
  if (-1 < handle) {
    SaveAuto = 0;
    AgntFlag1 = false;
    ovr_freeGameResources();
    uVar1 = save_readBlock((int)&header,(void *)CONCAT22(0x28,unaff_SS),unaff_DI,unaff_SI);
    if (((((uVar1 & 0xff) != 0) &&
         (iVar2 = strcmp((char *)CONCAT22(unaff_SS,&header),
                         (char *)CONCAT22(SaveHeader.seg,SaveHeader.ofs)), iVar2 == 0)) &&
        (uVar1 = save_readBlock((int)(short (*) [148] [60])GUnitGrid,
                                (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GUnitGrid) + 2))),unaff_DI,unaff_SI),
        (uVar1 & 0xff) != 0)) &&
       ((((uVar1 = save_readBlock((int)(short (*) [60] [148])GMapFlags,
                                  (void *)CONCAT22(0x4560,(*(uint16_t *)((uint8_t *)&(GMapFlags) + 2))),unaff_DI,unaff_SI),
          (uVar1 & 0xff) != 0 &&
          (uVar1 = save_readBlock((int)(byte (*) [59] [148])GMapCells,
                                  (void *)CONCAT22(0x22b0,(*(uint16_t *)((uint8_t *)&(GMapCells) + 2))),unaff_DI,unaff_SI),
          (uVar1 & 0xff) != 0)) &&
         ((uVar1 = save_readBlock(-0x7661,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI), (uVar1 & 0xff) != 0 &&
          ((uVar1 = save_readBlock(-0x7663,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
           && (uVar1 = save_readBlock(-0x6f69,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
              (uVar1 & 0xff) != 0)))))) &&
        ((uVar1 = save_readBlock((int)Entities,(void *)CONCAT22(EntityCount * 0x37,DAT_2000_d190),
                                 unaff_DI,unaff_SI), (uVar1 & 0xff) != 0 &&
         (uVar1 = save_readBlock(0x881,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI), (uVar1 & 0xff) != 0))))))
    {
      uVar5 = (undefined2)((ulong)((long)SquareRecCount * 0x13) >> 0x10);
      uVar1 = save_readBlock(0,(void *)CONCAT22((int)((long)SquareRecCount * 0x13),
                                                (void *)((int)&AgntAnms[0x7c].halfWidth + 1)),
                             unaff_DI,unaff_SI);
      if (((uVar1 & 0xff) != 0) &&
         (uVar1 = save_readBlock(-0x6f1a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI), (uVar1 & 0xff) != 0)) {
        for (iVar2 = 0; iVar2 < (int)(uint)GLeaderCount; iVar2 = iVar2 + 1) {
          pvVar3 = ovr_stshAlloc(0xae);
          ((undefined2 *)(iVar2 * 4))[1] = uVar5;
          *(undefined2 *)(iVar2 * 4) = (uint16_t)pvVar3;   /* hand fix: store of the far pointer's offset half */
          uVar1 = save_readBlock(*(int *)(iVar2 * 4),
                                 (void *)CONCAT22(0xae,(void *)((int *)(iVar2 * 4))[1]),unaff_DI,
                                 unaff_SI);
          if ((uVar1 & 0xff) == 0) goto L_save_49fd_01da_0800;
        }
        uVar1 = save_readBlock(0x4a12,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI);
        if (((((((((((uVar1 & 0xff) != 0) &&
                   (uVar1 = save_readBlock(-0x6f1b,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  (uVar1 = save_readBlock(-0x6f1c,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (((uVar1 = save_readBlock(-0x6e21,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(0,(char *)CONCAT22(GRecordCount * 0x12,
                                                              (char *)0x21f2),
                                           unaff_DI,unaff_SI), (uVar1 & 0xff) != 0)) &&
                  ((uVar1 = save_readBlock(-0x7667,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   ((uVar1 = save_readBlock((int)(unit_t *)GUnits,
                                            (void *)CONCAT22(GUnitCount * 9,(*(uint16_t *)((uint8_t *)&(GUnits) + 2))),unaff_DI,
                                            unaff_SI), (uVar1 & 0xff) != 0 &&
                    (uVar1 = save_readBlock(0x2f3,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0)))))))) &&
                (uVar1 = save_readBlock(-0x6f62,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               ((((uVar1 = save_readBlock(-0x6f91,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0 &&
                  (uVar1 = save_readBlock(-0x6f92,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (uVar1 = save_readBlock(-0x6f97,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)) &&
                ((uVar1 = save_readBlock(-0x6df0,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(-0x6f1d,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))))) &&
              (((uVar1 = save_readBlock(-0x6f93,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(0x2f4,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(-0x6f99,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))) &&
               (uVar1 = save_readBlock(-0x6f63,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
               (uVar1 & 0xff) != 0)))) &&
             ((((uVar1 = save_readBlock(0x5dcf,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(0x5dd7,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               (uVar1 = save_readBlock(0x5ddf,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
               (uVar1 & 0xff) != 0)) &&
              (((uVar1 = save_readBlock(0x5de7,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                (uVar1 = save_readBlock(-0x6d33,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0)) &&
               ((uVar1 = save_readBlock(-0x6d34,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                (uVar1 & 0xff) != 0 &&
                ((uVar1 = save_readBlock(0x6a86,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0 &&
                 (uVar1 = save_readBlock(0x6a88,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                 (uVar1 & 0xff) != 0)))))))))) &&
            ((uVar1 = save_readBlock(0x439,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
             && ((((uVar1 = save_readBlock(-0x766f,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(-0x7670,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  (uVar1 = save_readBlock(0x693a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (((uVar1 = save_readBlock(-0x6d38,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   (uVar1 = save_readBlock(0x744,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0)) &&
                  ((uVar1 = save_readBlock(-0x6f65,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                   (uVar1 & 0xff) != 0 &&
                   ((uVar1 = save_readBlock(-0x6e1a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0 &&
                    (uVar1 = save_readBlock(-0x6e1c,(void *)((char *)&_DATA + 2),unaff_DI,unaff_SI),
                    (uVar1 & 0xff) != 0)))))))))))) &&
           ((uVar1 = save_readBlock(0x26df,(void *)&__C0_ASM_CopyRight,unaff_DI,unaff_SI), (uVar1 & 0xff) != 0
            && ((((uVar1 = save_readBlock(-0x6d3a,(void *)MK_FP(0x2410, 0x1),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0 &&
                  (uVar1 = save_readBlock(-0x6d44,(void *)MK_FP(0x2410, 0xa),unaff_DI,unaff_SI),
                  (uVar1 & 0xff) != 0)) &&
                 (uVar1 = save_readBlock((int)&header,(void *)CONCAT22(0x28,unaff_SS),unaff_DI,
                                         unaff_SI), (uVar1 & 0xff) != 0)) &&
                (iVar2 = strcmp((char *)CONCAT22(unaff_SS,&header),
                                (char *)CONCAT22(SaveHeader.seg,SaveHeader.ofs)), iVar2 == 0)))))) {
          ovr_drawTextAt((char *)"Load complete.",0x2410);
          uVar4 = (undefined1)((uint)iVar2 >> 8);
          SaveAuto = 1;
          ovr_ovc24_usesAlignUp4();
          save_usesCalcSeasonPalette();
          return CONCAT11(uVar4,1);
        }
      }
    }
  }
L_save_49fd_01da_0800:
  uVar1 = (uint)suppressLoadError;
  if (uVar1 == 0) {
    ovr_drawTextAt((char *)"Load Error",0x2410);
  }
  return uVar1 & 0xff00;
}
