#!/usr/bin/env python3
"""G3 reference audit for the fresh FBOV model.

Reconstructs the same block map as scripts/ghidra/BuildFbovModel.java and
checks every MZ relocation and every FBOV fixup:
  - the fixup/relocation site is inside a modelled block;
  - the target segment is modelled;
  - null targets (0) are reported separately.

Exit code 0 means no unexplained references.
"""
import json
import os
import sys

STATIC_BASE = 0x1000
SEGTABLE_SEG = 0x2277
DGROUP = 0x2410
OVRDATA = 0x225D

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
MANIFEST = os.path.join(ROOT, "doc", "fbov_manifest.json")


def build_blocks(m):
    """Load the exact block layout emitted by scripts/fbov/model.py."""
    import csv
    ranges = {}
    starts = {}
    path = os.path.join(ROOT, "doc", "fbov_blocks.csv")
    with open(path, newline="", encoding="ascii") as f:
        for row in csv.DictReader(f):
            s = int(row["static_seg"], 16)
            start = s * 16 + int(row["start"], 16)
            size = int(row["size"], 16)
            end = start + size
            ranges.setdefault(s, []).append((start, end))
            if s not in starts or start < starts[s]:
                starts[s] = start
    return ranges, starts


def main():
    if not os.path.isfile(MANIFEST):
        print("missing", MANIFEST)
        return 1
    m = json.load(open(MANIFEST))
    ranges, starts = build_blocks(m)
    all_ranges = [r for rs in ranges.values() for r in rs]

    def in_any(lin):
        return any(lo <= lin < hi for lo, hi in all_ranges)

    errors = []
    notes = []
    rel_ok = rel_null = rel_bad_site = rel_bad_target = 0
    for r in m["relocs"]:
        site_static = STATIC_BASE + r["seg"]
        site_lin = site_static * 16 + r["ofs"]
        if not in_any(site_lin):
            rel_bad_site += 1
            errors.append("reloc site outside every block: %04X:%04X" %
                          (site_static, r["ofs"]))
            continue
        t = r["target_seg"]
        if not t:
            rel_null += 1
            notes.append("reloc null target: %04X:%04X" %
                         (r["seg"], r["ofs"]))
            continue
        if t not in ranges:
            rel_bad_target += 1
            errors.append("reloc target not modelled: %04X:%04X -> %04X" %
                          (r["seg"], r["ofs"], t))
            continue
        rel_ok += 1

    fix_ok = fix_bad_site = fix_bad_target = 0
    for f in m["fixups"]:
        code_seg = f["overlay_code_seg"]
        site_lin = code_seg * 16 + f["site_ofs"]
        if not in_any(site_lin):
            fix_bad_site += 1
            errors.append("fixup site outside every block: %04X:%04X" %
                          (code_seg, f["site_ofs"]))
            continue
        t = f["target_seg"]
        if not t or t not in ranges:
            fix_bad_target += 1
            errors.append("fixup target not modelled: %04X:%04X -> %s" %
                          (code_seg, f["site_ofs"],
                           "%04X" % t if t else "null"))
            continue
        fix_ok += 1

    if DGROUP not in ranges:
        errors.append("DGROUP 0x2410 has no block")
    if OVRDATA not in ranges:
        errors.append("_OVRDATA_ 0x225D has no block")

    print("blocks:", len(ranges))
    print("relocs: ok=%d null=%d bad_site=%d bad_target=%d" %
          (rel_ok, rel_null, rel_bad_site, rel_bad_target))
    print("fixups: ok=%d bad_site=%d bad_target=%d" %
          (fix_ok, fix_bad_site, fix_bad_target))
    print("errors:", len(errors), "notes:", len(notes))
    for e in errors[:40]:
        print("  ERROR", e)
    for n in notes[:20]:
        print("  NOTE ", n)

    report = {
        "blocks": {("%04X" % k): v for k, v in sorted(ranges.items())},
        "relocs": {"ok": rel_ok, "null": rel_null,
                   "bad_site": rel_bad_site, "bad_target": rel_bad_target},
        "fixups": {"ok": fix_ok, "bad_site": fix_bad_site,
                   "bad_target": fix_bad_target},
        "errors": errors,
        "notes": notes,
    }
    out = os.path.join(ROOT, "doc", "audit_report.json")
    json.dump(report, open(out, "w"), indent=1)
    print("wrote", out)
    return 1 if errors else 0


if __name__ == "__main__":
    sys.exit(main())
