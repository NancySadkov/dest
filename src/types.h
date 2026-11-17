typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned long    dword;
typedef unsigned long    qword;
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
typedef struct entity_t entity_t, *Pentity_t;

typedef struct agnt_t agnt_t, *Pagnt_t;

typedef uint uint16_t;

typedef uchar uint8_t;

typedef struct DW DW, *PDW;

struct DW {
    uint16_t lo;
    uint16_t hi;
};

struct agnt_t {
    uint16_t x; /* map x */
    uint16_t y; /* map y */
    uint8_t field_0x4;
    uint8_t field_0x5;
    uint16_t field_0x6;
    uint16_t field_0x8;
    uint16_t field_0xa;
    uint8_t field_0xc;
    uint8_t field_0xd;
    uint8_t field_0xe;
    uint8_t field_0xf;
    uint8_t field_0x10;
    uint8_t field_0x11;
    uint8_t field_0x12;
    struct DW field_0x13;
    struct DW field_0x17;
    uint16_t field_0x1b;
    struct DW field_0x1d;
    uint8_t field_0x21;
    uint8_t field_0x22;
    uint8_t field_0x23;
    uint8_t field_0x24;
    uint8_t field_0x25;
    uint16_t field_0x26;
    uint16_t field_0x28;
    uint8_t field_0x2a;
    uint16_t field_0x2b;
    uint8_t field_0x2d;
    uint8_t field_0x2e;
    uint8_t field_0x2f;
    uint16_t field_0x30;
    uint16_t field_0x32;
};

struct entity_t {
    struct agnt_t base; /* agnt_t prefix */
    byte reserved[3];
};

typedef struct char_sheet_t char_sheet_t, *Pchar_sheet_t;

typedef struct far_t far_t, *Pfar_t;

struct far_t {
    uint16_t ofs;
    uint16_t seg;
};

struct char_sheet_t {
    byte pad_0[40];
    byte statMask; /* enabled-stat bit mask */
    byte stats[6]; /* six ability scores */
    byte cls; /* class index, -1 = none */
    byte race; /* race index */
    byte pad_31[2];
    byte alignment; /* index into GAlignmentsNames */
    byte gender; /* gender index */
    struct far_t name; /* far pointer to character name */
    byte pad_39[4];
    byte active; /* non-zero if the record is in play */
    byte classStr; /* class string index */
    byte excluded; /* non-zero excludes record from population average */
    byte pad_40[13];
    short population; /* town population */
    short foodProd; /* food production */
    byte charIndex; /* index into the character table, -1 = none */
    byte pad_52[2];
    short income; /* income */
    long gold; /* gold on hand */
    byte pad_5a[1];
    short housing; /* housing capacity */
    byte flags5d; /* UI/character flags */
    byte pad_5e[2];
    long foodStored; /* food in storage */
    byte pad_64[26];
    long foodStorage; /* food storage capacity */
    byte pad_82[2];
    byte popularity; /* popularity percentage */
    byte pad_85[1];
    byte level; /* level/type (<9 checks) */
    short rank; /* rank (clamped to 10 for Fund Access) */
    byte partySlot; /* party slot index, 0xff = none */
    long vaultStorage; /* vault storage */
    byte pad_8e[18];
    short maxTrade; /* maximum trade */
    short foodSold; /* food sold */
    byte pad_a4[10];
};

typedef struct ui_menu_t ui_menu_t, *Pui_menu_t;

struct ui_menu_t {
    struct far_t title; /* dialog title entry */
    struct far_t items[3]; /* selectable menu entries */
};

typedef struct bld_inst_t bld_inst_t, *Pbld_inst_t;

struct bld_inst_t {
    short field0; /* first 16-bit field */
    short field2; /* second 16-bit field */
    byte data[8]; /* remaining record bytes */
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

typedef struct anm_t anm_t, *Panm_t;

typedef int int16_t;

struct anm_t { /* sprite animation definition */
    uint8_t frmid; /* index into spr_t frames */
    int16_t sx;
    int16_t sy;
    int16_t ex;
    int16_t ey;
    uint8_t fw;
    uint8_t fh;
    int16_t x;
    int16_t y;
    uint8_t ow;
    byte field_0x10;
    byte field_0x11;
    byte field_0x12;
    byte field_0x13;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
    byte field_0x18;
    byte field_0x19;
    byte field_0x1a;
    uint8_t nframes;
    uint8_t flags;
    byte field_0x1d;
};

typedef struct frm_t frm_t, *Pfrm_t;

typedef char int8_t;

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

typedef struct spr_t spr_t, *Pspr_t;

struct spr_t {
    struct anm_t *anm;
    byte field_0x4;
    byte field_0x5;
    byte field_0x6;
    byte field_0x7;
    byte field_0x8;
    byte field_0x9;
    byte field_0xa;
    byte field_0xb;
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    byte field_0x10;
    byte field_0x11;
    byte field_0x12;
    byte field_0x13;
    byte field_0x14;
    byte field_0x15;
    byte field_0x16;
    byte field_0x17;
    byte field_0x18;
    byte field_0x19;
    byte field_0x1a;
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
    byte field_0x20;
    byte field_0x21;
    byte field_0x22;
    byte field_0x23;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
    byte field_0x27;
    byte field_0x28;
    byte field_0x29;
    byte field_0x2a;
    byte field_0x2b;
    byte field_0x2c;
    byte field_0x2d;
    byte field_0x2e;
    byte field_0x2f;
    byte field_0x30;
    byte field_0x31;
    byte field_0x32;
    byte field_0x33;
    byte field_0x34;
    byte field_0x35;
    byte field_0x36;
    byte field_0x37;
    byte field_0x38;
    byte field_0x39;
    byte field_0x3a;
    byte field_0x3b;
    byte field_0x3c;
    byte field_0x3d;
    byte field_0x3e;
    byte field_0x3f;
    byte field_0x40;
    byte field_0x41;
    byte field_0x42;
    byte field_0x43;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
    byte field_0x48;
    byte field_0x49;
    byte field_0x4a;
    byte field_0x4b;
    byte field_0x4c;
    byte field_0x4d;
    byte field_0x4e;
    byte field_0x4f;
    byte field_0x50;
    byte field_0x51;
    byte field_0x52;
    byte field_0x53;
    byte field_0x54;
    byte field_0x55;
    byte field_0x56;
    byte field_0x57;
    struct far_t frames[2];
    byte field_0x60;
    byte field_0x61;
    byte field_0x62;
    byte field_0x63;
    byte field_0x64;
    byte field_0x65;
    byte field_0x66;
    byte field_0x67;
    byte field_0x68;
    byte field_0x69;
    byte field_0x6a;
    byte field_0x6b;
    byte field_0x6c;
    byte field_0x6d;
    byte field_0x6e;
    byte field_0x6f;
    byte field_0x70;
    byte field_0x71;
    byte field_0x72;
    byte field_0x73;
    byte field_0x74;
    byte field_0x75;
    byte field_0x76;
    byte field_0x77;
    byte field_0x78;
    byte field_0x79;
    byte field_0x7a;
    byte field_0x7b;
    byte field_0x7c;
    byte field_0x7d;
    byte field_0x7e;
    byte field_0x7f;
    byte field_0x80;
    byte field_0x81;
    byte field_0x82;
    byte field_0x83;
    byte field_0x84;
    byte field_0x85;
    byte field_0x86;
    byte field_0x87;
    byte field_0x88;
    byte field_0x89;
    byte field_0x8a;
    byte field_0x8b;
    byte field_0x8c;
    byte field_0x8d;
    byte field_0x8e;
    byte field_0x8f;
    byte field_0x90;
    byte field_0x91;
    byte field_0x92;
    byte field_0x93;
    byte field_0x94;
    byte field_0x95;
    byte field_0x96;
    byte field_0x97;
    byte field_0x98;
    byte field_0x99;
    byte field_0x9a;
    byte field_0x9b;
    byte field_0x9c;
    byte field_0x9d;
    byte field_0x9e;
    byte field_0x9f;
    byte field_0xa0;
    byte field_0xa1;
    byte field_0xa2;
    byte field_0xa3;
    byte field_0xa4;
    byte field_0xa5;
    byte field_0xa6;
    byte field_0xa7;
    byte field_0xa8;
    byte field_0xa9;
    byte field_0xaa;
    byte field_0xab;
    byte field_0xac;
    byte field_0xad;
    byte field_0xae;
    byte field_0xaf;
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
    byte field_0xc;
    byte field_0xd;
    byte field_0xe;
    byte field_0xf;
    byte field_0x10;
    int8_t type; /* -1=towers|storage,0=keep|ruin,2=jeweler,4=bath,16=masonry */
    int8_t expinc;
    byte field_0x13;
    byte field_0x14;
    int16_t income;
    uint16_t cost;
    uint8_t housing;
    byte field_0x1a;
    byte field_0x1b;
    uint16_t storage;
    byte field_0x1e;
    byte field_0x1f;
    uint16_t sight;
    uint8_t durability;
    int8_t tier;
    byte field_0x24;
    byte field_0x25;
    byte field_0x26;
};

typedef struct unk01_t unk01_t, *Punk01_t;

struct unk01_t {
    uint8_t type;
    uint8_t pad;
    struct far_t name;
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

typedef struct agntG_t agntG_t, *PagntG_t;

struct agntG_t { /* generic agent data, which can be shared by several agents */
    uint8_t ai; /* 0=player controlled, 1=computer controlled */
    uint8_t type;
    int8_t nanims;
    struct spr_t *sprs[6]; /* sprite stash handles */
    byte field_0x1b;
    byte field_0x1c;
    byte field_0x1d;
    byte field_0x1e;
    byte field_0x1f;
    byte field_0x20;
    byte field_0x21;
    byte field_0x22;
    byte field_0x23;
    char *name;
    struct anm_t *anms;
    int16_t sprfls[6]; /* sprite file ids; 0,1,2=male; 3,4,5=female */
    byte field_0x38;
    byte field_0x39;
    byte field_0x3a;
    byte field_0x3b;
    byte field_0x3c;
    byte field_0x3d;
    byte field_0x3e;
    byte field_0x3f;
    byte field_0x40;
    byte field_0x41;
    byte field_0x42;
    byte field_0x43;
    byte field_0x44;
    byte field_0x45;
    byte field_0x46;
    byte field_0x47;
    byte field_0x48;
    byte field_0x49;
    byte field_0x4a;
    byte field_0x4b;
    byte field_0x4c;
    byte field_0x4d;
    byte field_0x4e;
    byte field_0x4f;
    byte field_0x50;
    byte field_0x51;
    byte field_0x52;
    byte field_0x53;
    int16_t prtfls[6]; /* portrait file ids; 0,1,2=male; 3,4,5=female */
    struct far_t prts[6]; /* portrait stash handles */
    struct far_t prtpals[6]; /* portrait palettes */
    char *wpn_name;
    byte field_0x94;
};

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

typedef uint16_t size_t;

typedef struct brect_t brect_t, *Pbrect_t;

struct brect_t {
    int16_t x;
    int16_t y;
    int16_t w;
    int16_t h;
    uint16_t seg;
};

