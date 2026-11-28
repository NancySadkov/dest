/*
 * ovc33_stats.c - recovered from STRONG.EXE
 * memory block: OVC33_stats.c
 * range: 6386:0000 - 6386:28ff
 * functions: 25
 */
#include "recovered.h"


/* 6386:0000 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute1(agnt_t far *agnt)

{
  char cVar1;
  agnt_t far *paVar2;
  
  paVar2 = (agnt_t far *)agnt;
  if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xb < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x37;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x05') &&
          (9 < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x39;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x06') &&
          (7 < (((entity_t *)paVar2->entity)->base).level)) {
    cVar1 = (((entity_t *)paVar2->entity)->base).level + 0x39;
  }
  else {
    cVar1 = '0';
  }
  return cVar1;
}



/* 6386:0088 */

/* [R7] body shape: compute */

uint8_t __cdecl16far stats_compute2(agnt_t far *agnt)

{
  uint8_t uVar1;
  agnt_t far *paVar2;
  
  paVar2 = (agnt_t far *)agnt;
  if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xc < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0xc;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x05') &&
          (10 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0xa;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x06') &&
          (8 < (((entity_t *)paVar2->entity)->base).level)) {
    uVar1 = 0x8;
  }
  else {
    uVar1 = (((entity_t *)paVar2->entity)->base).level;
  }
  return uVar1;
}



/* 6386:00f8 */

/* Blits the full-screen stats background and the nwpanel1Cut3 panel. */

void __cdecl16far stats_drawStatsPanel(void)

{
  far_t gfx;
  far_t gfx_00;
  
  gfx.seg = fullScreenGfxSeg;
  gfx.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx,0,0,(brect_t *)0x5ce5,true,0,0);
  gfx_00.seg = nwpanel1Cut3Seg;
  gfx_00.ofs = nwpanel1Cut3Ofs;
  ovr_blitLoadRleGfx(gfx_00,far_from_u32((uint32_t)(0xa0000adf)),0);
  return;
}



/* 6386:013d */

/* [R7] body shape: compute */

undefined1 __cdecl16far stats_compute3(agnt_t far *agnt)

{
  undefined1 result;
  agnt_t far *paVar2;
  
  paVar2 = (agnt_t far *)agnt;
  if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x04') &&
     (0xb < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x05') &&
          (9 < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else if ((((agntG_t far *)paVar2->gdata)->shortName[3] == '\x06') &&
          (7 < (((entity_t *)paVar2->entity)->base).level)) {
    result = 1;
  }
  else {
    result = 0;
  }
  return result;
}



/* 6386:01a4 */

/* Draws the portrait of an agent type with the season palette. */

void __cdecl16far stats_drawPortrait(agntG_t far *gdata,byte portraitIndex,int palette)

{
  far_t handle;
  far_t handle_00;
  stg_tmp_t *gfxRec;
  uint16_t dxIn;           /* DX on entry, as the image's caller left it */
  agntG_t far *g;
  uint16_t paletteSeg;     /* segment half of the palette far pointer ([bp+0xc]) */
  far_t gfx;
  undefined1 dxHigh;       /* the high byte of dxIn, used to rebuild a far pointer */
  
  handle.seg = talkwin9Cut5Seg;
  handle.ofs = talkwin9Cut5Ofs;
  gfxRec = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette
            (gfxRec->cmap,dxIn,(uint8_t *)palette,paletteSeg,(char)dxIn,(char)palette);
  g = (agntG_t *)gdata;
  if (((g->prts + portraitIndex)->ofs != 0 || g->prts[portraitIndex].seg != 0) &&
     ((g->prtpals + portraitIndex)->ofs != 0 || g->prtpals[portraitIndex].seg != 0)) {
    handle_00.seg = g->prtpals[portraitIndex].seg;
    handle_00.ofs = (g->prtpals + portraitIndex)->ofs;
    gfxRec = ovr_stshLoadGfx(handle_00);
    dxHigh = (undefined1)(dxIn >> 8);
    _fmemmove((char far *)MK_FP(paletteSeg,(char *)(palette + 3)),
           (char *)CONCAT13(dxHigh,CONCAT12((char)dxIn,gfxRec->cmap + 3)),0xed);
    _fmemmove((char far *)MK_FP(paletteSeg,(char *)(palette + 0x1e0)),
           (char *)CONCAT13(dxHigh,CONCAT12((char)dxIn,gfxRec->cmap + 0x1e0)),0x90);
  }
  if (GameRunning == false) {
    ovr_vgaSetPalette8bit((uint8_t *)palette,paletteSeg);
  }
  if ((g->prts + portraitIndex)->ofs != 0 || g->prts[portraitIndex].seg != 0) {
    ovr_driver_fillRect(0xf,9,0x83,0x72,0xec,0xa000,0x72,0xec,0,0,0);
    gfx.seg = g->prts[portraitIndex].seg;
    gfx.ofs = (g->prts + portraitIndex)->ofs;
    ovr_blitGfxRect(gfx,16,10,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0,0,0,0);
  }
  return;
}



/* 6386:02db */
char * __cdecl16far agntCopyNthField(uint8_t filed_index,char *dst,char *src)

{
  int packed;
  char *pcVar2;
  bool bVar3;
  uint16_t len;
  uint16_t i;
  uint8_t in_stack_00000004;
  undefined1 in_stack_00000007;
  uint8_t j;
  
  packed = CONCAT11(in_stack_00000007,filed_index);
  j = 0x0;
  bVar3 = false;
  i = 0;
  while( true ) {
    in_stack_00000007 = (undefined1)((uint)packed >> 8);
    filed_index = (uint8_t)packed;
    pcVar2 = (char *)src;
    len = strlen((char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
    packed = CONCAT11(in_stack_00000007,filed_index);
    if (len <= i) break;
    if ((*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i)) == ',') {
      j = j + 0x1;
      packed = CONCAT11(in_stack_00000007,filed_index);
      if (bVar3) break;
    }
    else if (j == in_stack_00000004) {
      *(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + (int)(char)CONCAT11(in_stack_00000007,filed_index)) = (*(char *)((int)*(uint16_t *)((uint8_t *)&(dst) + 2) + i));
      packed = CONCAT11(in_stack_00000007,filed_index) + 1;
      bVar3 = true;
    }
    i = i + 1;
  }
  if (bVar3) {
    *(undefined1 *)CONCAT22((char *)dst,(undefined1 *)CONCAT11(in_stack_00000007,filed_index)) = 0;
  }
  else {
    strcpy((char *)CONCAT22((char *)dst,(char *)CONCAT11(in_stack_00000007,filed_index)),
           (char *)CONCAT22(pcVar2,(*(uint16_t *)((uint8_t *)&(dst) + 2))));
  }
  return (char *)CONCAT11(in_stack_00000007,filed_index);
}


/* 6386:0367 */

char * __cdecl16far
agntGetWeaponName(char *dst,uint8_t atype,bool magical,uint8_t field_index,int32_t agent)

{
  uint32_t fieldPtr;       /* the agent's field record, read at packed+0x1d */
  uint16_t tofs;
  uint16_t srcSeg;         /* segment half of the source packed string */
  char *dstSeg;            /* segment half of the destination ([bp+4]) */
  undefined1 in_stack_0000000f;
  
  if (*(int *)((int)&AgntGs[0].wpn_name + (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95) == 0) {
    if (atype == 0x0) {
      strcpy((char *)CONCAT22((char *)dst,dstSeg),"normal weaponry");
    }
    else {
      strcpy((char *)CONCAT22((char *)dst,dstSeg),"weaponry");
    }
  }
  else {
    fieldPtr = *(uint32_t *)(CONCAT11(in_stack_0000000f,field_index) + 0x1d);
    if ((*(uint *)((int)fieldPtr + 0x40) & 0x4000) == 0) {
      tofs = (uint)(*(uint8_t *)((uint8_t *)&(dst) + 2)) * 0x95;
      agntCopyNthField((uint8_t)dstSeg,
                       (char *)CONCAT22(*(uint16_t *)((int)&AgntGs[0].wpn_name + tofs),(char *)dst
                                       ),
                       (char *)CONCAT22(srcSeg,(char *)*(uint16_t *)
                                                          ((int)&AgntGs[0].wpn_name + 2 + tofs)));
    }
    else {
      strcpy((char *)CONCAT22((char *)dst,dstSeg),"short sword");
    }
  }
  return dstSeg;
}



/* 6386:0411 */

/* Appends the ring/armour description for an item: type 1 gives "+N ring of prot." (nothing for
   0), type 3 an armour tier chosen by the remaining count, and any other type one of nine armour
   names.  Re-derived from the image; the former body carried 804 lines and 57 calls for 182 bytes. */

far_t * __cdecl16far stats_textRingProt(char *dst,uint16_t src,uint16_t term,far_t ringValue)

{
  uint8_t type;
  uint8_t count;
  uint8_t value;

  (void)src;
  type = (uint8_t)term;
  count = (uint8_t)ringValue.ofs;
  value = (uint8_t)ringValue.seg;
  if (type == 1) {
    if (value == 0) {
      /* the image appends the lone NUL at ds:0x620f, which does nothing */
    }
    else if ((int8_t)value > 0) {
      sprintf(dst,"+%d ring of prot.",(uint16_t)value);
    }
    return (far_t *)dst;
  }
  count = (uint8_t)(count - value);
  if (type == 3) {
    switch ((int16_t)((int8_t)count - 6)) {
    case 0:
      strcat(dst,"+1 leather armor\000+2 leather armor");
      break;
    case 1:
      strcat(dst,"leather armor\0+1 leather armor\0+2 leather armor");
      break;
    case 2:
    case 3:
    case 4:
      strcat(dst,"no armor");
      break;
    default:
      strcat(dst,"+2 leather armor");
      break;
    }
    return (far_t *)dst;
  }
  switch ((int8_t)count) {
  case 0:
    strcat(dst,"suit armor");
    break;
  case 1:
    strcat(dst,"plate and shield +1");
    break;
  case 2:
    strcat(dst,"plate and shield\0plate and shield +1");
    break;
  case 3:
    strcat(dst,"plate mail");
    break;
  case 4:
    strcat(dst,"banded armor");
    break;
  case 5:
    strcat(dst,"chain mail");
    break;
  case 6:
    strcat(dst,"scale armor");
    break;
  case 7:
    strcat(dst,"leather armor\0+1 leather armor\0+2 leather armor");
    break;
  case 8:
    strcat(dst,"shield");
    break;
  default:
    strcat(dst,"no armor");
    break;
  }
  return (far_t *)dst;
}


/* 6386:05d3 */

/* [R7] body shape: compute */

char __cdecl16far stats_compute4(agnt_t far *agnt,uint16_t arg2)

{
  byte gindexVal;
  byte compute10Val;
  char modifier;           /* the level/ability modifier this returns */
  uint16_t abilityMod;
  
  gindexVal = agnt->gindex;
  if (AgntGs[(uint)gindexVal].shortName[3] == -1) {
    modifier = AgntGs[(uint)gindexVal].shortName[4];
  }
  else {
    compute10Val = ovr_agnt_compute10(agnt,arg2);
    modifier = AgntGs[(uint)gindexVal].shortName[4] - compute10Val;
    abilityMod = ovr_agnt_abilityModifier(*(uint8_t far *)((uint8_t far *)agnt + 0x1a),3);
    modifier = modifier - (char)abilityMod;
  }
  return modifier;
}



/* 6386:065c */

/* WARNING: Removing unreachable block (ram,0x00063ec8) */
/* Formats a long for the stats screen, switching to a 'K' suffix above a thousand. */

char * __cdecl16far stats_formatThousands(char *text,uint32_t value)

{
  size_t sVar1;
  long lVar2;
  
  if ((long)value < 1000000) {
    (*(uint16_t *)((uint8_t *)&(text))) = ovr_litoa10((char *)text,CONCAT22((uint16_t)value,(*(uint16_t *)((uint8_t *)&(text) + 2))),(*(uint16_t *)((uint8_t *)&(value) + 2)),0);
  }
  else {
    lVar2 = LDIV_at_(value,1000);
    ovr_litoa10((char *)text,CONCAT22((int)lVar2,(*(uint16_t *)((uint8_t *)&(text) + 2))),(int)((ulong)lVar2 >> 0x10),0);
    sVar1 = strlen(text);
    ((char *)text)[sVar1] = 'K';
    ((char *)text)[sVar1 + 1] = '\0';
  }
  return (char *)text;
}



/* 6386:06cd */

void __cdecl16far drawAgntStats(agnt_t far *agnt,far_t cmap,uint16_t arg3)

{
  uint32_t entPtr;
  far_t gfx;
  far_t fVar2;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t ringValue;
  far_t palette;
  char textAttr;          /* 'V', passed with the two colours */
  byte value;
  undefined1 cmapByte;      /* low byte of the cmap far pointer */
  char statValue;          /* result of stats_compute2(agnt) */
  char *textPtr;
  uint slotProbe;          /* result of stats_usesAlignUp4(agnt->owner) */
  int *namePairPtr;        /* (low, high) pair at shortName[3]*0x94 */
  uint16_t *strRef;
  int attrInt;             /* textAttr widened, passed to ovr_manage_compute1 */
  int growthValue;         /* result of ovr_ovc41_growthForLevel */
  far_t *text_00;
  uint8_t *in_DX;
  uint8_t *nameOfs;
  entity_t *peVar12;
  uint16_t colourC;        /* 0xe0, the attribute on the second pair of blits */
  uint16_t entitySeg;      /* segment half of agnt->entity */
  char *paletteSeg;        /* segment half of the palette ([bp+0xa]) */
  undefined1 fontSegLow;   /* low byte of Font02.seg */
  undefined1 segHi;
  undefined1 fontSegHigh;  /* high byte of Font02.seg */
  undefined1 byteLo;
  uint8_t *nameArg;        /* the name pointer passed to the blit */
  uint16_t fontOfs;
  undefined1 fontLowArg;    /* copy of fontSegLow for the blit's tail args */
  undefined1 fontHi;
  undefined1 fontHighArg;   /* copy of fontSegHigh */
  uint8_t colourA;         /* 0xde, the first attribute the label blit takes */
  uint8_t attr;
  uint16_t colourB;        /* 0xe0, the second attribute */
  uint16_t blitColour;
  char palbuf [768];
  char buf [80];
  static char text[64];   /* DGROUP-backed formatting buffer */
  uint8_t line;
  uint8_t field_index;
  byte bStack_4;
  int8_t damage;
  
  fVar2 = cmap;
  TextBlitDstSeg = 0xa000;
  if (cmap.seg == 0 && paletteSeg == (char *)0x0) {
    cmap.seg = (uint16_t)palbuf;
    paletteSeg = _SS;
  }
  if (!GameRunning) {
    stats_drawStatsPanel();
  }
  if (DebugVerbose != false) {
    printf("Exp %ld \r");
  }
  field_index = (*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 3) & 1) != 0;
  bStack_4 = field_index;
  if (3 < (((entity_t *)agnt->entity)->base).level) {
    bStack_4 = field_index + 4;
  }
                    /* WARNING: Load size is inaccurate */
  stats_drawPortrait((agntG_t *)CONCAT22(*(uint16_t *)((int)&agnt->gdata + 2),agnt->gdata),
                     bStack_4,cmap.seg);
  TextBlitY = 10;
  TextBlitX = 0x87;
  colourB = 0xe0;
  colourA = 0xde;
  byteLo = (undefined1)Font02.seg;
  fontHi = (undefined1)(Font02.seg >> 8);
  cmapByte = (undefined1)fVar2.ofs;
  segHi = (*(uint8_t *)((uint8_t *)&(fVar2.ofs) + 1));
  fontOfs = Font02.ofs;
  textPtr = ovr_agnt_statusText(agnt,(char *)CONCAT13((char)((uint)&line >> 8),
                                                     CONCAT12((char)&line,cmap.ofs)),cmapByte);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),colourA,byteLo,
                colourA,colourB);
  if ((GameRunning == false) && ((agnt->gdata->ai == 0 || (DebugVerbose != false)))) {
    TextBlitY = 0xb5;
    TextBlitX = 0x13;
    if ((*(byte *)((int)&(((entity_t *)agnt->entity)->base).flags32 + 1) & 1) == 0) {
      (*(uint8_t *)((uint8_t *)&(fVar2.seg))) = (char)butt01Cut3Seg;
      fVar2.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(fVar2.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(fVar2,16,179,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0x10,0,0,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx.seg))) = (char)butt01Cut4Seg;
      gfx.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx,16,179,(brect_t *)(BlitRects + 1),0x10,true,0x10,0x10,0x10,0,0,0);
      TextBlitX = 0x47;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x13;
    }
    ovr_blitLabel((char *)"Ready",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                  Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x57;
    slotProbe = stats_usesAlignUp4(agnt->owner);
    if ((char)slotProbe == '\0') {
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg))) = (char)butt01Cut3Seg;
      gfx_01.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_01.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(gfx_01,84,179,(brect_t *)(BlitRects + 1),0x10,true,0x54,0x10,0x10,0,0,0);
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg))) = (char)butt01Cut4Seg;
      gfx_00.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_00.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx_00,84,179,(brect_t *)(BlitRects + 1),0x10,true,0x54,0x10,0x10,0,0,0);
      TextBlitX = 0x8b;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x57;
    }
    ovr_blitLabel((char *)"Home",(uint8_t *)CONCAT22(FontMain.ofs,(char *)0x26510),
                  FontMain.seg,0xde,(char)FontMain.seg,0xde,0xe0);
    TextBlitY = 0xb5;
    TextBlitX = 0x9b;
    slotProbe = stats_usesAlignUp4(agnt->owner);
    if (((slotProbe & 0xff) == 0) &&
       ((*(byte *)((int)&(((entity_t *)agnt->entity)->base).flags32 + 1) & 1) == 0)) {
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg))) = (char)butt01Cut4Seg;
      gfx_02.ofs = butt01Cut4Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_02.seg) + 1)) = (char)((uint)butt01Cut4Seg >> 8);
      ovr_blitGfxRect(gfx_02,152,179,(brect_t *)(BlitRects + 1),0x10,true,0x98,0x10,0x10,0,0,0);
      TextBlitX = 0xcf;
      ovr_blitLabel((char *)"\x7f",(uint8_t *)CONCAT22(Font01.ofs,(char *)0x26510),
                    Font01.seg,0xde,(char)Font01.seg,0xde,0xe0);
      TextBlitX = 0x9b;
    }
    else {
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg))) = (char)butt01Cut3Seg;
      gfx_03.ofs = butt01Cut3Ofs;
      (*(uint8_t *)((uint8_t *)&(gfx_03.seg) + 1)) = (char)((uint)butt01Cut3Seg >> 8);
      ovr_blitGfxRect(gfx_03,152,179,(brect_t *)(BlitRects + 1),0x10,true,0x98,0x10,0x10,0,0,0);
    }
    ovr_blitLabel((char *)"Unassigned",(uint8_t *)CONCAT22(FontMain.ofs,(char *)0x26510),
                  FontMain.seg,0xde,(char)FontMain.seg,0xde,0xe0);
  }
  TextBlitY = 0x11;
  TextBlitX = 0x87;
  colourB = 0xe0;
  colourA = 0xde;
  byteLo = (undefined1)Font02.seg;
  fontHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  textPtr = ovr_stsprintf((char *)&line);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),colourA,byteLo,
                colourA,colourB);
  TextBlitY = 0x1b;
  TextBlitX = 0x87;
  if (*(char *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) != -1) {
    strRef = (uint16_t *)
             ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
    colourB = strRef[1];
    slotProbe = ovr_font_textWidth((char *)*strRef,
                               (char *)CONCAT13((char)(Font02.ofs >> 8),
                                                CONCAT12((char)Font02.ofs,colourB)),(char)colourB,
                               (char)Font02.ofs,Font02.seg);
    fontSegLow = (undefined1)Font02.seg;
    fontSegHigh = (undefined1)(Font02.seg >> 8);
    byteLo = (undefined1)Font02.ofs;
    fontHi = (undefined1)(Font02.ofs >> 8);
    if (slotProbe < 0x30) {
      colourC = 0xe0;
      colourA = 0xde;
      colourB = 3;
      textAttr = 'V';
      strRef = (uint16_t *)
               ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
      in_DX = (uint8_t *)((char *)0x2627a);
      fontOfs = Font02.ofs;
      fontLowArg = fontSegLow;
      fontHighArg = fontSegHigh;
      textPtr = ovr_stsprintf(text,(char *)CONCAT22(0x62fe,_SS),
                             (char *)CONCAT22(*strRef,(char *)0x26510),strRef[1]);
      textPtr = (char *)ovr_ovc45_compute9((char *)&line,(char *)CONCAT22(textPtr,_SS),
                                          (char *)CONCAT13(fontHi,CONCAT12(byteLo,in_DX)),
                                          CONCAT11(fontSegHigh,fontSegLow),textAttr,byteLo,fontSegLow,textAttr,colourB);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHighArg,fontLowArg),colourA,fontLowArg,
                    colourA,colourC);
    }
    else {
      colourC = 0xe0;
      colourA = 0xde;
      colourB = 3;
      textAttr = 'V';
      strRef = (uint16_t *)
               ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) * 4);
      in_DX = (uint8_t *)((char *)0x2627a);
      fontOfs = Font02.ofs;
      fontLowArg = fontSegLow;
      fontHighArg = fontSegHigh;
      textPtr = ovr_stsprintf(text,(char *)CONCAT22(0x630a,_SS),
                             (char *)CONCAT22(*strRef,(char *)0x26510),strRef[1]);
      textPtr = (char *)ovr_ovc45_compute9((char *)&line,(char *)CONCAT22(textPtr,_SS),
                                          (char *)CONCAT13(fontHi,CONCAT12(byteLo,in_DX)),
                                          CONCAT11(fontSegHigh,fontSegLow),textAttr,byteLo,fontSegLow,textAttr,colourB);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHighArg,fontLowArg),colourA,fontLowArg,
                    colourA,colourC);
    }
  }
  TextBlitY = 0x25;
  TextBlitX = 0x87;
  if (((agntG_t far *)agnt->gdata)->shortName[3] != -1) {
    textAttr = stats_compute3(agnt);
    byteLo = (undefined1)Font02.seg;
    fontHi = (undefined1)(Font02.seg >> 8);
    if (textAttr == '\0') {
      colourB = 0xe0;
      colourA = 0xde;
      fontOfs = Font02.ofs;
      value = stats_compute2(agnt);
      textPtr = ovr_manage_compute1((uint)value,0);
      fontSegLow = SUB21(textPtr,0);
      nameOfs = in_DX;
      statValue = stats_compute2(agnt);
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6323,_SS),
                             (char *)(ulong)CONCAT12(statValue,0x2410),0x10,statValue,fontSegLow,nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),colourA,byteLo,
                    colourA,colourB);
    }
    else {
      colourA = 0xde;
      fontOfs = Font02.ofs;
      textAttr = stats_compute1(agnt);
      attrInt = (int)textAttr;
      value = stats_compute2(agnt);
      textPtr = ovr_manage_compute1((uint)value,attrInt);
      fontSegHigh = SUB21(in_DX,0);
      fontSegLow = SUB21(textPtr,0);
      statValue = stats_compute2(agnt);
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6313,_SS),
                             (char *)(ulong)CONCAT12(statValue,0x2410),statValue,fontSegLow,fontSegHigh);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,in_DX),CONCAT11(fontHi,byteLo),colourA,byteLo);
    }
  }
  if ((((agntG_t far *)agnt->gdata)->shortName[3] == -1) ||
     (*(char *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) == -1)) {
    slotProbe = (uint)(byte)((agntG_t far *)agnt->gdata)->shortName[2];
    nameOfs = (uint8_t *)((char *)0x26510);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + slotProbe)->ofs,
                  (uint8_t *)
                  CONCAT22(Font02.ofs,
                           (uint8_t *)*(uint16_t *)((int)&GAlignmentsNames[0].seg + slotProbe * 4)),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  else {
    entPtr = *(uint32_t *)
             ((uint)*(byte *)((int)&(((entity_t *)agnt->entity)->base).entity + 3) << 2);
    slotProbe = (uint)*(byte *)((int)entPtr + 0x33);
    nameOfs = (uint8_t *)((char *)0x26510);
    ovr_blitLabel((char *)((far_t *)GAlignmentsNames + slotProbe)->ofs,
                  (uint8_t *)
                  CONCAT22(Font02.ofs,
                           (uint8_t *)*(uint16_t *)((int)&GAlignmentsNames[0].seg + slotProbe * 4)),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  TextBlitY = 0x2f;
  TextBlitX = 0x87;
  if ((((agntG_t far *)agnt->gdata)->shortName[3] != -1) && (agnt->gdata->ai == 0)) {
    ovr_blitLabel((char *)"Experience points",
                  (uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),Font02.seg,0xde,
                  (char)Font02.seg,0xde,0xe0);
    TextBlitY = 0x36;
    TextBlitX = 0x87;
    namePairPtr = (int *)((uint)(byte)((agntG_t far *)agnt->gdata)->shortName[3] * 0x94 +
                    (uint)(((entity_t *)agnt->entity)->base).level * 4);
    nameOfs = (uint8_t *)((char *)0x262b1);
    statValue = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    if (*namePairPtr == 0 && namePairPtr[1] == 0) {
      colourB = 0xe0;
      colourA = 0xde;
      fontOfs = Font02.ofs;
      textPtr = ovr_litoa10(text,0,0,0);
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(7,_SS)),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),7,0x10,(char)textPtr,
                             nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,statValue,
                    colourA,colourB);
    }
    else {
      blitColour = 0xe0;
      colourA = 0xde;
      strRef = (uint16_t *)
               ((uint)(byte)((agntG_t far *)agnt->gdata)->shortName[3] * 0x94 +
               (uint)(((entity_t *)agnt->entity)->base).level * 4);
      nameOfs = (uint8_t *)((char *)0x262b1);
      fontOfs = Font02.ofs;
      textPtr = stats_formatThousands
                         ((char *)CONCAT13((char)((uint)_SS >> 8),CONCAT12((char)_SS,buf))
                          ,CONCAT22(strRef[1],*strRef));
      byteLo = SUB21(textPtr,0);
      entitySeg = (uint16_t)((ulong)agnt->entity >> 0x10);
      peVar12 = (entity_t *)agnt->entity;
      colourB = *(uint16_t *)&(peVar12->base).frameIndex;
      nameArg = nameOfs;
      textPtr = stats_formatThousands
                         (text,
                          CONCAT13((char)((uint)colourB >> 8),
                                   CONCAT12((char)colourB,*(uint16_t *)&(peVar12->base).health)));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6342,_SS),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),(char)textPtr,
                             (char)nameOfs,byteLo,nameArg);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,statValue,
                    colourA,blitColour);
    }
  }
  if (agnt->gdata->ai != 0) {
    colourB = 0xe0;
    colourA = 0xde;
    statValue = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    fontOfs = Font02.ofs;
    growthValue = ovr_ovc41_growthForLevel
                       (*(agnt_t far **)&agnt->entity,*(uint16_t *)((int)&agnt->entity + 2));
    textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x48,_SS)),
                           (char *)CONCAT13((char)((uint)growthValue >> 8),CONCAT12((char)growthValue,0x2410))
                           ,0x48,0x10,(char)growthValue,nameOfs);
    ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,statValue,
                  colourA,colourB);
  }
  TextBlitY = 0x40;
  TextBlitX = 0x87;
  colourB = 0xe0;
  colourA = 0xde;
  statValue = (undefined1)Font02.seg;
  segHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x54,_SS)),
                         (char *)(ulong)CONCAT12(agnt->strength,0x2410),0x54,0x10,agnt->strength,
                         (uint)agnt->strengthMax);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,statValue,
                colourA,colourB);
  TextBlitY = 0x4a;
  TextBlitX = 0x87;
  growthValue = (uint)((agntG_t far *)agnt->gdata)->type * 0x95;
  nameOfs = (uint8_t *)((int)&BuildingTypes[0x9f].income + 1);
  colourA = (uint8_t)agnt;
  if (*(int *)((int)&AgntGs[0].wpn_name + growthValue) == 0 &&
      *(int *)((int)&AgntGs[0].wpn_name + 2 + growthValue) == 0) {
    damage = 0;
  }
  else {
    damage = ovr_agnt_compute9(agnt,cmap.ofs);
    statValue = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    if (damage == 0) {
      colourB = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t far *)agnt->gdata)->type),
                                                  _SS),0x0,(bool)field_index,colourA,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),attr,statValue,
                    attr,colourB);
    }
    else if (damage < '\0') {
      colourB = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t far *)agnt->gdata)->type),
                                                  _SS),damage,(bool)field_index,colourA,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT13(99,CONCAT12(0x65,_SS)),
                             (char *)CONCAT13((char)((uint)textPtr >> 8),
                                              CONCAT12((char)textPtr,0x2410)),0x65,0x10,(char)textPtr,
                             nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),attr,statValue,
                    attr,colourB);
    }
    else {
      colourB = 0xe0;
      attr = 0xde;
      fontOfs = Font02.ofs;
      textPtr = agntGetWeaponName((char *)CONCAT22(CONCAT11(0x24,((agntG_t far *)agnt->gdata)->type),
                                                  _SS),damage,(bool)field_index,colourA,
                                 CONCAT22(Font02.ofs,cmap.ofs));
      textPtr = ovr_stsprintf((char *)&line,(char *)CONCAT22(0x6370,_SS),
                             (char *)CONCAT13(damage >> 7,CONCAT12(damage,0x2410)),0x10,damage,
                             (char)textPtr,nameOfs);
      ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),attr,statValue,
                    attr,colourB);
    }
  }
  TextBlitY = 0x54;
  TextBlitX = 0x87;
  if (agnt->gdata->ai == 0) {
    damage = ovr_agnt_compute11(agnt,cmap.ofs);
  }
  else {
    damage = 0;
  }
  colourB = 0xe0;
  colourA = 0xde;
  statValue = (undefined1)Font02.seg;
  segHi = (undefined1)(Font02.seg >> 8);
  fontOfs = Font02.ofs;
  stats_compute4(*(agnt_t far **)&agnt->entity,*(uint16_t *)((int)&agnt->entity + 2));
  textPtr = ovr_stsprintf((char *)&line);
  ovr_blitLabel(textPtr,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,statValue,
                colourA,colourB);
  if (agnt->gdata->ai == 0) {
    TextBlitY = 0x5e;
    TextBlitX = 0x87;
    colourB = 0xe0;
    colourA = 0xde;
    statValue = (undefined1)Font02.seg;
    segHi = (undefined1)(Font02.seg >> 8);
    (*(uint8_t *)((uint8_t *)&(ringValue.seg))) = statValue;
    ringValue.ofs = Font02.ofs;
    (*(uint8_t *)((uint8_t *)&(ringValue.seg) + 1)) = segHi;
    fontOfs = Font02.ofs;
    text_00 = stats_textRingProt((char *)CONCAT13(0x24,CONCAT12(((agntG_t far *)agnt->gdata)->type,
                                                                _SS)),
                                 CONCAT11(0x24,((agntG_t far *)agnt->gdata)->shortName[4]),
                                 CONCAT11(0x24,damage),ringValue);
    ovr_blitLabel((char *)text_00,(uint8_t *)CONCAT22(fontOfs,nameOfs),CONCAT11(segHi,statValue),colourA,
                  statValue,colourA,colourB);
  }
  else {
    damage = 0;
  }
  if ((*(uint *)((int)&(((entity_t *)agnt->entity)->base).frames + 1) & 2) != 0) {
    TextBlitY = 0x68;
    TextBlitX = 0x87;
    ovr_blitLabel((char *)"Mirror",(uint8_t *)CONCAT22(Font02.ofs,(char *)0x26510),
                  Font02.seg,0xde,(char)Font02.seg,0xde,0xe0);
  }
  if (GameRunning != false) {
    palette.seg = (uint16_t)paletteSeg;
    palette.ofs = cmap.seg;
    ovr_setSeasonPalette(palette);
  }
  return;
}



/* 6386:12b7 */

/* Formats the ready/not-ready line for an agent. */

char * __cdecl16far stats_readyStatusText(byte agntIndex,char *text)

{
  uint8_t *puVar2;
  char *msg;
  uint16_t agntSeg;

  if ((*(uint8_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.flags32 + 1) & 1) == 0) {
    agntSeg = SEG_OF(Agnts);
    puVar2 = ovr_ovc15_usesStshRealloc
                       ((char *)far_ofs_u32(Agnts[agntIndex].gdata->name),
                        (uint16_t)SEG_OF(Agnts[agntIndex].gdata->name),0,0,0,0,0,0);
    msg = ovr_stsprintf(agntIndex,(char *)CONCAT22(0x638d,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)0x26510),agntSeg);
  }
  else {
    agntSeg = SEG_OF(Agnts);
    puVar2 = ovr_ovc15_usesStshRealloc
                       ((char *)far_ofs_u32(Agnts[agntIndex].gdata->name),
                        (uint16_t)SEG_OF(Agnts[agntIndex].gdata->name),0,0,0,0,0,0);
    msg = ovr_stsprintf(agntIndex,(char *)CONCAT22(0x63a2,(char *)text),
                           (char *)CONCAT22(puVar2,(char *)0x26510),agntSeg);
  }
  return msg;
}



/* 6386:1353 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R6] touches EntityCount, Entities */

void __cdecl16far stats_usesEntityCount(char partyIndex)

{
  byte *flagBytePtr;       /* &Entities[i].base + 0x33, bit 2 cleared */
  uint i;                  /* entity index */
  
  for (i = 0; i < EntityCount; i = i + 1) {
    if (*(char *)((int)&(Entities)[i].base.entity + 3) == partyIndex) {
      flagBytePtr = (byte *)((uint8_t *)&(Entities)[i] + 0x33);
      *flagBytePtr = *flagBytePtr & 0xfb;
    }
  }
  return;
}



/* 6386:13a1 */

/* WARNING: Variable defined which should be unmapped: text */
/* Formats the "%s is no longer ready." notice and ready-list hint. */

void __cdecl16far stats_unreadyNotice(byte agnt_id)

{
  /* Re-derived from 6386:13a1 (465 bytes).  Toggles bit 0 of the agent entity's last flag byte,
     reports the change, redraws the stats panel, then either prints the agent's generic name or the
     "ready" status text depending on that bit.

     The entity byte is reached as `les bx,es:[bx+0x17]` then `es:[bx+0x33]` - a chained far deref
     that the export truncated through a `uint32_t` local and an `(int)` cast.  `entity` and `gdata`
     are far pointer fields, so the accesses below are direct.

     The argument lists of ovc15_usesStshRealloc / stsprintf / drawString / attact_usesEntities /
     stats_readyStatusText and the declared sizes of `text` and `msg` are kept exactly as exported:
     the frame is `sub sp,0xd0` with a far buffer at `SS:[bp-0xa8]`, so those buffers are larger than
     declared and their true extents are not established here. */
  uint8_t *allocPtr;
  char *textPtr;
  char *textFar;
  uint16_t agntSeg;
  uint8_t text;
  uint8_t msg;
  uint8_t unitFlags;
  int owner;
  uint8_t far *flagByte;
  far_t noCmap;

  /* entity + 0x33: the high byte of base.flags32, the last byte of the agent record */
  flagByte = (uint8_t far *)&Agnts[agnt_id].entity->base.flags32 + 1;
  *flagByte = *flagByte ^ 1;
  if ((*flagByte & 1) == 0) {
    *flagByte = *flagByte & 0xfb;
  }
  else {
    stats_usesEntityCount(AGNT_FIELD(Agnts[agnt_id].entity, base.entity, 3));
    *flagByte = *flagByte | 4;
    owner = Agnts[agnt_id].owner;
    textFar = (char *)CONCAT22(text,_SS);
    ovr_attact_usesEntities(owner,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  }
  *flagByte = *flagByte & 0xfd;
  noCmap.ofs = 0;
  noCmap.seg = 0;
  drawAgntStats((agnt_t far *)&Agnts[agnt_id].x,noCmap,0);
  agntSeg = SEG_OF(Agnts);
  if ((*flagByte & 1) == 0) {
    agntSeg = SEG_OF(Agnts);
    allocPtr = ovr_ovc15_usesStshRealloc
                       ((char *)(uint16_t)far_ofs_u32(Agnts[agnt_id].gdata->name),
                        (uint16_t)SEG_OF(Agnts[agnt_id].gdata->name),0,0,0,0,0,0);
    textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x63b1,_SS),
                            (char *)CONCAT22(allocPtr,(char *)0x26510),agntSeg);
    drawString(textPtr,agntSeg,0);
  }
  else {
    textFar = (char *)CONCAT22(text,_SS);
    textPtr = stats_readyStatusText((byte)&text,textFar);
    textPtr = ovr_stsprintf((char *)&msg,(char *)CONCAT22(0x63c8,_SS),
                            (char *)CONCAT22(textPtr,(char *)0x26510),agntSeg);
    drawString(textPtr,agntSeg,0);
  }
  return;
}



/* 6386:1572 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

uint __cdecl16far stats_usesAlignUp4(int entityIndex)

{
  /* Re-derived: 1 when the entity is the cursor's own unit at rest - flags32 bit 2 set, x
     aligned to GfxRndSeed with y == GfxRndSeed2, targetX likewise aligned with targetY ==
     GfxRndSeed2, and both destination fields zero.  Every exported `& 0xff00` / CONCAT11 / <<8
     return was stale AH (AL is written as 0 at seven exits and 1 at one). */
  uint alignedX;
  uint cursorAligned;
  entity_t *ent;

  if ((*((uint8_t far *)&(Entities)[entityIndex].base.flags32 + 1) & 2) == 0) {
    return 0;
  }
  ent = Entities;
  alignedX = ovr_alignUp4(ent[entityIndex].base.x,0,0);
  cursorAligned = ovr_alignUp4(GfxRndSeed,0,0);
  if (alignedX != cursorAligned) {
    return 0;
  }
  if ((uint)ent[entityIndex].base.y != (uint)GfxRndSeed2) {
    return 0;
  }
  alignedX = ovr_alignUp4(ent[entityIndex].base.targetX,0,0);
  cursorAligned = ovr_alignUp4(GfxRndSeed,0,0);
  if (alignedX != cursorAligned) {
    return 0;
  }
  if ((uint)ent[entityIndex].base.targetY != (uint)GfxRndSeed2) {
    return 0;
  }
  if (ent[entityIndex].base.destX != 0) {
    return 0;
  }
  if (ent[entityIndex].base.destY != 0) {
    return 0;
  }
  return 1;
}



/* 6386:16a2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Sets the agent's entity position to the cursor cell and reports the new base. */

void __cdecl16far stats_setAgentBase(byte agntIndex)

{
  byte *flagPtr;
  int entityIndex;
  int newX;
  uint8_t *stashPtr;
  char *text;
  uint16_t widths;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  int agntData;
  uint8_t unitFlags;
  
  entityIndex = Agnts[agntIndex].owner;
  agntData = AGNT_WORD(&Agnts[agntIndex], gdata, 0);
  newX = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  (Entities)[entityIndex].base.x = newX;
  (Entities)[entityIndex].base.y = GfxRndSeed2;
  (Entities)[entityIndex].base.targetX =
       (Entities)[entityIndex].base.x;
  (Entities)[entityIndex].base.targetY = GfxRndSeed2;
  flagPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
  *flagPtr = *flagPtr | 2;
  widths = 0x2410;
  flagPtr = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
  *flagPtr = *flagPtr & 0xfa;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  ovr_alignUp4(GfxRndSeed,GfxRndSeed2,0);
  stashPtr = ovr_ovc15_usesStshRealloc
                     ((char *)*(uint16_t *)(agntData + 0x24),*(uint16_t *)(agntData + 0x26),0,0,0,0,0,0);
  text = ovr_stsprintf(msg,(char *)CONCAT22(0x6406,_SS),
                       (char *)CONCAT22(stashPtr,(char *)0x26510),widths);
  drawString(text,widths,0);
  drawAgntStats((agnt_t far *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  return;
}



/* 6386:1837 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Formats the (char *)"%s can now be called away from home." notice. */

void __cdecl16far stats_calledAwayNotice(byte agntIndex)

{
  byte *pbVar1;
  int entityIndex;
  int iVar2;
  uint8_t *puVar3;
  char *text;
  uint16_t widths;
  static char msg[64];   /* DGROUP-backed formatting buffer */
  int agntData;
  uint8_t unitFlags;
  
  entityIndex = Agnts[agntIndex].owner;
  agntData = AGNT_WORD(&Agnts[agntIndex], gdata, 0);
  iVar2 = ovr_ovc23_compute2(GfxRndSeed,GfxRndSeed2);
  (Entities)[entityIndex].base.x = iVar2;
  (Entities)[entityIndex].base.y = GfxRndSeed2;
  (Entities)[entityIndex].base.targetX =
       (Entities)[entityIndex].base.x;
  (Entities)[entityIndex].base.targetY = GfxRndSeed2;
  widths = 0x2410;
  pbVar1 = (byte *)((uint8_t *)&(Entities)[entityIndex] + 0x33);
  *pbVar1 = *pbVar1 & 0xfd;
  ovr_attact_usesEntities(entityIndex,0,0,(uint16_t)&unitFlags,(uint16_t)_SS,0,0,0,0);
  puVar3 = ovr_ovc15_usesStshRealloc
                     ((char *)*(uint16_t *)(agntData + 0x24),*(uint16_t *)(agntData + 0x26),0,0,0,0,0,0);
  text = ovr_stsprintf(msg,(char *)CONCAT22(0x644e,_SS),
                       (char *)CONCAT22(puVar3,(char *)0x26510),widths);
  drawString(text,widths,0);
  drawAgntStats((agnt_t far *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  return;
}



/* 6386:1997 */

/* Returns the agent whose owner index is the next larger one after the given agent's, or 0xff. */

undefined1 __cdecl16far stats_nextAgentByOwner(byte agntIndex)

{
  int i;                   /* agent index */
  uint bestOwner;          /* smallest owner index above the given agent's */
  undefined1 found;        /* the agent found, 0xff when none */
  
  found = 0xff;
  bestOwner = 0x7fff;
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((Agnts[agntIndex].owner < Agnts[i].owner) &&
       (Agnts[i].owner < bestOwner)) {
      bestOwner = Agnts[i].owner;
      found = (undefined1)i;
    }
  }
  return found;
}



/* 6386:1a19 */

/* Returns the agent whose owner index is the next smaller one before the given agent's, or 0xff. */

undefined1 __cdecl16far stats_prevAgentByOwner(byte agntIndex)

{
  int i;                   /* agent index */
  int bestOwner;           /* largest owner index below the given agent's */
  undefined1 found;        /* the agent found, 0xff when none */
  
  found = 0xff;
  bestOwner = -1;
  for (i = 0; i < (int)(uint)AgntCount; i = i + 1) {
    if ((Agnts[i].owner < Agnts[agntIndex].owner) &&
       (bestOwner < Agnts[i].owner)) {
      bestOwner = Agnts[i].owner;
      found = (undefined1)i;
    }
  }
  return found;
}



/* 6386:1a9b */

/* [R7] body shape: compute */

void __cdecl16far stats_compute5(byte agntIndex)

{
  ovr_ovc15_usesStExit(Agnts[agntIndex].owner);
  return;
}



/* 6386:1abe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Opens the agent detail page: ScreenMode 2, drawAgntStats and the detail text. */

void __cdecl16far stats_openAgentDetail(int agntIndex)

{
  byte gindexVal;
  int ownerIdx;
  uint audioBusy;
  
  ownerIdx = Agnts[agntIndex].owner;
  ovr_manage_openTalkWindow();
  ScreenMode = 2;
  drawAgntStats((agnt_t far *)&Agnts[agntIndex].x,far_from_u32((uint32_t)(SEG_OF(Agnts))),0);
  drawString((char *)0x620f,0x2410,0);
  gindexVal = (Entities)[ownerIdx].base.gindex;
  if (AgntGs[(uint)gindexVal].ai == '\0') {
    if ((AgntGs[(uint)gindexVal].shortName[3] == '\0') ||
       (AgntGs[(uint)gindexVal].shortName[3] == '\x04')) {
      CurMusicType = 0x43;
    }
    else if (AgntGs[(uint)gindexVal].shortName[3] == '\x02') {
      CurMusicType = 0x42;
    }
    else if ((AgntGs[(uint)gindexVal].shortName[3] == '\x05') ||
            (AgntGs[(uint)gindexVal].shortName[3] == '\x01')) {
      CurMusicType = 0x27;
    }
    else if (AgntGs[(uint)gindexVal].shortName[3] == '\x06') {
      CurMusicType = 0x28;
    }
    else if (AgntGs[(uint)gindexVal].shortName[3] == '\x03') {
      CurMusicType = 0x20;
    }
    else {
      CurMusicType = 0xc;
    }
  }
  else if ((AgntGs[(uint)gindexVal].flags3 & 8) == 0) {
    CurMusicType = 0x29;
  }
  else {
    CurMusicType = 0x59;
  }
  audioBusy = ovr_audio_isPlaying();
  if ((audioBusy & 0xff) == 0) {
    ovr_play_sfx(CONCAT11(0x24,CurMusicType),0,0);
  }
  return;
}



/* 6386:1c9f */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0006f700) overlaps instruction at (ram,0x0006f6ff)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [R4] calls ovr_alignUp4 */

byte __cdecl16far
stats_usesAlignUp42(byte agntIndex,byte gfxIndex,int16_t x,int16_t y,brect_t *rect,uint16_t type)

{
  uint32_t uVar1;
  far_t gfx;
  far_t entries_00;
  far_t gfx_00;
  far_t gfx_01;
  far_t gfx_02;
  far_t gfx_03;
  far_t gfx_04;
  char otherAgnt;          /* stats_prev/nextAgentByOwner's result */
  byte bVar3;
  bool moreHousing;        /* ovr_draw_textProvidesMoreHousing's result */
  uint uVar5;
  uint aligned;            /* alignUp4 of a coordinate, compared with the cursor */
  char *choice;            /* ovr_uiInputText's answer */
  ulong *counterPtr;       /* ovr_attact_usesBDADailyTimeCounter's result */
  uint limit;              /* 5 while leading, then AgntCount */
  uint8_t *tablePtr;        /* the byte table the answer indexes */
  uint16_t timeNow;        /* BDA_DailyTimeCounter, compared with InputEventTime */
  uint16_t *gfxPair;        /* {ofs, seg} of the graphic to load */
  int *classPair;          /* (class * 0x94) + level * 4, a two-word record */
  uint16_t *classPairW;     /* the same address, read as words */
  int ownerIdx;            /* Agnts[agntIndex].owner, an entity index */
  uint16_t uVar15;
  uint16_t pairWord;       /* the word moved out of that record */
  undefined1 slotLo;       /* low byte of the alignUp4 result */
  undefined1 slotHi;       /* high byte of it */
  uint16_t menu0Ofs;       /* "Previous" at DGROUP:0x6473 */
  uint16_t menu0Seg;       /* 0x2410, or 0 when the item is absent */
  uint16_t menu1Ofs;       /* "Next" at 0x647c */
  uint16_t menu1Seg;
  uint16_t menu2Ofs;       /* "Leader" at 0x6481 */
  uint16_t menu2Seg;
  uint16_t menu3Ofs;       /* "Help" at 0x6488 */
  uint16_t menu3Seg;
  uint16_t menu4Ofs;       /* "Done" at 0x6401 */
  uint16_t menu4Seg;
  uint8_t permTable;
  undefined1 menuCode0;    /* 4 */
  undefined1 menuCode1;    /* 5 */
  undefined1 menuCode2;    /* 7 */
  undefined1 menuCode3;    /* 9 */
  undefined1 menuCode4;    /* 6 */
  char flagB;              /* the other */
  char flagA;              /* one of the two loop flags */
  byte bStack_4;
  byte bStack_3;
  
  if (AgntCount <= agntIndex) {
    return AgntCount;
  }
  gfx_00.seg = FontHandle.seg;
  gfx_00.ofs = FontHandle.ofs;
  ovr_blitLoadRleGfx(FontHandle,far_from_u32((uint32_t)(0xa000c31d)));
  Cancelled = 0;
  ovr_attact_usesAgntFlag1();
  ovr_draw_freeRingBuffers();
  ovr_stop_audio();
  savedMenuItem = GMenuItem;
  MenuModeSaved = MenuMode;
  CurMusicType = 0xff;
L_stats_6386_1c9f_1E1D:
  for (; GCharLevelsInc != '\0'; GCharLevelsInc = GCharLevelsInc + -1) {
    bStack_3 = Agnts[agntIndex].gdata->shortName[3];
    if (bStack_3 == 0xff) {
      bStack_3 = 0;
    }
    classPair = (int *)((uint)bStack_3 * 0x94 + (uint)Agnts[agntIndex].entity->base.level * 4);
    if (*classPair != 0 || classPair[1] != 0) {
      classPairW = (uint16_t *)((uint)bStack_3 * 0x94 + (uint)Agnts[agntIndex].entity->base.level * 4);
      pairWord = *classPairW;
      /* 0149: entity + 0x12 takes table[0];  014D: entity + 0x10 takes table[1]. */
      *(uint16_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.frameIndex) = pairWord;
      *(uint16_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.health) = classPairW[1];
      pairWord = AGNT_WORD(&Agnts[agntIndex], entity, 2);
      ovr_ovc41_compute3(CONCAT13((char)((uint)pairWord >> 8),
                                  CONCAT12((char)pairWord,
                                           AGNT_WORD(&Agnts[agntIndex], entity, 0))));
    }
  }
  ownerIdx = Agnts[agntIndex].owner;
  stats_openAgentDetail((uint)agntIndex);
  pairWord = (uint16_t)((ulong)Entities >> 0x10);
  if ((Entities)[ownerIdx].base.targetY == GfxRndSeed2) {
    aligned = ovr_alignUp4((Entities)[ownerIdx].base.targetX,0,0);
    slotLo = (undefined1)aligned;
    slotHi = (undefined1)(aligned >> 8);
    aligned = ovr_alignUp4(GfxRndSeed,0,0);
    if (CONCAT11(slotHi,slotLo) == aligned) {
      ovr_ovc39_textHalflingCastle(AGNT_FIELD(Agnts[agntIndex].entity, base.entity, 3));
    }
  }
L_stats_6386_1c9f_1ECD:
  otherAgnt = stats_prevAgentByOwner(agntIndex);
  if (otherAgnt == -1) {
    menu0Seg = 0;
    menu0Ofs = 0;
  }
  else {
    menu0Seg = 0x2410;
    menu0Ofs = 0x6473;
  }
  menuCode0 = 4;
  otherAgnt = stats_nextAgentByOwner(agntIndex);
  if (otherAgnt == -1) {
    menu1Seg = 0;
    menu1Ofs = 0;
  }
  else {
    menu1Seg = 0x2410;
    menu1Ofs = 0x647c;
  }
  menuCode1 = 5;
  menuCode2 = 7;
  if ((char)AGNT_FIELD(Agnts[agntIndex].entity, base.entity, 3) == -1) {
    menu2Seg = 0;
    menu2Ofs = 0;
  }
  else {
    menu2Seg = 0x2410;
    menu2Ofs = 0x6481;
  }
  menuCode3 = 9;
  menu3Seg = 0x2410;
  menu3Ofs = 0x6488;
  menuCode4 = 6;
  menu4Seg = 0x2410;
  menu4Ofs = 0x6401;
  tablePtr = (uint8_t *)((int)&AgntAnms[0x75].halfWidth + 1);
  if (Agnts[agntIndex].gdata->ai == '\0') {
    menuBarShown = 1;
  }
  entries_00.seg = _SS;
  entries_00.ofs = (uint16_t)&menu0Ofs;
  choice = ovr_uiInputText(entries_00,5,far_from_u32((uint32_t)(0x0)),0x0,0);
  bStack_4 = (byte)choice;
  menuBarShown = 0;
  if ((bStack_4 != 0) && (bStack_4 < 10)) {
    tablePtr = &permTable;
    bStack_4 = tablePtr[(uint)choice & 0xff];
  }
  flagA = '\0';
  flagB = '\0';
  uVar5 = (uint)bStack_4;
  if (uVar5 == 6) {
    flagB = '\x01';
    flagA = '\x01';
  }
  else if (uVar5 < 7) {
    limit = 5;
    switch(uVar5) {
    case 0:
      menuBarShown = 0;
      uVar5 = 5;
      Agnts[5].x = 0x2b;
      Agnts[5].y = 2;
      do {
        bStack_3 = 1;
        while( true ) {
          uVar5 = uVar5 + 1;
          limit = (uint)AgntCount;
          if ((int)limit <= (int)uVar5) {
            ovr_agnt_usesAlignToSeg();
            bVar3 = (byte)limit;
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            ovr_agnt_usesAlignToSeg();
            return bVar3;
          }
          limit = uVar5;
          if (Agnts[uVar5].gdata->type == '\x02') break;
          if (Agnts[uVar5].gdata->type == '\x01') {
            Agnts[uVar5].x = 0x3d;
            Agnts[uVar5].y = 0x12;
          }
          else {
            if (Agnts[uVar5].gdata->type == '\v') {
              Agnts[uVar5].x = 0x56;
              Agnts[uVar5].y = 0x14;
            }
          }
        }
switchD_6000_58bf_caseD_5:
        Agnts[uVar5].x = 0x6e;
        Agnts[limit].y = 0xb;
        uVar5 = limit;
      } while( true );
    case 1:
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    case 2:
      pairWord = (uint16_t)
               ((ulong)*(uint32_t *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) >> 0x10);
      gfxPair = (uint16_t *)
                ((int)*(uint32_t *)((undefined *)&GfxFramePtrs + (uint)gfxIndex * 4) +
                (uint)bStack_3 * 4);
      gfx.seg = gfxPair[1];
      gfx.ofs = *gfxPair;
      ovr_blitGfxRect(gfx,x,y,rect,(uint8_t)type,true,(uint8_t)type,0,0,0,0,0);
      (*(uint8_t *)((uint8_t *)&(AnimSeqPtr[0].seg))) = bStack_3 + 1;
      GAnimPlaying = 1;
      return bStack_3 + 1;
    case 3:
      slotLo = 0x10;
      slotHi = 0x24;
      bStack_3 = '\0';
      do {
        moreHousing = ovr_draw_textProvidesMoreHousing();
      } while (moreHousing);
      while( true ) {
        timeNow = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
        if ((*(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2) != InputEventTime.hi) ||
           (timeNow != InputEventTime.lo)) {
          InputEventTime.hi = *(uint16_t far *)((uint8_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs) +  2);
          timeNow = *(uint16_t far *)MK_FP(BDA_DailyTimeCounter.seg, BDA_DailyTimeCounter.ofs);
          InputEventTime.lo = timeNow;
          ovr_draw_usesPrintf();
        }
        bStack_4 = ovr_draw_textProvidesMoreHousing();
        if ((bool)bStack_4) break;
        counterPtr = ovr_attact_usesBDADailyTimeCounter
                           ((ulong *)TextBlitCycle,
                            CONCAT13(slotHi,CONCAT12(slotLo,(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)))),
                            (char)(*(uint16_t *)((uint8_t *)&(TextBlitCycle) + 2)));
        if ((timeNow != 0) || ((ulong *)(uint)agntIndex <= counterPtr)) break;
      }
      if (bStack_3 != '\0') {
        ovr_miceRestoreArea((brect_t *)(BlitRects + 1),0x10);
      }
      return bStack_4;
    case 4:
      in(tablePtr);
      ovr_draw_freeRingBuffers();
      ovr_stop_audio();
      savedMenuItem = GMenuItem;
      MenuModeSaved = MenuMode;
      gfx_01.seg = nwpanel1Cut2Seg;
      gfx_01.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_01,far_from_u32((uint32_t)(0xa000e249)),0x49);
      gfx_02.seg = trianglsCut6Seg;
      gfx_02.ofs = trianglsCut6Ofs;
      ovr_blitLoadRleGfx(gfx_02,far_from_u32((uint32_t)(0xa000e249)),0x49);
      ovr_uiMainMenuLoop();
      gfx_03.seg = nwpanel1Cut2Seg;
      gfx_03.ofs = nwpanel1Cut2Ofs;
      ovr_blitLoadRleGfx(gfx_03,far_from_u32((uint32_t)(0xa000e249)),0x49);
      bVar3 = 0x10;
      gfx_04.seg = trianglsCut5Seg;
      gfx_04.ofs = trianglsCut5Ofs;
      ovr_blitLoadRleGfx(gfx_04,far_from_u32((uint32_t)(0xa000e249)),0x49);
      ovc41_usesGMenuItem();
      return bVar3;
    case 5:
      goto switchD_6000_58bf_caseD_5;
    }
  }
  else if (uVar5 == 0xfc) {
    if ((*(uint8_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.flags32 + 1) & 1) == 0) {
      stats_unreadyNotice(agntIndex);
    }
  }
  else if (uVar5 < 0xfd) {
    if (uVar5 == 7) {
      if ((char)AGNT_FIELD(Agnts[agntIndex].entity, base.entity, 3) != -1) {
        ovr_stop_audio();
        CurMusicType = 0xff;
        ovr_manage_settlementScreen(AGNT_FIELD(Agnts[agntIndex].entity, base.entity, 3));
        if (Cancelled == 0) {
          ownerIdx = Agnts[agntIndex].owner;
          stats_openAgentDetail((uint)agntIndex);
          pairWord = (uint16_t)((ulong)Entities >> 0x10);
          if ((Entities)[ownerIdx].base.targetY == GfxRndSeed2) {
            aligned = ovr_alignUp4((Entities)[ownerIdx].base.targetX,0,0);
            slotLo = (undefined1)aligned;
            slotHi = (undefined1)(aligned >> 8);
            aligned = ovr_alignUp4(GfxRndSeed,0,0);
            if (CONCAT11(slotHi,slotLo) == aligned) {
              ovr_ovc39_textHalflingCastle(AGNT_FIELD(Agnts[agntIndex].entity, base.entity, 3));
            }
          }
        }
        else {
          flagA = '\x01';
        }
      }
    }
    else {
      if (uVar5 == 8) goto L_stats_6386_1c9f_20C5;
      if (uVar5 == 9) {
        ovr_ovc50_usesUiInputText();
        flagB = '\x01';
      }
    }
  }
  else if (uVar5 == 0xfd) {
L_stats_6386_1c9f_20C5:
    uVar5 = stats_usesAlignUp4(Agnts[agntIndex].owner);
    if ((uVar5 & 0xff) == 0) {
      stats_setAgentBase(agntIndex);
    }
  }
  else if (uVar5 == 0xfe) {
    if ((*(uint8_t far *)((uint8_t far *)&Agnts[agntIndex].entity->base.flags32 + 1) & 1) != 0) {
      stats_unreadyNotice(agntIndex);
    }
    uVar5 = stats_usesAlignUp4(Agnts[agntIndex].owner);
    if ((char)uVar5 != '\0') {
      stats_calledAwayNotice(agntIndex);
    }
  }
  if ((flagA != '\0') || (flagB != '\0')) goto L_stats_6386_1c9f_22C8;
  goto L_stats_6386_1c9f_1ECD;
L_stats_6386_1c9f_22C8:
  if (flagA != '\0') {
    if (Cancelled != 0) {
      return Cancelled;
    }
    bVar3 = Cancelled;
    stats_openCastlePanel();
    ovr_ovc41_usesGMenuItem();
    return bVar3;
  }
  goto L_stats_6386_1c9f_1E1D;
}



/* 6386:22fd */

/* Opens the stats page for the agent under the screen point (video_findAgentAt) and returns whether
   one was hit. */

bool __cdecl16far stats_selectAgentAt(uint16_t x,uint16_t y)

{
  int agentIdx;
  int16_t unaff_BP;
  int16_t in_stack_00000000;
  brect_t *in_stack_00000002;
  
  agentIdx = video_findAgentAt(x,y);
  if (agentIdx != -1) {
    stats_usesAlignUp42((byte)agentIdx,(byte)agentIdx,unaff_BP,in_stack_00000000,in_stack_00000002,x);
  }
  return agentIdx != -1;
}



/* 6386:232d */

/* Opens the castle status panel with its palette and five menu bars. */

void __cdecl16far stats_openCastlePanel(void)

{
  far_t gfx;
  far_t gfx_00;
  uint16_t in_DX;
  int menuIndex;
  far_t ptr;
  far_t handle;
  far_t handle_00;
  uint8_t palette;
  stg_tmp_t *palRec;
  uint8_t dst;
  uint rectY1;
  uint rectX2;
  uint rectY2;
  void *pvStack_6;
  uint16_t gfxSeg;
  
  MiceNeedsUpdate = 1;
  pvStack_6 = ovr_stshAlloc(0xfa0f);
  ptr.seg = in_DX;
  ptr.ofs = (uint16_t)pvStack_6;
  gfxSeg = in_DX;
  ovr_alignToSeg(ptr);
  rectY1 = 7;
  rectY2 = 0xc2;
  dst = 8;
  rectX2 = 0xe2;
  ovr_driver_fillRect(8,7,0xe2,0xc2,0x0,in_DX,0,0,0,0,0);
  gfx_00.seg = fullScreenGfxSeg;
  gfx_00.ofs = fullScreenGfxOfs;
  ovr_blitGfx10(gfx_00,0,0,(brect_t *)&dst,SUB21(_SS,0),0,0);
  gfx.seg = nwpanel2Cut1Seg;
  gfx.ofs = nwpanel2Cut1Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&dst,SUB21(_SS,0),true,0,0,0,0,0,0);
  handle.seg = Lbm_nwpanel1.seg;
  handle.ofs = Lbm_nwpanel1.ofs;
  palRec = ovr_stshLoadGfx(handle);
  ovr_calcSeasonPalette(palRec->cmap,in_DX,&palette,_SS,0,0);
  ovr_driver_fillRect(dst,rectY1,rectX2,rectY2,0x0,0xa000,0,0,0,0,0);
  ovr_vgaSetPalette8bit(&palette,0);
  ovr_blitRect((brect_t *)&dst,0);
  TextBlitDstSeg = 0xa000;
  ovr_ovc28_textHalflingCastle();
  for (menuIndex = 0; menuIndex < 5; menuIndex = menuIndex + 1) {
    ovr_draw_usesBlitLoadRleGfx3(menuIndex);
    ovr_draw_menuRowBar(menuIndex,0xa000);
  }
  mapViewActive = 0xff;
  ovr_attact_usesLDIV_at_2();
  handle_00.seg = gfxSeg;
  handle_00.ofs = (uint16_t)pvStack_6;
  ovr_stshFree(handle_00);
  ovr_stop_audio();
  CurMusicType = 0xff;
  ScreenMode = 0;
  return;
}



/* 6386:24c2 */

void __cdecl16far drawString(char *text,uint16_t widths,uint16_t arg3)

{
  uint blitted;            /* characters the blit consumed */
  size_t textLen;          /* strlen of the remaining text */
  far_t gfx;
  uint8_t rect;
  uint16_t startY;         /* initial TextBlitY, from the screen mode */
  int16_t barY;            /* set by the screen-mode switch; not read by the body */
  
  _fmemmove((char far *)MK_FP(_SS,&rect),(char *)(BlitRects + 1),10);
  if (ScreenMode == '\x01') {
    startY = 0x9c;
    barY = 190;
  }
  else {
    startY = 0x75;
    if (GameRunning == false) {
      barY = 178;
    }
    else {
      barY = 150;
    }
  }
  rect = 19;
  TextBlitFlag = 1;
  TextBlitDstSeg = 0xa000;
  gfx.seg = talkwin9Cut4Seg;
  gfx.ofs = talkwin9Cut4Ofs;
  ovr_blitGfxRect(gfx,0,0,(brect_t *)&rect,(uint8_t)_SS,0,0,0,0,0,0,0);
  TextBlitY = startY;
  while( true ) {
    TextBlitX = 0x13;
    blitted = ovr_blitText(text,(byte *)CONCAT22(Font03.ofs,widths),Font03.seg,0xd7,(char)Font03.seg,
                         0xd7,0xed);
    textLen = strlen((char *)CONCAT22(widths,text));
    if (textLen <= blitted) break;
    text = text + blitted;
    TextBlitY = TextBlitY + 0xb;
  }
  ovr_clean_ring_buffer();
  return;
}


