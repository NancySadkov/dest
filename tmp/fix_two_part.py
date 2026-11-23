"""Two-part transform: .ofs from stsh_store's return, .seg from the same call.

For each pair

    X.ofs = (uint16_t)ovr_stshStoreFile(A, B);
    ...
    X.seg = V;

rewrite to

    X.ofs = stsh_store(A, (uint16_t)B, &stshSegTmp);
    ...
    X.seg = stshSegTmp;

using one function-scoped scratch (the .seg assignment always precedes the next
store, verified on the first chain).  The `V` value may still be used as the next
call's argument, so those lines are left in place.

usage: python tmp/fix_two_part.py <file.c> [--dry]
"""
import io
import re
import sys

path = 'src/decompiled/' + sys.argv[1]
dry = '--dry' in sys.argv
t = io.open(path, encoding='latin-1').read()

OFS = re.compile(r'^([ \t]*)([\w\[\]0-9x]+)\.ofs = \(uint16_t\)ovr_stshStoreFile\((.*)\);[ \t]*$', re.M)
SEG = re.compile(r'^([ \t]*)([\w\[\]0-9x]+)\.seg = (\w+);[ \t]*$', re.M)

done = 0
skipped = 0
pos = 0
while True:
    m = OFS.search(t, pos)
    if not m:
        break
    indent, target, args = m.group(1), m.group(2), m.group(3)
    head, sep, tail = args.rpartition(',')
    tail = tail.strip()
    if sep and not (tail.isdigit() or tail.startswith('0x')):
        tail = '(uint16_t)' + tail
    new_ofs = '%s%s.ofs = stsh_store(%s, %s, &stshSegTmp);' % (indent, target, head, tail)
    t = t[:m.start()] + new_ofs + t[m.end():]
    # find the matching .seg for the same target within the next ~600 chars
    window = t[m.start() + len(new_ofs): m.start() + len(new_ofs) + 600]
    sm = re.search(r'^([ \t]*)' + re.escape(target) + r'\.seg = (\w+);[ \t]*$', window, re.M)
    if not sm:
        skipped += 1
        pos = m.start() + len(new_ofs)
        continue
    start = m.start() + len(new_ofs) + sm.start()
    end = m.start() + len(new_ofs) + sm.end()
    t = t[:start] + '%s%s.seg = stshSegTmp;' % (sm.group(1), target) + t[end:]
    done += 1
    pos = start

if done and 'uint16_t stshSegTmp;' not in t:
    # declare the scratch after the first local block of each function that needs it
    t = re.sub(r'^(\s*)(int|uint|uint16_t|undefined1|byte)\s+\w+;',
               lambda m: m.group(0), t, count=0)

print('%-20s converted %d pairs, skipped %d, 0x195d left %d'
      % (sys.argv[1], done, skipped, t.count('0x195d')))
if not dry:
    io.open(path, 'w', encoding='latin-1', newline='\n').write(t)
