/* init_computeMaxSquares - builds the square grid for the iso map.  The
   scale row table is copied to the stack (F_SCOPY from 2410:04e8), then for
   each row: the square pass fills SquareTopY/BottomY/LeftX/RightX,
   squareColumn and squareSide, and the map pass fills the same per-square
   arrays at half scale.  Local names come from those assignments
   (xStep/yStep, xOffset/yOffset, leftX/topY, colUp/colDown). */
void __cdecl16far init_computeMaxSquares(void)

{
  far_t dst;
  int topY;
  int colDown;
  uint sqColUp;
  uint16_t sqColDown;
  uint16_t unaff_SS;
  uint8_t scaleRow[10];
  uint yOffset;
  uint xOffset;
  char row;
  uint colUp;
  int mapTopY;
  int mapLeftX;
  int leftX;
  uint yStep;
  uint xStep;
  
  dst.seg = unaff_SS;
  dst.ofs = (uint16_t)&scaleRow;
  F_SCOPY(far_from_u32((uint32_t)(0x241004e8)),dst);
  GMaxSquare = 0;
  row = '\b';
  do {
    if (row < '\0') {
      if (GMaxSquare != 0x1b0) {
        printf("NEW MAXSQUARE %d \r");
        ovr_gameProcessKey();
      }
      GSMaxSquare = 0;
      row = '\x02';
      do {
        if (row < '\0') {
          if (GSMaxSquare != 0x24) {
            printf("NEW SMAXSQUARE %d \r");
            ovr_gameProcessKey();
          }
          return;
        }
        ((uint16_t *)rowBandSquareFirst)[row] = GSMaxSquare;
        xStep = ((uint)scaleRow[row + -1] * 0x30) / 0x30;
        yStep = ((uint)scaleRow[row] * 0x30) / 0x30;
        ((uint16_t *)RowScreenX)[row] =
             (uint)*(byte *)(row + 0x74c) + ((uint)scaleRow[row] * 0x3c) / 0x30;
        ((uint16_t *)RowScreenY)[row] =
             (uint)*(byte *)(row + 0x74b) + ((uint)scaleRow[row + -1] * 0x3c) / 0x30;
        yOffset = ((uint)scaleRow[row + -1] * 0x27) / 0x30;
        xOffset = ((uint)scaleRow[row] * 0x27) / 0x30;
        leftX = 0x111 - yOffset;
        sqColUp = 0;
        for (topY = 0x111 - xOffset; 0xee < (int)((topY - yStep) + xOffset + yStep);
            topY = topY - yStep) {
          leftX = leftX - xStep;
          sqColUp = sqColUp - 1;
        }
        for (; 0x7fff < sqColUp; sqColUp = sqColUp + 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = topY + xOffset;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + yStep;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = leftX + yOffset;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + xStep;
          ((uint16_t *)squareColumn)[GSMaxSquare] = sqColUp;
          if ((int)sqColUp < -1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 0;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          GSMaxSquare = GSMaxSquare + 1;
          leftX = leftX + xStep;
          topY = topY + yStep;
        }
        leftX = 0x111 - yOffset;
        sqColDown = 0;
        for (topY = 0x111 - xOffset; (int)(yStep + topY + xOffset) < 0x135;
            topY = topY + yStep) {
          leftX = leftX + xStep;
          sqColDown = sqColDown + 1;
        }
        for (; -1 < (int)sqColDown; sqColDown = sqColDown - 1) {
          if (0x23 < (int)GSMaxSquare) {
                    /* WARNING: Subroutine does not return */
            ovr_stExit(8);
          }
          ((uint16_t *)SquareTopY)[GSMaxSquare] = topY + xOffset;
          ((uint16_t *)SquareBottomY)[GSMaxSquare] =
               ((uint16_t *)SquareTopY)[GSMaxSquare] + yStep;
          ((uint16_t *)SquareLeftX)[GSMaxSquare] = leftX + yOffset;
          ((uint16_t *)SquareRightX)[GSMaxSquare] =
               ((uint16_t *)SquareLeftX)[GSMaxSquare] + xStep;
          ((uint16_t *)squareColumn)[GSMaxSquare] = sqColDown;
          if ((int)sqColDown < 1) {
            ((uint16_t *)squareSide)[GSMaxSquare] = 1;
          }
          else {
            ((uint16_t *)squareSide)[GSMaxSquare] = 2;
          }
          GSMaxSquare = GSMaxSquare + 1;
          leftX = leftX - xStep;
          topY = topY - yStep;
        }
        ((uint16_t *)rowBandSquareEnd)[row] = GSMaxSquare;
        row = row + -1;
      } while( true );
    }
    ((uint16_t *)rowMapSquareFirst)[row] = GMaxSquare;
    xStep = ((uint)scaleRow[row + -1] * 0x30) / 0x10;
    yStep = ((uint)scaleRow[row] * 0x30) / 0x10;
    ((uint16_t *)ScreenOriginX)[row] =
         (uint)*(byte *)(row + 0x729) + ((uint)scaleRow[row] * 0x38) / 0x10;
    ((uint16_t *)ScreenOriginY)[row] =
         (uint)*(byte *)(row + 0x728) + ((uint)scaleRow[row + -1] * 0x38) / 0x10;
    yOffset = ((uint)scaleRow[row + -1] * 0x27) / 0x10;
    xOffset = ((uint)scaleRow[row] * 0x27) / 0x10;
    mapLeftX = 0x75 - yOffset;
    colUp = 0;
    for (mapTopY = 0x75 - xOffset; 0xb < (int)((mapTopY - yStep) + xOffset + yStep);
        mapTopY = mapTopY - yStep) {
      mapLeftX = mapLeftX - xStep;
      colUp = colUp - 1;
    }
    *(uint *)(row * 2 + -0x73ed) = colUp;
    leftX = 0x75 - yOffset;
    colDown = 0;
    for (topY = 0x75 - xOffset; (int)(yStep + topY + xOffset) < 0xdf;
        topY = topY + yStep) {
      leftX = leftX + xStep;
      colDown = colDown + 1;
    }
    *(int *)(row * 2 + -0x73ff) = colDown;
    while ((0x7fff < colUp || (-1 < colDown))) {
      if ((int)colUp < 0) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = mapTopY + xOffset;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + yStep;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = mapLeftX + yOffset;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + xStep;
        *(uint *)(&mapSquareColumn[GMaxSquare]) = colUp;
        if ((int)colUp < -1) {
          *(uint16_t *)(GMaxSquare * 2) = 0;
        }
        else {
          *(uint16_t *)(GMaxSquare * 2) = 1;
        }
        GMaxSquare = GMaxSquare + 1;
        mapLeftX = mapLeftX + xStep;
        mapTopY = mapTopY + yStep;
        colUp = colUp + 1;
      }
      if (-1 < colDown) {
        if (0x1af < (int)GMaxSquare) {
                    /* WARNING: Subroutine does not return */
          ovr_stExit(7);
        }
        *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) = topY + xOffset;
        *(int *)(&mapSquareBottomY[GMaxSquare]) =
             *(int *)((int)&AgntAnms[0x5d].sx + 1 + GMaxSquare * 2) + yStep;
        *(int *)(&mapSquareLeftX[GMaxSquare]) = leftX + yOffset;
        *(int *)(&mapSquareRightX[GMaxSquare]) = *(int *)(&mapSquareLeftX[GMaxSquare]) + xStep;
        *(int *)(&mapSquareColumn[GMaxSquare]) = colDown;
        if (colDown < 1) {
          *(uint16_t *)(GMaxSquare * 2) = 1;
        }
        else {
          *(uint16_t *)(GMaxSquare * 2) = 2;
        }
        GMaxSquare = GMaxSquare + 1;
        leftX = leftX - xStep;
        topY = topY - yStep;
        colDown = colDown + -1;
      }
    }
    ((uint16_t *)rowMapSquareEnd)[row] = GMaxSquare;
    row = row + -1;
  } while( true );
}
