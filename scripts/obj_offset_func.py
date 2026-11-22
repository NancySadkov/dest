"""Find which function in an object contains a given segment offset.

Parses OMF PUBDEF records (0x90 with 2-byte offsets, 0xB6 with 4-byte offsets)
so a TLINK "Fixup overflow at O33_SEG:12F6" can be attributed to a C function.
"""
import io
import sys

path = sys.argv[1]
target = int(sys.argv[2], 16)

b = open(path, "rb").read()
i = 0
pubs = []
while i + 2 < len(b):
    t = b[i]
    ln = b[i + 1] | (b[i + 2] << 8)
    body = b[i + 3:i + 3 + ln]
    i += 3 + ln
    if t not in (0x90, 0x91, 0xB6, 0xB7) or not body:
        continue
    width = 2 if t in (0x90, 0x91) else 4
    seg = None
    if body[0] == 0:
        # segment index follows (2 bytes) for 0x90/0xB6
        seg = body[1] | (body[2] << 8)
        body = body[3:]
    else:
        body = body[1:]
    # groups of: name (len byte + chars), offset (width), type index (2)
    j = 0
    while j < len(body):
        n = body[j]
        if n == 0 or j + 1 + n + width + 2 > len(body) + 2:
            break
        name = body[j + 1:j + 1 + n].decode("latin-1")
        j += 1 + n
        if j + width > len(body):
            break
        off = int.from_bytes(body[j:j + width], "little")
        j += width + 2
        pubs.append((off, name, seg))

pubs.sort()
below = [p for p in pubs if p[0] <= target]
if not below:
    print("no public symbol below", hex(target))
    raise SystemExit(0)
off, name, seg = below[-1]
nxt = next((p for p in pubs if p[0] > target), None)
print("target %s is inside %s (starts 0x%04x%s)"
      % (hex(target), name, off,
         ", next %s at 0x%04x" % (nxt[1], nxt[0]) if nxt else ""))
