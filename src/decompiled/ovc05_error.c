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
  int iVar1;
  undefined2 unaff_SI;
  int in_stack_00000004;
  
  iVar1 = in_stack_00000004;
  if ((in_stack_00000004 != 0) && (in_stack_00000004 < 0x80)) {
    printf("\n\rError %d\n");
    ovr_biosReadKey();
  }
  ovr_biosVideoCall();
  if (iVar1 < 0x80) {
    if (iVar1 != 0) {
      printf("Error %d %d.  (Give Cathryn BOTH numbers.)\n");
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
    ovr_stshClose();
  }
  xmsFree();
  emsFree();
  ovr_chpath((char *)CONCAT22(unaff_SI,(char *)"puppetmaker" + 3),0x8c28);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    exit(0x80);
  }
                    /* WARNING: Subroutine does not return */
  exit(0);
}


