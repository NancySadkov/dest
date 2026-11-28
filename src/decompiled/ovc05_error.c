/*
 * ovc05_error.c - recovered from STRONG.EXE
 * memory block: OVC05_error.c
 * range: 3168:0000 - 3168:015f
 * functions: 1
 */
#include "recovered.h"


/* 3168:0000 */

void __cdecl16far stExit(int n,...)

{
  /* 3168:0004 mov si,[bp+6]: SI holds the first parameter n throughout (the other
     SI instructions are or si,si reads and the final pop). */
  
  if ((n != 0) && (n < 0x80)) {
    printf("\n\rError %d\n",n);
    ovr_biosReadKey();
  }
  ovr_biosVideoCall(0x3,n);
  if (n < 0x80) {
    if (n != 0) {
      printf("Error %d %d.  (Give Cathryn BOTH numbers.)\n",GGameState,n);
    }
  }
  else {
    printf("%s\n");
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
  /* 3168:00f4 pushes the DGROUP far pointer 0x280:0x8c28, i.e. GOriginalDir - the directory
     init_paths saved at startup and this exit path restores. */
  ovr_chpath((char *)GOriginalDir,(uint16_t)_DS);
  if (n != 0) {
                    /* WARNING: Subroutine does not return */
    exit(0x80);
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


