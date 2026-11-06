#!/usr/bin/env python3
"""Dump compiled function bytes from an OMF OBJ (no original compare)."""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "scripts", "fbov"))
from byte_match import parse_omf

obj, name = sys.argv[1], sys.argv[2]
segdata, pub = parse_omf(obj)
if name not in pub:
    print("symbols:", sorted(pub))
    raise SystemExit("not found")
seg, off = pub[name]
code = bytes(segdata.get(seg, b""))
print("symbol %s seg=%d off=%04X len=%d" % (name, seg, off, len(code) - off))
print(code[off:off + int(sys.argv[3], 0) if len(sys.argv) > 3 else None].hex(" "))
