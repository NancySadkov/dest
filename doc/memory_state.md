# In-game memory-state comparison

The built EXE is compared against the original at the in-game map screen by
dumping DGROUP (`DS:0000..9499`) through the debug server.

## Determinism setup

`scripts/fbov/boot_game.py` now starts every run with:

```text
[dos]
synchronize time = false

[autoexec]
date 01-01-1993
time 00:00:00
```

and `[cpu] cycles = fixed 20000`.

It also validates that the dump is really DGROUP by checking `_psp`
(DGROUP offset `0x7B`); a valid run shows `DS=1C32 PSP=0812`.

## Diffing bytes

Earlier natural runs differed at these offsets:

| Offset | Symbol | Source |
|---:|---|---|
| `0x0081` | `_StartTime` | program start clock ticks |
| `0x7144` | `GameRunning` | loop/state timing |
| `0x8934` | `bdata_at_` | Borland C0 internal / timer state |
| `0x8986` | `InputEventTime` | BIOS timer tick of last input |
| `0x898A` | `TextBlitCycle` | text/blit animation counter |
| `0x9001` | `DAT_2000_d101` | agent/timer state word |
| `0x9070` | `GDailyTimeCounter` | game clock ticks |

## Results with synthesized clock

| Comparison | Differing bytes |
|---|---:|
| original vs original | 6 |
| functional C EXE vs original | 5 |

The remaining bytes are only:

```text
0x7144 GameRunning        (0/1, only between two original runs)
0x8934 bdata_at_
0x8986 InputEventTime
0x898A TextBlitCycle
0x9001 DAT_2000_d101
0x9070 GDailyTimeCounter
```

All are elapsed-time counters or state flags and differ by ±1 depending on the
emulated tick at capture.  `_StartTime` now matches exactly, confirming that
the synthesized date/time removed the start-clock factor.

## Deterministic harness

`scripts/fbov/boot_game_det.py` removes the final timing variance:

1. halt at the sound prompt,
2. reset `_StartTime`, the BIOS tick counter and all timer fields above,
3. advance an exact instruction count (`step 20000000`) with the harness,
4. dump DGROUP at the map screen.

Result:

```text
map after 1 step(s)
map after 1 step(s)
DGROUP differing bytes: 0
```

Both the original and the functional C EXE now reach the map screen after the
same instruction count and produce **identical DGROUP state**, with no
run-to-run differences.  The reset fields are all clock/timer/state values, so
this removes the butterfly-effect source without touching game logic.
