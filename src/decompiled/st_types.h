typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned long    dword;
typedef unsigned long    qword;
typedef char    sbyte;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    uint16;
typedef unsigned long    ulong;
typedef unsigned long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined2;
typedef unsigned long    undefined4;
typedef unsigned short    ushort;
typedef unsigned int    word;
typedef struct ui_menu_t ui_menu_t, *Pui_menu_t;

typedef struct far_t far_t, *Pfar_t;

typedef uint uint16_t;

struct far_t {
    uint16_t ofs;
    uint16_t seg;
};

struct ui_menu_t {
    struct far_t title; /* dialog title entry */
    struct far_t items[3]; /* selectable menu entries */
};

typedef struct entity_t entity_t, *Pentity_t;

typedef struct agnt_t agnt_t, *Pagnt_t;

typedef uchar uint8_t;

typedef struct agntG_t agntG_t, *PagntG_t;

typedef struct spr_t spr_t, *Pspr_t;

typedef struct anm_t anm_t, *Panm_t;

typedef char int8_t;

typedef int int16_t;

struct agntG_t { /* generic agent data, which can be shared by several agents */
    byte ai; /* 0 = player controlled, 1 = computer */
    byte type;
    sbyte nanims;
    struct spr_t *sprs[6]; /* sprite stash handles */
    sbyte extents[3][3]; /* three (left,right,height) triples, one per draw path */
    char *name;
    struct anm_t *anms; /* animation definitions */
    short sprfls[6]; /* sprite file ids */
    uint8_t dmgDice; /* number of damage dice rolled */
    uint8_t dmgSides; /* sides per die, passed to randBelow */
    byte dmgBonus; /* GUESS: byte between dmgSides (+0x39) and strength (+0x3b). The manual states Strength drives damage (manual.txt:382) and damage is dice+sides, so a bonus byte at this position is the natural inference. No code reads or writes it. */
    byte strength; /* base strength for this generic agent, copied into each instance */
    word flags; /* only ever masked */
    word flags2; /* 16-bit flag word: every access is a mask test, e.g. 6a8f:1cf3 TEST word ptr ES:[BX+0x3e],0x40 and 8699:0c44 TEST ...,0x200. */
    word flags3; /* 16-bit flag word: 6a8f:1dba TEST word ptr ES:[BX+0x40],0x100; 8699:0939 TEST ...,0x2000. */
    byte rank; /* rank level compared against agnt_3b1d_1bc1()'s ladder */
    char shortName[13]; /* GUESS: inferred from layout and manual terminology; no code reader or writer exists */
    byte hitSound; /* Hit/damage sound selector: 6a8f:1c74 compares it with 0, 0x15 and 3 and otherwise calls play_sfx(value,0) when the agent takes damage, with play_sfx values 0x3d/0x3e, 21/71 and 0x14/0x15 for the special cases. */
    uint8_t actSound; /* action sound id; 0xff = use default (4) */
    int8_t yOffset;
    uint8_t levelLimit; /* level cap: 4/8/0xc, 0xff = none; compared with entity level */
    short prtfls[6]; /* portrait file ids */
    struct far_t prts[6]; /* portrait stash handles */
    struct far_t prtpals[6]; /* portrait palettes */
    char *wpn_name;
    uint8_t wpnAmmo; /* GUESS: last byte of the class record, directly after the wpn_name far pointer (+0x90..0x93); holds 0x14 (20) in all five live class records, consistent with a per-class ammunition count. No code reads or writes it. */
};

struct spr_t {
    struct anm_t *anm; /* animation table for this sprite */
    struct far_t frames[43]; /* far pointers to the 43 frame records */
};

struct agnt_t {
    uint16_t x; /* map x */
    uint16_t y; /* map y */
    uint16_t targetX; /* requested target x (word: +4/+5) */
    uint16_t targetY; /* requested target y */
    uint16_t destX; /* destination x, 0 when the target is the current square */
    uint16_t destY; /* destination y, 0 when the target is the current square */
    uint8_t target; /* index of another agent record, 0xff = none */
    uint8_t gindex; /* index of the generic agent record (stride 0x95) */
    uint8_t animFrame; /* animation frame cursor, 0xff = none */
    uint8_t level; /* agent level, compared with per-kind thresholds and used as table[level*4] */
    uint8_t health; /* hit points, initialised to 100 and per type */
    uint8_t animVariant;
    uint8_t frameIndex; /* index into the frame table pointed to by agnt_t+0x13 */
    struct far_t *frames; /* CONCAT22(*(u16*)(i*0x34+0x15), *(u16*)(i*0x34+0x13)) is indexed by a frame id ((int)p + id*4) */
    struct entity_t *entity; /* far pointer to this agent's entity record */
    uint16_t owner; /* index of the entity that owns this agent */
    struct agntG_t *gdata; /* far pointer to this agent's generic record */
    uint8_t strength; /* per-agent combat strength, summed per faction by attact_3f0b_28eb */
    uint8_t strengthMax; /* upper bound applied to strength */
    uint8_t timer; /* countdown: reset to 5 or 10, decremented per tick */
    uint8_t combatState;
    uint8_t moveState;
    uint16_t screenX; /* agent screen x, read into CrossBlitX */
    uint16_t screenY; /* agent screen y, read into CrossBlitY */
    uint8_t teamCode; /* GUESS: byte between screenY and flags, read only as ==2 in the BothFactions branch of ovc49_agentIsActive; no writer exists. Inferred as a team/side code because the only test compares it with 2. Zero assignments; all five live agents read 0. */
    uint16_t flags; /* bit flags */
    uint8_t visited; /* set while a search pass has already examined this agent */
    uint8_t variant; /* 0/1 selector into a 0x21-stride record table */
    uint8_t faction; /* compared between records; cells of the same faction are skipped */
    uint16_t state; /* small state: 0, 0xc or 0xd selected by flags 0x80/0x100 */
    uint16_t flags32; /* 16-bit flags; bit 0x800 set by the construction switch */
};

struct entity_t {
    struct agnt_t base; /* the agent record */
    uint16_t tick; /* last GameTick this entity was updated (word at 0x34) */
    byte dir; /* sprite direction, reduced mod 6 */
};

struct anm_t { /* sprite animation definition */
    uint8_t frmid;
    int16_t sx;
    int16_t sy;
    int16_t ex;
    int16_t ey;
    uint8_t fw;
    uint8_t fh;
    int16_t x;
    int16_t y;
    int16_t maxDx; /* max per-frame x delta (clamp bound) */
    int16_t maxDy; /* max per-frame y delta (clamp bound) */
    int16_t missileDx; /* Read by ovc27_textCastsSpell (5ded:0a05) as the horizontal offset added to/subtracted from agnt->screenX when a bolt/spell is spawned (sign follows level/facing), and by ovc27_usesBlitGfxRect (5ded:0cc2) to place and advance that projectile. Nonzero only for the missile-using types read live: fighter 16, cleric 22, archer 16, evil fighter 16, manscorpion 12, evil cleric 22, vampire 18. */
    int16_t missileDy; /* Read by the same two functions. textCastsSpell does destY = (char)anm[0x15] + (char)screenY, so it is the signed vertical offset of the projectile spawn; live values are all negative (-9..-15), i.e. above the unit. */
    int16_t halfWidth; /* Horizontal half-extent. video_findAgentAt (13aa:005b) tests screenX -/+ anm[0x17] to decide whether the mouse point picks an agent, and ovc15_usesStExit2 (4207:1d87) tests agnt->x -/+ anm[0x17] when checking which map cells the unit occupies. Live values scale with creature size: 5 for humans/elves/dwarves, 8-10 for large beasts (ant, toad, wolf, griffon, scorpion), 0 for dragons/giant. */
    uint8_t eventFrame;
    uint8_t startFrame;
    uint8_t nframes;
    uint8_t flags;
    byte sfxId;
};

typedef struct bld_inst_t bld_inst_t, *Pbld_inst_t;

struct bld_inst_t {
    short ofs; /* offset half of the instance's graphics far pointer */
    short seg; /* segment half of the instance's graphics far pointer */
    byte data[8]; /* remaining record bytes */
};

typedef struct char_sheet_t char_sheet_t, *Pchar_sheet_t;

struct char_sheet_t {
    char nameText[40]; /* 40-byte name buffer at the front of the sheet. ovc30_usesFmFreeAudio zeroes the whole 0xae record with _fmemset(sheet,0,0xae) and then calls strcpy(sheet, classRecord->name) (1000:2d31) with the far string taken from ES:[gindex*0x95 + 0x26fa/0x26fc], so this field is the sheet name string. */
    byte statMask;
    byte stats[6];
    byte cls;
    byte race;
    byte hp[2]; /* hit points: bytes 0x31 and 0x32 both initialised from the hit-dice roll (current and maximum) */
    byte alignment;
    byte gender;
    struct far_t name;
    uint16_t x; /* map x (word at 0x39) */
    uint16_t y; /* map y (word at 0x3b) */
    byte active;
    byte classStr;
    uint8_t faction; /* Party/faction id of the leader, copied from the class record byte at +0x1f when the sheet is built (ovc30_createLeader: excluded = GMenuStrings[gindex*0x95 + 0x1f]). It is the value the enemy tests compare: ovc25_spyReportNotice treats an entity as an enemy when GMenuStrings[entity.gindex*0x95 + 0x1f] != sheet->faction, and ovc23_textConstructionAbandoned builds the per-side mask with 0x1000 << (sheet->faction & 0x1f).  Formerly named "excluded" after the temporary array a menu path builds from it; the readers show it is the side id, not an exclusion marker. */
    uint8_t spyReports; /* Nonzero enables the per-leader spy/intel report pass. ovc30_createLeader writes it as 1 (619c:0577 MOV byte ptr ES:[BX+0x40],0x1) and the two other leader-sheet builders store 1 at +0x40 as well. ovc25_spyReportNotice tests it at 5b66:0b5a (CMP byte ptr ES:[BX+0x40],0), computes the nearest other-faction leader at +0x49 and emits "Spies report %s heading towards stronghold."; ovc25_intelAttackingNotice requires it at 5b66:1991 (MOV AL,ES:[BX+0x40]; OR AX,AX; JNZ) before emitting "Intelligence reports %s attacking."; ovc23_textAdlibNone skips leaders with +0x40 == 0 at 5087:... (CMP byte ptr ES:[BX+0x40],0). save.003 stores 1 in this byte for its leader records. */
    uint16_t unitsNear; /* Count of this leader's own units within the spy-report radius: cleared at the start of a report pass and incremented once per entity whose party byte equals the leader index and whose hex distance is under 10 (|dx|/2 + |dy| < 10). */
    uint16_t enemiesNear; /* Count of enemy units within the same radius: incremented for entities whose class-record faction byte differs from this leader's faction when the hex distance is under 10. */
    uint16_t unitCount; /* Total number of units belonging to this leader: incremented for every entity whose party byte equals the leader index, regardless of distance. ovc22_usesPlayerCount divides it by 10 and ovc22_textDecreaseMessageDelay compares it with 0x23/0x4b/0x19 to scale the message delay. */
    uint16_t unitsOnTile; /* Count of this leader's units standing on the leader's own tile: incremented when the entity x and y equal the leader x and y. */
    uint8_t nearestEnemyLeader; /* Index of the nearest leader of a different faction, 0xff when none. Computed only when spyReports is nonzero; the loop runs over GLeaderSheets and requires leader[j].faction != leader[i].faction, keeping the smallest hex distance. */
    uint8_t reportState; /* Last spy/intel notice state: 0/1/2 are written at the end of the three notice branches, and the checks are "!= 2" before repeating "Spies report ..." and "!= 0" in ovc25_usesAlignUp47 to suppress a second report for the same entity. */
    uint16_t nearestEnemy; /* Index of the nearest enemy entity (0xffff when none), stored from the report pass and tested with "== -1" before computing distances to it. */
    short population;
    short foodProd;
    byte charIndex;
    uint8_t level;
    uint8_t levelLimit; /* max level from 4/8/0xc; 0xff = none (see OVC22_5087_056e) */
    short income;
    long gold;
    byte pad_5a[1];
    short housing;
    byte flags5d;
    byte pad_5e[2];
    long foodStored;
    uint16_t dirBudgetIn[3]; /* Three input words of the per-turn direction budget.  Written together by the ring-of-protection recompute (5087:132b store from [BP-0x28], 1346 from [BP-0x26], 1361 from [BP-0x24]); upd_usesAlignUp4 partitions them into dirBudget. */
    uint16_t dirBudget[3]; /* Per-turn inner-direction budget.  upd_usesAlignUp4 clears 6 bytes here (5087:2a9c) and assigns the three dirBudgetIn words; ovc22_usesEntities2 then loops over the three entries and, for an entity whose computed value is below the entry index, decrements the entry and sets dir = dir - dir%6 + ovc22_compute3(index), i.e. the inner (6-way) direction. */
    uint16_t ringBudgetIn[3]; /* Three input words of the per-turn ring budget, written from local_32[1..3] at 5087:1619-1623 (the accumulated per-building-type totals).  upd_usesAlignUp4 partitions them into ringBudget. */
    uint16_t ringBudget[4]; /* Per-turn outer-ring budget.  upd_usesAlignUp4 clears 6 bytes and fills the entries from ringBudgetIn; ovc22_usesEntities3 loops over four entries and, when it consumes one, rewrites dir to dir%6 + ovc22_compute3(group+1)*6, i.e. it picks the ring (the dir/6 term) rather than the inner direction. */
    long foodStorage;
    uint16_t reserved_82; /* Two-byte scratch: the ring-of-protection recompute stores 0 at 5087:... and the word from [BP-0x38] at 5087:122b (MOV word ptr ES:[BX+0x82],AX).  No instruction reads it and no table points at it. */
    byte popularity;
    byte buildType[1]; /* Building type this party's leader is placing: bldng_textBuildingNowSelect stores the value picked from the "Select type of building." list here, and callers index the bldtp_t table at 195d:010e with it (stride 0x27). */
    byte titleIndex; /* GUESS: byte at +0x86, read only by title code (manage_playerTitle 4d05:03d0/03db, manage_usesLitoa10 4d05:0c24/0c4c) and compared with 0 and 8; manage_playerTitle uses it to choose between the GPlayerTitles and GStatsLabels tables. Renamed from a second field called level, which duplicated +0x52 and does not compile.\n */
    short rank;
    byte partySlot;
    long vaultStorage;
    byte pad_8e[18];
    short maxTrade;
    short foodSold;
    byte pad_a4[10];
};

typedef struct unit_t unit_t, *Punit_t;

struct unit_t {
    byte bldType; /* index into BuildingTypes, stride 0x27 */
    byte level; /* level/count; compared < 8 */
    byte unitType; /* unit/sprite type */
    byte flags; /* bit flags */
    short x; /* map x */
    short y; /* map y */
    byte timer; /* state timer */
};

typedef struct DW DW, *PDW;

struct DW {
    uint16_t lo;
    uint16_t hi;
};

typedef struct str_t str_t, *Pstr_t;

struct str_t {
    char *ptr;
    uint16_t seg;
};

typedef struct cfax_t cfax_t, *Pcfax_t;

struct cfax_t {
    uint16_t value;
    uint8_t flag;
};

typedef struct LH LH, *PLH;

struct LH {
    uint8_t lo;
    uint8_t hi;
};

typedef struct frm_t frm_t, *Pfrm_t;

typedef ulong uint32_t;

struct frm_t { /* animation frame */
    int8_t type4; /* always 4 */
    struct frm_t *next; /* next frm_t or 0 */
    uint8_t ow;
    int8_t type2; /* always 2 */
    int16_t x;
    int16_t y;
    int8_t type1; /* always 1 */
    uint32_t sz;
    uint16_t w;
    uint16_t h;
};

typedef struct stg_t stg_t, *Pstg_t;

struct stg_t {
    uint8_t type;
    uint32_t sz;
    uint16_t w;
    uint16_t h;
};

typedef struct bldtp_t bldtp_t, *Pbldtp_t;

struct bldtp_t { /* building type */
    char *name;
    char *description;
    char *action;
    uint8_t kind;
    uint8_t size;
    uint8_t minBuildTime;
    uint8_t buildTime;
    byte flags;
    sbyte type;
    sbyte expinc;
    word flags2;
    short income;
    word cost;
    byte housing;
    uint8_t production;
    uint8_t output;
    word storage;
    uint16_t halfWidth; /* word at 0x1e: terrain-scaled span used as x +- halfWidth*2 when drawing */
    word sight;
    byte durability;
    uint8_t resource;
    byte sfxType; /* ovc23_textAdlibNone reads bldtp_t+0x24 into CurSfxType3 (a named global compared with 0x76/0x70) and special-cases the value 0x86 when level > 5 */
    uint8_t unitType;
    uint8_t flags3;
};

typedef struct unk01_t unk01_t, *Punk01_t;

struct unk01_t {
    uint8_t type;
    uint8_t pad;
    struct far_t name;
};

typedef struct grec_t grec_t, *Pgrec_t;

struct grec_t {
    word buildTimer; /* Compared with 20000 and reset to 3 (ovc23_placeBuilding). */
    word x; /* Left column of the record's span. */
    word y; /* Row of the record (compared with GfxRndSeed2). */
    byte reserved06; /* No reader or writer in the recovered code. */
    byte width; /* Span width: x0 <= x <= x0+width-1. */
    byte reserved08; /* No reader or writer in the recovered code. */
    byte party; /* Party sheet index (*(undefined4 *)(party*4)). */
    byte reserved0a; /* No reader or writer in the recovered code. */
    byte countdown; /* Decremented by ovc23_tickRecordsAt. */
    byte reserved0c; /* No reader or writer in the recovered code. */
    byte kind; /* Tested with & 3; 1 is a construction record. */
    byte done; /* Set when the countdown reaches zero. */
    word tick; /* Assigned GameTick by ovc23_tickRecordsAt. */
    byte reserved11; /* No reader or writer in the recovered code. */
};

typedef struct squarerec_t squarerec_t, *Psquarerec_t;

struct squarerec_t {
    word x; /* Square x, compared with the requested x in attact_usesSquareRecCount / unit_usesAlignUp42. */
    word y; /* Square y, compared with the requested y in the same readers. */
    byte reserved[15]; /* Copied with the whole 0x13-byte record (memcpy/fmemmove) but no individual reader in the recovered code. */
};

typedef struct cte_t cte_t, *Pcte_t;

struct cte_t {
    uint8_t state;
    struct DW ofs;
    struct DW sz;
    uint8_t info[12];
};

typedef enum lbm_type_t {
    LBM_PBM=0,
    LBM_ILBM=1
} lbm_type_t;

typedef struct voc_t voc_t, *Pvoc_t;

struct voc_t {
    uint8_t id[20];
    uint16_t data_ofs;
    uint16_t version;
    uint16_t validation;
    uint8_t blkid;
    uint8_t blksz[3];
    uint8_t freq;
    uint8_t codec;
};

typedef struct stg_tmp_t stg_tmp_t, *Pstg_tmp_t;

struct stg_tmp_t {
    uint8_t cmap[768];
    struct far_t aptr;
    struct far_t bptr;
};

typedef struct lbm_bmhd_t lbm_bmhd_t, *Plbm_bmhd_t;

struct lbm_bmhd_t {
    uint16_t w;
    uint16_t h;
    int16_t x;
    int16_t y;
    uint8_t nplanes;
    uint8_t mask;
    uint8_t enc;
    uint8_t cmapFlags;
    uint16_t colorKey;
    uint8_t xAspect;
    uint8_t yAspect;
    uint16_t pageWidth;
    uint16_t pageHeight;
};

typedef struct bios_key_t bios_key_t, *Pbios_key_t;

struct bios_key_t {
    uint8_t ascii;
    uint8_t scancode;
};

typedef struct dos_open_t dos_open_t, *Pdos_open_t;

struct dos_open_t {
    uint16_t handle;
    uint8_t error;
};

typedef struct dosver_t dosver_t, *Pdosver_t;

struct dosver_t {
    uint8_t major;
    uint8_t minor;
};

typedef struct dos_read_t dos_read_t, *Pdos_read_t;

struct dos_read_t {
    uint16_t readed;
    uint8_t error;
};

typedef struct dos_psp_t dos_psp_t, *Pdos_psp_t;

struct dos_psp_t {
    uint16_t cpm_call0;
    uint16_t himem;
    uint8_t unused1;
    uint8_t cpm_call5[5];
    struct far_t termhndlr;
    struct far_t breakhndlr;
    struct far_t crithndlr;
    uint16_t parent_psp;
    uint8_t jft[20];
    uint16_t envseg;
    struct far_t int21_ss_sp;
    uint16_t jft_size;
    struct far_t jft_pointer;
    struct far_t previous_psp;
    uint8_t call_int21[3];
    uint8_t unused2;
    uint8_t dosver[2];
    uint16_t win3x_pdb_next_psp;
    uint16_t win3x_pdb_partition;
    uint16_t win3x_pdb_next_pdb;
    uint8_t win3x_winoldapp;
    uint8_t unused3[3];
    uint16_t win3x_pdb_entry_stack;
    uint8_t unused4[2];
    uint8_t unix_call50[3];
    uint8_t unused5[2];
    uint8_t efcb1[7];
    uint8_t fcb1[16];
    uint8_t fcb2[16];
    uint8_t extra[4];
    uint8_t cmdlen;
    uint8_t cmdline[127];
};

typedef struct dos_setfileposrslt_t dos_setfileposrslt_t, *Pdos_setfileposrslt_t;

typedef long int32_t;

struct dos_setfileposrslt_t {
    int32_t position;
    uint8_t error;
};

typedef struct bofh_t bofh_t, *Pbofh_t;

struct bofh_t {
    uint16_t id0;
    uint16_t id1;
    uint32_t size;
    uint32_t stofs;
    int32_t nsegs;
};

typedef struct boseg_t boseg_t, *Pboseg_t;

struct boseg_t {
    uint16_t seg;
    uint16_t maxoff;
    uint16_t flags;
    uint16_t minoff;
};

typedef struct boinit_t boinit_t, *Pboinit_t;

struct boinit_t {
    uint8_t calltype;
    uint8_t priority;
    struct far_t addr;
};

typedef struct bosh_t bosh_t, *Pbosh_t;

struct bosh_t {
    uint16_t code;
    uint16_t saveret;
    int32_t fileofs;
    uint16_t codesz;
    uint16_t fixupsz;
    uint16_t jmpcnt;
    uint16_t link;
    uint16_t bufseg;
    uint16_t retrycnt;
    uint16_t next;
    uint16_t ems_page;
    uint16_t ems_ofs;
    uint8_t user[6];
};

typedef struct FILE FILE, *PFILE;

struct FILE {
    int16_t level;
    uint16_t flags;
    int8_t fd;
    uint8_t hold;
    uint16_t bsize;
    uint32_t buffer;
    uint32_t curp;
    uint16_t istemp;
    int16_t token;
};

typedef struct VIDEOREC VIDEOREC, *PVIDEOREC;

struct VIDEOREC {
    uint8_t windowx1;
    uint8_t windowy1;
    uint8_t windowx2;
    uint8_t windowy2;
    uint8_t attribute;
    uint8_t normattr;
    uint8_t currmode;
    uint8_t screenheight;
    uint8_t screenwidth;
    uint8_t graphicsmode;
    uint8_t snow;
    struct far_t displayptr;
};

typedef struct brect_t brect_t, *Pbrect_t;

struct brect_t {
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
    uint16_t seg;
};

typedef uint16_t size_t;

