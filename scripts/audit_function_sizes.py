"""Audit audit/functions_real.tsv for genuinely truncated function sizes.

A function's recorded size can be trusted if every intra-segment jump target either
  * lies inside [start, start+size), or
  * is another function's entry (a tail call), or
  * is the shared return-epilogue stub (`emptyFunction`) that Borland emits for a common `return;`.

Anything else is a jump to an address inside no known function and beyond this one's extent, which is
what a truncated size looks like.  (An earlier note claimed 5ded:10ea was truncated because it jumps to
0x1be7; that address is `emptyFunction`, i.e. a return, so the size is correct and the note was wrong.)
"""

import io
import os
import re
import struct

import capstone

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

b = io.open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
img = struct.unpack("<H", b[8:10])[0] * 16
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)

fns = []
for line in io.open(os.path.join(ROOT, "audit", "functions_real.tsv"), encoding="latin-1"):
    f = line.rstrip("\n").split("\t")
    m = re.match(r"^([0-9a-fA-F]{4}):([0-9a-fA-F]{4})$", f[0])
    if m:
        fns.append((int(m.group(1), 16), int(m.group(2), 16), int(f[2]), f[1]))
fns.sort()

entries = {(s, o) for s, o, _, _ in fns}
known_offsets_by_seg = {}
for s, o, _, _ in fns:
    known_offsets_by_seg.setdefault(s, set()).add(o)


def foff(seg, ofs):
    return img + (seg - 0x1000) * 16 + ofs


suspicious = []
checked = 0
for seg, ofs, size, name in fns:
    if size <= 0:
        continue
    start = foff(seg, ofs)
    code = b[start:start + size]
    checked += 1
    bad = []
    for ins in md.disasm(code, ofs):
        if ins.mnemonic not in ("jmp", "jz", "jnz", "je", "jne", "jl", "jle", "jg", "jge",
                                "jb", "jbe", "ja", "jae", "js", "jns", "jo", "jno", "jp", "jnp",
                                "jcxz", "loop", "loope", "loopne"):
            continue
        m = re.match(r"^0x([0-9a-f]+)$", ins.op_str.strip())
        if not m:
            continue
        t = int(m.group(1), 16)
        if ofs <= t < ofs + size:
            continue
        if (seg, t) in entries:
            continue
        if t in known_offsets_by_seg.get(seg, ()):
            continue
        bad.append(t)
    if bad:
        suspicious.append((len(bad), seg, ofs, size, name, sorted(set(bad))[:4]))

print("functions checked:", checked)
print("functions with out-of-range jump targets:", len(suspicious))
for n, seg, ofs, size, name, tgts in sorted(suspicious, reverse=True)[:15]:
    print("  %04x:%04x size=%-5d %-34s %d targets, e.g. %s"
          % (seg, ofs, size, name[:34], n, ["%04x" % t for t in tgts]))
