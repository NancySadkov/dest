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
typedef struct far_t far_t, *Pfar_t;

typedef uint uint16_t;

struct far_t {
    uint16_t ofs;
    uint16_t seg;
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

typedef uchar uint8_t;

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
    undefined field10_0x10;
    undefined field11_0x11;
    undefined field12_0x12;
    undefined field13_0x13;
    undefined field14_0x14;
    undefined field15_0x15;
    undefined field16_0x16;
    undefined field17_0x17;
    undefined field18_0x18;
    undefined field19_0x19;
    undefined field20_0x1a;
    uint8_t nframes;
    uint8_t flags;
    undefined field23_0x1d;
};

typedef struct agnt_t agnt_t, *Pagnt_t;

struct agnt_t {
    uint16_t field0_0x0;
    uint16_t field1_0x2;
    uint8_t field2_0x4;
    uint8_t field3_0x5;
    uint16_t field4_0x6;
    uint16_t field5_0x8;
    uint16_t field6_0xa;
    uint8_t field7_0xc;
    uint8_t field8_0xd;
    uint8_t field9_0xe;
    uint8_t field10_0xf;
    uint8_t field11_0x10;
    uint8_t field12_0x11;
    uint8_t field13_0x12;
    struct DW field14_0x13;
    struct DW field15_0x17;
    uint16_t field16_0x1b;
    struct DW field17_0x1d;
    uint8_t field18_0x21;
    uint8_t field19_0x22;
    uint8_t field20_0x23;
    uint8_t field21_0x24;
    uint8_t field22_0x25;
    uint16_t field23_0x26;
    uint16_t field24_0x28;
    uint8_t field25_0x2a;
    uint16_t field26_0x2b;
    uint8_t field27_0x2d;
    uint8_t field28_0x2e;
    uint8_t field29_0x2f;
    uint16_t field30_0x30;
    uint16_t field31_0x32;
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
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    undefined field5_0x8;
    undefined field6_0x9;
    undefined field7_0xa;
    undefined field8_0xb;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    undefined field13_0x10;
    undefined field14_0x11;
    undefined field15_0x12;
    undefined field16_0x13;
    undefined field17_0x14;
    undefined field18_0x15;
    undefined field19_0x16;
    undefined field20_0x17;
    undefined field21_0x18;
    undefined field22_0x19;
    undefined field23_0x1a;
    undefined field24_0x1b;
    undefined field25_0x1c;
    undefined field26_0x1d;
    undefined field27_0x1e;
    undefined field28_0x1f;
    undefined field29_0x20;
    undefined field30_0x21;
    undefined field31_0x22;
    undefined field32_0x23;
    undefined field33_0x24;
    undefined field34_0x25;
    undefined field35_0x26;
    undefined field36_0x27;
    undefined field37_0x28;
    undefined field38_0x29;
    undefined field39_0x2a;
    undefined field40_0x2b;
    undefined field41_0x2c;
    undefined field42_0x2d;
    undefined field43_0x2e;
    undefined field44_0x2f;
    undefined field45_0x30;
    undefined field46_0x31;
    undefined field47_0x32;
    undefined field48_0x33;
    undefined field49_0x34;
    undefined field50_0x35;
    undefined field51_0x36;
    undefined field52_0x37;
    undefined field53_0x38;
    undefined field54_0x39;
    undefined field55_0x3a;
    undefined field56_0x3b;
    undefined field57_0x3c;
    undefined field58_0x3d;
    undefined field59_0x3e;
    undefined field60_0x3f;
    undefined field61_0x40;
    undefined field62_0x41;
    undefined field63_0x42;
    undefined field64_0x43;
    undefined field65_0x44;
    undefined field66_0x45;
    undefined field67_0x46;
    undefined field68_0x47;
    undefined field69_0x48;
    undefined field70_0x49;
    undefined field71_0x4a;
    undefined field72_0x4b;
    undefined field73_0x4c;
    undefined field74_0x4d;
    undefined field75_0x4e;
    undefined field76_0x4f;
    undefined field77_0x50;
    undefined field78_0x51;
    undefined field79_0x52;
    undefined field80_0x53;
    undefined field81_0x54;
    undefined field82_0x55;
    undefined field83_0x56;
    undefined field84_0x57;
    struct far_t frames[2];
    undefined field86_0x60;
    undefined field87_0x61;
    undefined field88_0x62;
    undefined field89_0x63;
    undefined field90_0x64;
    undefined field91_0x65;
    undefined field92_0x66;
    undefined field93_0x67;
    undefined field94_0x68;
    undefined field95_0x69;
    undefined field96_0x6a;
    undefined field97_0x6b;
    undefined field98_0x6c;
    undefined field99_0x6d;
    undefined field100_0x6e;
    undefined field101_0x6f;
    undefined field102_0x70;
    undefined field103_0x71;
    undefined field104_0x72;
    undefined field105_0x73;
    undefined field106_0x74;
    undefined field107_0x75;
    undefined field108_0x76;
    undefined field109_0x77;
    undefined field110_0x78;
    undefined field111_0x79;
    undefined field112_0x7a;
    undefined field113_0x7b;
    undefined field114_0x7c;
    undefined field115_0x7d;
    undefined field116_0x7e;
    undefined field117_0x7f;
    undefined field118_0x80;
    undefined field119_0x81;
    undefined field120_0x82;
    undefined field121_0x83;
    undefined field122_0x84;
    undefined field123_0x85;
    undefined field124_0x86;
    undefined field125_0x87;
    undefined field126_0x88;
    undefined field127_0x89;
    undefined field128_0x8a;
    undefined field129_0x8b;
    undefined field130_0x8c;
    undefined field131_0x8d;
    undefined field132_0x8e;
    undefined field133_0x8f;
    undefined field134_0x90;
    undefined field135_0x91;
    undefined field136_0x92;
    undefined field137_0x93;
    undefined field138_0x94;
    undefined field139_0x95;
    undefined field140_0x96;
    undefined field141_0x97;
    undefined field142_0x98;
    undefined field143_0x99;
    undefined field144_0x9a;
    undefined field145_0x9b;
    undefined field146_0x9c;
    undefined field147_0x9d;
    undefined field148_0x9e;
    undefined field149_0x9f;
    undefined field150_0xa0;
    undefined field151_0xa1;
    undefined field152_0xa2;
    undefined field153_0xa3;
    undefined field154_0xa4;
    undefined field155_0xa5;
    undefined field156_0xa6;
    undefined field157_0xa7;
    undefined field158_0xa8;
    undefined field159_0xa9;
    undefined field160_0xaa;
    undefined field161_0xab;
    undefined field162_0xac;
    undefined field163_0xad;
    undefined field164_0xae;
    undefined field165_0xaf;
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
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
    undefined field7_0x10;
    int8_t type; /* -1=towers|storage,0=keep|ruin,2=jeweler,4=bath,16=masonry */
    int8_t expinc;
    undefined field10_0x13;
    undefined field11_0x14;
    int16_t income;
    uint16_t cost;
    uint8_t housing;
    undefined field15_0x1a;
    undefined field16_0x1b;
    uint16_t storage;
    undefined field18_0x1e;
    undefined field19_0x1f;
    uint16_t sight;
    uint8_t durability;
    int8_t tier;
    undefined field23_0x24;
    undefined field24_0x25;
    undefined field25_0x26;
};

typedef struct unk01_t unk01_t, *Punk01_t;

struct unk01_t {
    uint8_t field0_0x0;
    uint8_t field1_0x1;
    struct far_t field2_0x2;
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
    undefined field4_0x1b;
    undefined field5_0x1c;
    undefined field6_0x1d;
    undefined field7_0x1e;
    undefined field8_0x1f;
    undefined field9_0x20;
    undefined field10_0x21;
    undefined field11_0x22;
    undefined field12_0x23;
    char *name;
    struct anm_t *anms;
    int16_t sprfls[6]; /* sprite file ids; 0,1,2=male; 3,4,5=female */
    undefined field16_0x38;
    undefined field17_0x39;
    undefined field18_0x3a;
    undefined field19_0x3b;
    undefined field20_0x3c;
    undefined field21_0x3d;
    undefined field22_0x3e;
    undefined field23_0x3f;
    undefined field24_0x40;
    undefined field25_0x41;
    undefined field26_0x42;
    undefined field27_0x43;
    undefined field28_0x44;
    undefined field29_0x45;
    undefined field30_0x46;
    undefined field31_0x47;
    undefined field32_0x48;
    undefined field33_0x49;
    undefined field34_0x4a;
    undefined field35_0x4b;
    undefined field36_0x4c;
    undefined field37_0x4d;
    undefined field38_0x4e;
    undefined field39_0x4f;
    undefined field40_0x50;
    undefined field41_0x51;
    undefined field42_0x52;
    undefined field43_0x53;
    int16_t prtfls[6]; /* portrait file ids; 0,1,2=male; 3,4,5=female */
    struct far_t prts[6]; /* portrait stash handles */
    struct far_t prtpals[6]; /* portrait palettes */
    char *wpn_name;
    undefined field48_0x94;
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

