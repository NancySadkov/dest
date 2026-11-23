"""Capture the RLE result's segment for every stsh_store argument in a file.

For each

    pfX = ovr_stshRleType2(...);
    ...
    <target>.ofs = stsh_store(<args>, (uint16_t)uVarN, &stshSegTmp);

insert `asm { mov uVarN,dx };` immediately after the RLE call and delete any
premature `uVarN = 0x195d;` / `uVarN = in_DX;` line, so the argument carries the
segment `ovr_stshRleType2` actually returned (see doc/segment_195d.md).

usage: python tmp/fix_seed_file.py <file.c> [--dry]
"""
import io
import re
import sys

path = 'src/decompiled/' + sys.argv[1]
dry = '--dry' in sys.argv
t = io.open(path, encoding='latin-1').read()

STORE = re.compile(
    r'^([ \t]*)([\w\[\]0-9x]+)\.ofs = stsh_store\((.*), \(uint16_t\)(\w+), &stshSegTmp\);[ \t]*$',
    re.M)

done = 0
missed = 0
pos = 0
while True:
    m = STORE.search(t, pos)
    if not m:
        break
    indent, target, args, segvar = m.group(1), m.group(2), m.group(3), m.group(4)
    # find the RLE call that produces the pointer used as the first argument
    first = args.split(',')[0].strip()
    first = first.replace('(uint8_t *)', '').strip()
    rle = re.search(
        r'^([ \t]*)' + re.escape(first) + r' = ovr_stshRleType2\(.*\);?[ \t]*$', t[:m.start()],
        re.M)
    if not rle:
        missed += 1
        pos = m.end()
        continue
    # already captured?
    after = t[rle.end():rle.end() + 120]
    if ('mov %s,dx' % segvar) in after or ('mov %s, dx' % segvar) in after:
        pos = m.end()
        continue
    ins = '\n%s    asm { mov %s,dx };' % (rle.group(1), segvar)
    t = t[:rle.end()] + ins + t[rle.end():]
    # delete a premature seed of the same variable, if it is a bare statement
    seed = re.search(r'^[ \t]*' + re.escape(segvar) + r' = (0x195d|in_DX);[ \t]*\n', t)
    if seed:
        t = t[:seed.start()] + t[seed.end():]
    done += 1
    pos = rle.end() + len(ins)

print('%-20s captured %d, no RLE match %d, 0x195d left %d'
      % (sys.argv[1], done, missed, t.count('0x195d')))
if not dry:
    io.open(path, 'w', encoding='latin-1', newline='\n').write(t)
