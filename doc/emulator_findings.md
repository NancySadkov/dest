# Runtime instrumentation of STRONG.EXE

The static export cannot state what several fields *mean*: their values are data, their
readers live in overlays that Ghidra cannot decompile, or the vocabulary is simply never
written down.  This note records the second instrument: a patched DOSBox-X that runs the
original `game/STRONG.EXE` and exposes guest memory over a socket, so the structs can be
read from a live process.

## Running it

```
cd emulator
$env:SDL_AUDIODRIVER='dummy'           # the sandbox has no audio device
.\dosbox-x-mod.exe -conf strong.conf   # emulator/strong.conf mounts game\ as C: and runs STRONG.EXE DEBUG
```

`strong.conf` needs a sound card (`sbtype = sb16`) or the game prints
`Cannot find sound card.` and returns to DOS.  The first screen is the setup prompt
`ENTER: use previous configuration, SPACE: reconfigure, ESC: quit`; send `key enter`
through the harness and the game starts in VGA (mode `M_VGA`, 640x480x16).

The harness listens on `127.0.0.1:23946` and accepts line commands.  The ones that matter
for struct work:

| command | effect |
|---|---|
| `peek <lin> [n]` | hex dump, **capped at 64 bytes** |
| `dump <lin> <len> <file>` | write guest memory to a host file (any length) |
| `find <hexbytes> [start] [end]` | first hit in guest physical memory |
| `regs` | full register dump (includes DS/ES/SS) |
| `key <name>` / `type <text>` / `mclick <x> <y> <ms>` | input |
| `bp <lin>`, `until <lin>`, `step <n>`, `bpwrite <lin>` | execution / write breakpoints |

`scripts/emulator/probe.py` wraps this: `Probe().locate()` recovers the data segment and
`Probe().addr('195d:26d6')` converts a Ghidra address to a guest linear address.

## Recovering the runtime segment mapping

Ghidra's segment numbers are the MZ module's, not the runtime ones.  The runtime DGROUP is
found from a known string rather than assumed:

```
find 756E646576656C6F706564        # "undeveloped" -> hit at 0001E041
(0x1E041 - 0x1D11) >> 4 = 0x1C33    # DS, because Ghidra has that string at 2410:1d11
delta = 0x2410 - 0x1C33 = 0x7DD
```

`delta` then applies to every segment in the image: `195d:26d6 -> 0x13ED6`,
`1ef4:0000 -> 0x17170`, `1726:0000 -> 0x0F490`.  Verification is exact: the far pointers
at `1ef4:0000` (the asset-name table) are `7C 2A 32 1C`, i.e. `1C32:2A7C`, which is
`DGROUP:2A7C` in the same run.

**The delta is not constant across processes.**  Before the game is started the setup
stage runs with DGROUP = `1C32` (delta `0x7DE`); after `ENTER` the game reloads at
DGROUP = `1C33` (delta `0x7DD`).  Locate it every time.

## What the live process settled

### `AgntGs` (42 unit types) — the whole layout validated

Dumping `195d:26d6` for `42 * 0x95` bytes decodes cleanly with the recovered `agntG_t`:

| # | name | weapon | nanims | +0x94 | | # | name | weapon | +0x94 |
|---|---|---|---|---|---|---|---|---|---|
| 0 | fighter | spear | 4 | 20 | | 21 | hobgoblin | spear | 20 |
| 1 | mage | — | 4 | 20 | | 22 | goblin | short sword | 20 |
| 2 | cleric | staff,club | 5 | 20 | | 23 | manscorpion | bow | 40 |
| 3 | thief | dagger | 4 | 20 | | 24 | giant scorpion | — | 20 |
| 4 | red dragon | — | 3 | 40 | | 25 | wood golem | — | 20 |
| 5 | archer | bow | 4 | 20 | | 26 | evil mage | — | 20 |
| 6 | skeleton | short sword | 4 | 5 | | 27 | medusa | — | 40 |
| 7 | orc | morning star | 4 | 5 | | 28 | evil cleric | club | 20 |
| 8 | elf | bow | 5 | 20 | | 29 | evil thief | dagger | 20 |
| 9 | evil fighter | pike | 4 | 20 | | 30 | wight | — | 40 |
| 10 | dwarf | axe,hammer | 4 | 20 | | 31 | blue dragon | — | 40 |
| 11 | halfling | dagger | 4 | 20 | | 32 | purple worm | — | 40 |
| 12 | carrion crawler | — | 2 | 20 | | 33 | griffon | — | 20 |
| 13 | giant ant | — | 2 | 5 | | 34 | stone giant | — | 30 |
| 14 | harpy | — | 3 | 30 | | 35 | troll | — | 20 |
| 15 | dire wolf | — | 5 | 20 | | 36 | fire giant | — | 30 |
| 16 | giant bat | — | 3 | 5 | | 37 | lesser phoenix | — | 40 |
| 17 | blast spore | — | 4 | 20 | | 38 | minotaur | axe | 30 |
| 18 | kobold | dagger | 4 | 10 | | 39 | cockatrice | — | 20 |
| 19 | obsidian statue | — | 5 | 20 | | 40 | vampire | — | 40 |
| 20 | giant toad | — | 3 | 10 | | 41 | Mindark | — | 20 |

Two things this proves and one it leaves open:

- `name` at `+0x24` and `wpn_name` at `+0x90` are working far pointers into DGROUP
  (`1C33:2562 -> "fighter"`, `1C33:24DD -> "spear"`), so the field offsets of
  `agntG_t` are correct end to end, not just plausible.
- `+0x94` holds a clean 5/10/20/30/40 scale across all 42 types (humans all 20;
  dragons/vampire/medusa/wight/phoenix 40; giants/harpy/minotaur 30; kobold/toad 10;
  skeleton/orc/ant/bat 5).  **No function in the export reads it**, so it is recorded
  with this distribution and left unnamed rather than guessed.
- The static image and the live image agree byte for byte here, which also means the
  in-file table is the one the game uses (no runtime copy).

### `Agnts` (agents) — `gdata` and the open byte flags

The live array at `1726:0000` (stride 0x34) held 17 units in a running game, e.g.

```
rec 0  pos=(153,7)  type=archer  str=6/6   owner=006C faction=0  gdata=1180:29BF
rec 7  pos=(168,19) type=griffon str=25/28 owner=0064 faction=1  field_0x11=01
```

`0x1180:29BF` resolves to `AgntGs + 5*0x95`, i.e. the **archer** record, and its
`strength/strengthMax` (6/6) match that type's live values — a direct confirmation that
`agnt_t+0x1d` is the `agntG_t *gdata` the project named it.

`agnt_t+0x11` got a real lead and still no name.  The writer in `ovc15_textArena` is

```c
pfVar7 = agntCopy.frames;
if ((frames[0x1a].ofs == 0 && frames[0x1a].seg == 0) ||
    (frames[0x16].ofs == 0 && frames[0x16].seg == 0)) {
    if (frames[0x1a].ofs != 0 || frames[0x1a].seg != 0) agntCopy.field_0x11 = 1;
} else {
    agntCopy.field_0x11 = randBelow(2);
}
```

so it is decided by **which animation-table entries exist**, not by unit stats, and the
reader adds `gdata->yOffset - 0x16` to the sprite's screen y when it is non-zero.  In the
live game only the two griffons (the only flying units present) carry 1, which fits an
"elevated drawing" flag but does not prove the vocabulary.  Recorded, not renamed.

### `AgntAnms` — the three words are real data

The live table (68 records, stride 0x1e) matches the static image exactly:

| word | live values |
|---|---|
| `+0x13` | 0 (60), 7, 15, 16, 22, 28 |
| `+0x15` | 0 (60), -19, -15, -14, -10, -9, -5 |
| `+0x17` | 0 (1), 5 (49), 9 (8), 10 (8), 26 (2) |

and the records show them varying **per frame of one animation**: frames 0–2 of a cycle
hold `(0, 0, 5)` while frame 3 holds `(16, -14, 5)`.  That is the shape of a per-frame
origin offset (`+0x13`/`+0x15`) plus a constant (`+0x17`), but no code in the export reads
them, so they stay named `field_0x13/15/17` with this data recorded.

## Harness limitations found

- `peek` is capped at 64 bytes; use `dump`.
- The screenshot path is **wrong for planar VGA**: `write_bmp_text` reads text cells from
  `vga.mem.linear[0]` instead of the display page, and `write_bmp` ignores planar layout
  and `doublewidth`, so it reads `fb_width()` bytes from a 640-byte row.  Both produce
  strips.  Struct work should use memory probes; screen navigation needs the 4-plane
  decoder (`emulator/decode_vga.py` has the first attempt) or a rebuilt harness.
- Heavy commands (`dump`, `find`, `regs`) are queued to the emulation thread.  A client
  that opens a second connection while the first is still open can block the accept loop
  and make the harness appear dead; restart the emulator if `ping` stops answering.

## Second session: live validation and a correction

### `AgntGs` and `Agnts` agree with the static image

Dumping `AgntGs` from the running game gives the same 42 records as the file image, and the
`name`/`wpn_name` far pointers resolve inside DGROUP (`1C33:2562 -> "fighter"`,
`1C33:24DD -> "spear"`).  The live agent array resolves through `gdata` the same way:
`0x1180:29BF` is `AgntGs + 5*0x95`, the archer record, and the agent's `strength/strengthMax`
match that type.  This is what makes the emulator useful for the structs: it proves the field
offsets against the running program, not just against the file.

### `StatsSeg` (`217a`) is not a party-sheet table

Earlier static reading suggested the five dwords at `217a:0000` were `char_sheet_t *` entries.
The live segment shows what they are: five 192-byte records with **inline ASCII names**:

```
085A70  0C 00 A7 85 'Nasher'   ...
085B30  0C 00 A7 85 'Fordor'   ...
085BF0  0C 00 B3 85 'Kaunas'   ...
085CB0  0C 00 BF 85 'red dragon' ...
085D70  0C 00 CB 85 'Mindark'  ...
```

The first dword is a `(count, segment)` header pointing back at the record's own segment, the
name is inline at `+4`, and the stats follow.  A `char_sheet_t` has `name` as a **far pointer**
at `+0x35` and is 174 bytes, so these are the five **faction/player** records, not character
sheets.  `217a` is a segment symbol (`StatsSeg`), not a sheet array; the `217a:003F/0053/0092`
labels in the database are offsets inside the first of these records.

### The game cycles scenarios, so per-snapshot field values are not a controlled experiment

Polling the live agent array at 0.5 s intervals shows whole-array changes: positions, strengths
and even unit types jump between snapshots because the attract/demo mode loads different
scenarios.  A single `dump` therefore gives a consistent world, but *successive* dumps do not
give a time series of one world.  For time-series work the harness needs `halt`/`run` around
each dump (atomic snapshot), and the demo must be exited first.  Recorded so a later pass does
not misread a scenario switch as unit movement.

## Sampling one world: `cycles` matters, and the array can be trusted

With `cycles = max` the demo advanced so far between dumps that unit positions could not be told
apart from scenario reloads.  Setting `cycles = 6000` in `emulator/strong.conf` and dumping every
~0.6 s gave 120 consecutive snapshots of **one** scenario: all 17 agents stayed in the array, the
type multiset was constant, and positions evolved.  That is the setup for time-series work.

Two practical notes:

- A `dump` is already atomic: heavy commands run on the emulation thread, so the CPU does not
  step while the file is being written.  `halt` is *not* usable for this, because heavy commands
  only execute from the timer tick while the CPU is running (`harness_tick` returns early when
  halted) - a dump sent while halted just queues.
- The scenario starts slowly: the first ~30 snapshots had 0, then 4, then 7 agents as the demo
  built its army.  Analyse only after the count stabilises.

What the 120-snapshot run settled: `agnt_t+0x25` goes 0 -> 1 -> 2 -> 0, and `+0x11` stays 0 for
every unit of that spawn while an earlier spawn had 1 for the same types - which is why the two
fields are now named from their writers/readers rather than from position correlation.

## Negative result: the `StatsSeg` faction records are static during the demo

To test whether `agntG_t+0x94` (the 5/10/20/30/40 byte) is a score or price, 40 one-megabyte
memory dumps were taken while the demo built its army (4 -> 7 -> 17 agents), and the five
`StatsSeg` records (`Nasher`, `Fordor`, `Kaunas`, `red dragon`, `Mindark`) were compared field by
field.  **No byte of any record changed** across the whole run, so these are starting templates
or per-faction definitions, not live player state, and the demo cannot be used to correlate
`+0x94` with a score change.

The same data does confirm the records' shape: 192 bytes each, a `(count, segment)` header whose
segment points back at the record itself, and the name inline at `+4`.

## `agntG_t+0x94` is independent of every other numeric field in the record

Comparing the live 42-record table, the byte at `+0x94` equals no other field except by chance:

```
dmgDice 0/42   dmgSides 0/42   levelLimit 0/42   rank 0/42
+0x3e   0/42   +0x3f    0/42   nanims     0/42   flags-lo 0/42   strength 4/42 (coincidence)
```

while its own values are exactly `05 0A 14 1E 28` (5, 10, 20, 30, 40).  So it is not a copy of a
stat already named in the record; whatever it measures is carried only by this byte, which is why
it stays refused with the distribution recorded.

## `2410:26f7` is the new-world dialog's label table, not an AgntGs alias

Dumping the blob at runtime (DGROUP = `0x1C33`, delta `0x7DD`, i.e. linear `0x1C330 + 0x26f7`)
shows thirteen far pointers into DGROUP:

```
 0  1C33:2915  'Peaceful'      7  1C33:2952  'World 2'
 1  1C33:291E  'Aggressive'    8  1C33:295A  'World 3'
 2  1C33:2929  'Hostile'       9  1C33:2962  'World 4'
 3  1C33:2931  'Custom'       10  1C33:296A  'World 5'
 4  1C33:2938  'Return'       11  1C33:2972  'Random'
 5  1C33:293F  'First City'   12  1C33:2938  'Return'
 6  1C33:294A  'World 1'
```

These are the item labels of the "Which new world:" dialog whose strings
`saveui_configureNewWorld` uses, so the global is now **`worldMenuLabels`** (13 far pointers).

This also **withdraws the earlier "AgntGs alias" claim**.  `AgntGs` is `195d:26d6`; the code that
looked like it indexed an alias (`data_[9].ofs + 1 + g*0x95`, `GMenuStrings + g*0x95 + 0x1f`) is a
lost-segment artifact: `GMenuStrings` ends at `2410:26d7` and `GMenuStrings + 0x1f` = `0x26d6`,
which is exactly the `AgntGs` **offset** -- the real base is the far pointer to `195d:26d6` and the
segment is lost in the listing.  There is no second table and no alias to name.

## `DGROUP:5dec` at the main menu (inconclusive)

A read taken at the main menu (before a scenario is generated) gives
`5dec=0x0500, 5dee=0x0009, 5df0=0x0804, 5df2=0xFFFF, 5df4=0, 5df6=0`.  `DGROUP:0500` is a byte
table and `DGROUP:0804` lands inside the string `"returned %s"`, so the values look like pre-game
leftovers rather than initialised LEVELBAND pointers.  The `levelBandMinSeg`/`levelBandMaxSeg`
names therefore still rest only on the code's load pattern (`bandMin = LevelBandMin; uStack_4 =
5DEE;` and the matching pair for Max); confirming them needs a read during a generated scenario.

## Harness notes from the 2026-11-19 session

Working recipe (verified this session):

```
cd emulator; $env:SDL_AUDIODRIVER='dummy'; .\dosbox-x-mod.exe -conf strong.conf
# then, from another shell:
python -u scripts/emulator/probe.py          # locate -> DGROUP 1C33, delta 7DD
```

* `regs` confirms `DS=1C33 SS=257D ES=1C33` in the game stage, so the DGROUP mapping is right.
* The setup prompt is readable as text: `dump`/`peek` at `0xB8000` and take every second byte --
  `ENTER: use previous configuration, SPACE: reconfigure, ESC: quit` was visible there.
* After `key enter` the display switches to VGA graphics and `0xB8000` no longer shows the screen.
  Use a text-mode screen dump only to check the setup stage.
* **`peek` is capped at 64 bytes and each call costs about a second** -- scanning megabytes with it
  is impractical (a 64 KB scan did not finish in minutes).  Use `dump <lin> <len> <file>` instead:
  four `dump` calls of 0x40000 each produce a full 1 MB image in a few seconds.
* `find <hex>` over the full 16 MB is fast enough and is the reliable way to locate DGROUP
  (`find 756E646576656C6F706564` -> `0x1E041` here, delta `0x7DD`).
* A second client cannot connect while an earlier socket is still half-open: run one script per
  emulator session, and restart the emulator after a killed script.

### Resolved: the BSS segment is `2000 - delta`

Ghidra's BSS block is `2000:ca34 - 2000:d59f`.  Earlier this looked like an exception because
`DS:0xca34` returned overlay code; the reason is that the block is its own segment, not DS.
The uniform delta applies to it too: runtime segment = `0x2000 - 0x7DD = 0x1823`.

A 1 MB dump taken in the game stage decodes every far-pointer global in that block to real
data, which confirms the mapping:

```
GUnits    @1823:ca95 = 69C4:0004   (records 00ffff..., 0001ffff...)
GMapCells @1823:cb05 = 7516:0004
GMapFlags @1823:cb09 = 70BF:0004   (0900 1400 1400 1000 ...)
GUnitGrid @1823:cb0d = 6C68:0004
Entities  @1823:d18e = 7742:0004
```

Reads of the BSS scalars through the same base are consistent too (`EntityCount = 98`,
`GGameState = 61` for the logo screen, `AgntCount` 0..10 depending on the demo step).  Use
`bss_base = (0x2000 - delta) << 4`.

## Reaching a recorded scenario and the live agent table

The attract demo is not interactive (`MouseX` stays `-1`, `GGameInProgress = 0`).  Pressing
**ESC while the demo runs opens the main menu**, whose options are `New Game`, `Save Game`,
`Load Game`, `Delete Game`, `Quit Game`, `Message Delay`, `Great Achievements`, `Begin Play`.
The game already ships real saves: `game/STRONG.SAV/SAVE.000` .. `SAVE.005` (plus `SAVES.TXT`),
so `Load Game` can put the process into a recorded scenario.  The save/load UI runs in
`320x400`, where `mabs`'s vertical mapping is not 1:1 with the 200-line coordinate space; that
is the remaining nuisance for scripted menu clicks.

Once a scenario is live, `Agnts` (`1726:0000`, 24 records of 0x34) fills and each record's
`gdata` is `1180:26d6 + gindex*0x95`.  Reading the 42 `agntG_t` records gave their names
straight from the engine:

```
0 fighter      1 mage       2 cleric      3 thief       4 red dragon  5 archer
6 skeleton     7 orc        8 elf         9 evil fighter 10 dwarf     11 halfling
12 carrion crawler  13 giant ant  14 harpy  15 dire wolf  16 giant bat  17 blast spore
18 kobold      19 obsidian statue  20 giant toad  21 hobgoblin  22 goblin  23 manscorpion
24 giant scorpion  25 wood golem  26 evil mage  27 medusa  28 evil cleric  29 evil thief
30 wight       31 blue dragon  32 purple worm  33 griffon  34 stone giant  35 troll
36 fire giant  37 lesser phoenix  38 minotaur  39 cockatrice  40 vampire  41 Mindark
```

Each `agntG_t.anms` (+0x28) is a far pointer into `AgntAnms`; reading `nanims` records gives
the per-type animation data used to settle `anm_t+0x13/+0x15/+0x17` (see
`doc/structs_recovery.md`).

### Saved-state and queue gotchas

* `mabs <x> <y>` lands the game cursor at `MouseX = x/2`, `MouseY = y` in the 320x200 screens;
  use `mabs 2*X Y` to target game pixel `(X,Y)`.
* Heavy commands (`dump`, `regs`, `peek`) are queued while the CPU runs, and the queue only
  drains when the harness tick is active (a command such as `mabs`/`mick` sets it).  When in
  doubt: `halt`, run the heavy command (it executes synchronously), then `run`.

## Loading a shipped save (working recipe)

The main menu is keyboard-driven (`uiMenuSub`, 4528:0706): up/down move the selection and
Enter (`0x1c0d`) activates it; Escape (`0x11b`) cancels.  Mouse hover only moves the
highlight, so scripted menu navigation must use `key up` / `key down` / `key enter`.

```
ESC                              # from the attract demo -> main menu
down down enter                  # New Game, Save Game, Load Game
down x N, enter                  # save slot N (1-based)
enter                            # Yes on "Game not saved! Are you sure?"
up enter                         # Begin Play (last item, wraps from the top)
```

`game/STRONG.SAV/SAVE.000..005` are real saves; `SAVES.TXT` names them (Emperor Corak,
Prince Corak, Duke Corak, Marquis Corak, Baron ojk).  Slot 5 gives a live animated empire
(`GGameState` 8/44, `AgntCount` 1-2, `mabs` lands exactly: `MouseX = x/2`, `MouseY = y`).

### The pick window is smaller than the map

`video_usesMiceUnkState` only calls `video_findAgentAt` while `MouseX` is in `0x0c..0xde` and
`MouseY` in `0x07..0x96`; outside that it returns a map/button cursor state.  In the loaded
Emperor view the two live agents were at screen `(217,104)` and `(131,168)`, i.e. outside the
window on one axis each, so the planned `anm_t+0x17` pick-box poke could not be exercised
there.  It needs a view with a unit inside the window (scroll the minimap or load another slot).

### Live bytes behind the level-band table

A read of `DGROUP:5dec` in the loaded game gives
`LevelBandMin = 00 05 09 00`, `LevelBandMax = 04 08 FF FF` -- the level bands [0,4], [5,8],
[9,255], [0,255].  The same read shows `DGROUP:5df4/5df6` at `0x28/0x1d` during a demo, i.e.
the demo centre values move from the initial `0x58/0x24` as the attract camera advances.

## Attempt: measuring the pushed argument count for the jump-table-only functions

Target: `driver_unrleScreen` (`2d63:0aac`), `driver_zeroWords` (`2d63:0bc8`), `driver_loop3`
(`2d63:0bde`), `stshTell` (`474a:06fe`), `stshFilesize` (`474a:0aa7`), `ovc07_swapWords`
(`32c9:0000`) — the six whose only static reference is their `22xx:00xx` jump-table slot.

The harness came up cleanly and the setup prompt was passed with `key enter`:

```
> regs
EAX=00000000 ... EIP=00000438 CS=30B0 DS=1C33 SS=257D
```

`find 756E646576656C6F706564` returned `0001E041`, so the runtime DGROUP is
`(0x1E041 - 0x1D11) >> 4 = 0x1C33`, exactly the live `DS` — the segment mapping helper still works.

Searching each function's first 16 bytes found four of the six:

| function | resident copy |
|---|---|
| `ovc07_swapWords` | `0x001745D8` |
| `driver_unrleScreen` | `0x0002CB5C` |
| `driver_zeroWords` | `0x0002C288` |
| `driver_loop3` | `0x0002C59E` |
| `stshTell` | not resident |
| `stshFilesize` | not resident |

### Why the measurement did not complete

`bp 1745D8` was accepted (`OK bp 001745D8`) but never hit: after a two-second wait `EIP=00001216`,
i.e. the game was in its idle loop and none of these routines were being called.  Two further
problems make the method unreliable for this set:

1. a `find` hit is a *resident copy* of the overlay image, which need not be the segment the CPU
   executes from after an overlay swap, so a breakpoint on that address can sit in dead memory;
2. `stshTell`/`stshFilesize` live in an overlay that is not loaded at all while the game idles, so
   their code has to be caught at the moment of a load.

A successful measurement would have to: find the live segment, catch a call, read the return
address from `[SS:SP]`, break there, and decode the caller's `ADD SP,0xN`.  That is a long
interactive protocol, and its payoff is only the *pushed byte count* — the parameters stay unnamed
either way, and trimming one that the caller really pushes would corrupt the call-site rendering.

No project change was made from this attempt; it is recorded so the next session does not repeat the
same dead ends.
