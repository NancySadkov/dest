/*
 * ovc05_error.c - recovered from STRONG.EXE
 * memory block: OVC05_error.c
 * range: 3168:0000 - 3168:015f
 * functions: 1
 */
#include "recovered.h"


/* 3168:0000 */

void __cdecl16far stExit(int n)

{
  if ((n != 0) && (n < 0x80)) {
    printf("\n\rError %d\n",n);
    ovr_biosReadKey();
  }
  ovr_biosVideoCall(0x0,0x3);
  if (n < 0x80) {
    if (n != 0) {
      printf("Error %d %d.  (Give Cathryn BOTH numbers.)\n",GGameState);
    }
  }
  else {
    printf("%s\n",*(undefined2 *)(n * 4 + 0x13e));
  }
  if (CFG_Mice != 0) {
    ovr_miceDisableHandler();
  }
  if (MusRunning != '\0') {
    ovr_midMidiStop();
  }
  if (MIDHandle.ofs != 0 || MIDHandle.seg != 0) {
    audio_done(MIDHandle.seg);
  }
  if (DIGHandle.ofs != 0 || DIGHandle.seg != 0) {
    audio_done(DIGHandle.seg);
  }
  if (-1 < StshStrongDatHnd) {
    ovr_stshClose(StshStrongDatHnd);
  }
  xmsFree();
  emsFree();
  ovr_chpath((char *)GOriginalDir);
  if (n != 0) {
                    /* WARNING: Subroutine does not return */
    exit(0x80);
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


