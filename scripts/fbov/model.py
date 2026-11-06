#!/usr/bin/env python3
"""Independent Borland FBOV manifest builder.

This deliberately does not use mzap and does not use the old Ghidra project.
It follows the format described in tools/devroomm/doc/bcpp_overlays.txt and
the reversed overlay manager in tools/devroomm/src/ovrman.c.

Outputs:
  doc/fbov_manifest.json
  doc/fbov_segments.csv
  doc/fbov_overlays.csv
  doc/fbov_fixups.csv
  doc/fbov_relocs.csv

Run from the repo root or pass --exe.
"""
import argparse
import csv
import json
import os
import struct
import sys

FBOV_CODE = 1
FBOV_OVR = 2
FBOV_DATA = 4
FIXUP_FUNREF = 1
STATIC_BASE = 0x1000  # linker first-segment base; see plan.md


def u16(data, off):
    return struct.unpack_from("<H", data, off)[0]


def i32(data, off):
    return struct.unpack_from("<i", data, off)[0]


def parse(path):
    data = open(path, "rb").read()
    if len(data) < 0x1C:
        raise SystemExit("not an MZ file")

    (magic, cblp, cp, crlc, cparhdr, minalloc, maxalloc, ss, sp,
     csum, ip, cs, lfarlc, ovno) = struct.unpack_from("<14H", data, 0)
    if magic != 0x5A4D:
        raise SystemExit("not an MZ file")

    full_pages = cp - 1 if cblp else cp
    loaded_sz = full_pages * 512 + cblp
    start_ofs = cparhdr * 16

    # Locate FBOV. It is 16-byte aligned after the load image.
    fbovofs = (loaded_sz + 15) & ~15
    found = None
    for off in range(fbovofs, min(len(data) - 16, fbovofs + 0x1000), 16):
        if data[off:off + 4] == b"FBOV":
            found = off
            break
    if found is None:
        raise SystemExit("FBOV not found near 0x%X" % fbovofs)
    fbovofs = found

    size, stofs, nsegs = struct.unpack_from("<IIi", data, fbovofs + 4)
    if nsegs <= 0 or nsegs > 0x10000:
        raise SystemExit("bad segment count %d" % nsegs)

    segments = []
    for i in range(nsegs):
        off = stofs + i * 8
        if off + 8 > len(data):
            raise SystemExit("segment table runs past EOF")
        s, maxoff, flags, minoff = struct.unpack_from("<HHHH", data, off)
        segments.append({
            "index": i,
            "seg": s,
            "maxoff": maxoff,
            "flags": flags,
            "minoff": minoff,
            "class": ("OVR" if flags & FBOV_OVR else
                      "CODE" if flags & FBOV_CODE else "DATA"),
            "static_seg": STATIC_BASE + s,
            "is_overlay": bool(flags & FBOV_OVR),
        })

    # MZ relocations.
    relocs = []
    for i in range(crlc):
        off = lfarlc + i * 4
        if off + 4 > len(data):
            break
        r_ofs, r_seg = struct.unpack_from("<HH", data, off)
        site = start_ofs + r_seg * 16 + r_ofs
        target = u16(data, site) if site + 2 <= len(data) else None
        relocs.append({
            "index": i, "seg": r_seg, "ofs": r_ofs,
            "file_offset": site, "target_seg": target,
        })

    overlays = []
    fixups = []
    for i, e in enumerate(segments):
        if not e["is_overlay"]:
            continue
        hdr_off = start_ofs + e["seg"] * 16
        if hdr_off + 0x20 > len(data):
            continue
        code2 = data[hdr_off:hdr_off + 2]
        saveret = u16(data, hdr_off + 2)
        fileofs = i32(data, hdr_off + 4)
        codesz = u16(data, hdr_off + 8)
        fixupsz = u16(data, hdr_off + 10)
        jmpcnt = u16(data, hdr_off + 12)
        link = u16(data, hdr_off + 14)
        bufseg = u16(data, hdr_off + 16)
        retrycnt = u16(data, hdr_off + 18)
        nxt = u16(data, hdr_off + 20)
        ems_page = u16(data, hdr_off + 22)
        ems_ofs = u16(data, hdr_off + 24)

        code_off = fbovofs + 16 + fileofs
        # Canonical analysis segment (same convention mzap used for the merged
        # image): load-module-relative 16-byte unit.
        code_seg = (code_off - start_ofs) >> 4
        code_disp = (code_off - start_ofs) & 0xF

        ov = {
            "index": i, "header_seg": e["seg"],
            "header_file_offset": hdr_off,
            "fileofs": fileofs, "code_file_offset": code_off,
            "code_seg": code_seg, "code_disp": code_disp,
            "codesz": codesz, "fixupsz": fixupsz, "jmpcnt": jmpcnt,
            "saveret": saveret, "link": link, "bufseg": bufseg,
            "retrycnt": retrycnt, "next": nxt,
            "ems_page": ems_page, "ems_ofs": ems_ofs,
        }
        overlays.append(ov)

        # Trampolines.
        for j in range(jmpcnt):
            t = hdr_off + 0x20 + j * 5
            if t + 5 > len(data):
                break
            tcode = data[t:t + 2]
            tofs = u16(data, t + 2)
            ov.setdefault("trampolines", []).append({
                "index": j, "header_off": 0x20 + j * 5,
                "code": tcode.hex(), "target_ofs": tofs,
            })

        # Fixups.
        ftab = code_off + codesz
        for j in range(fixupsz // 2):
            q = u16(data, ftab + j * 2)
            site = code_off + q
            if site + 2 > len(data):
                continue
            sf = u16(data, site)
            flags = sf & 7
            target = sf >> 3
            target_info = segments[target] if target < len(segments) else None
            target_seg = target_info["static_seg"] if target_info else None
            f = {
                "overlay_header_seg": e["seg"],
                "overlay_code_seg": code_seg,
                "index": j, "code_offset": q,
                "site_seg": code_seg,
                "site_ofs": code_disp + q,
                "site_file_offset": site,
                "sf": sf, "flags": flags, "target_index": target,
                "target_seg": target_seg,
                "target_class": target_info["class"] if target_info else None,
                "funref": bool(flags & FIXUP_FUNREF),
            }
            if f["funref"]:
                # __OvrFixupFunref reads the function offset at p[4].
                f["funref_offset_word"] = u16(data, site + 4) if site + 6 <= len(data) else None
                f["trampoline_offset"] = None
                # Find the matching trampoline in the target header segment.
                if target_seg is not None:
                    th = start_ofs + target_seg * 16
                    for k in range(jmpcnt):
                        tofs = u16(data, th + 0x20 + k * 5 + 2)
                        if tofs == f["funref_offset_word"]:
                            f["trampoline_offset"] = 0x20 + k * 5
                            break
            fixups.append(f)

    manifest = {
        "exe": os.path.abspath(path),
        "file_size": len(data),
        "mz": {
            "cblp": cblp, "cp": cp, "crlc": crlc, "cparhdr": cparhdr,
            "ss": ss, "sp": sp, "cs": cs, "ip": ip, "lfarlc": lfarlc,
            "start_ofs": start_ofs, "loaded_sz": loaded_sz,
        },
        "fbov": {
            "offset": fbovofs, "size": size, "stofs": stofs, "nsegs": nsegs,
        },
        "segments": segments,
        "overlays": overlays,
        "fixups": fixups,
        "relocs": relocs,
        "dgroup": {
            "data": 0x2410,
            "ovrdata": 0x225d,
        },
    }
    return manifest


def validate(m, data):
    """Structural checks that must pass before the manifest is used."""
    errs = []
    warnings = []
    n = len(data)
    start = m["mz"]["start_ofs"]
    load_end = m["fbov"]["offset"]

    by_static = {}
    for e in m["segments"]:
        by_static.setdefault(e["static_seg"], []).append(e)

    for e in m["segments"]:
        seg = e["seg"]
        if e["is_overlay"]:
            hdr = start + seg * 16
            if hdr + 0x20 > load_end:
                errs.append("overlay header out of load module: seg=%04X" % seg)
            ov = next((o for o in m["overlays"] if o["header_seg"] == seg), None)
            if ov:
                end = ov["code_file_offset"] + ov["codesz"] + ov["fixupsz"]
                if end > n:
                    errs.append("overlay code out of file: seg=%04X end=%X" % (seg, end))
                if ov["code_seg"] * 16 < 0:
                    errs.append("negative overlay code segment: seg=%04X" % seg)
        else:
            if e["maxoff"] == 0xFFFF:
                # boseg_t: 0xFFFF means "ignored by the linker's OvrCodeReloc"
                continue
            off = start + seg * 16
            end = off + e["maxoff"]
            if end > load_end:
                errs.append("segment out of load module: seg=%04X end=%X" % (seg, end))
            if e["minoff"] > e["maxoff"]:
                warnings.append("segment minoff > maxoff: seg=%04X" % seg)

    for f in m["fixups"]:
        if f["target_index"] >= len(m["segments"]):
            errs.append("fixup target out of range: %d" % f["target_index"])
        if f["code_offset"] >= next(
                o["codesz"] for o in m["overlays"]
                if o["header_seg"] == f["overlay_header_seg"]):
            errs.append("fixup site outside code: seg=%04X q=%04X"
                        % (f["overlay_header_seg"], f["code_offset"]))
        if f["target_seg"] is None:
            errs.append("fixup target has no segment: seg=%04X q=%04X"
                        % (f["overlay_header_seg"], f["code_offset"]))

    for r in m["relocs"]:
        if r["file_offset"] + 2 > load_end:
            errs.append("MZ reloc out of load module: %04X:%04X"
                        % (r["seg"], r["ofs"]))
        if r["target_seg"] is None:
            warnings.append("MZ reloc has no target: %04X:%04X"
                            % (r["seg"], r["ofs"]))

    if 0x2410 not in by_static:
        errs.append("DGROUP 0x2410 is missing from _SEGTABLE_")
    if 0x225D not in by_static:
        errs.append("_OVRDATA_ 0x225D is missing from _SEGTABLE_")

    dups = {k: v for k, v in by_static.items() if len(v) > 1}
    if dups:
        warnings.append("duplicate static segments: " +
                        ", ".join("%04X(%d)" % (k, len(v))
                                  for k, v in sorted(dups.items())))

    code_segs = {}
    for o in m["overlays"]:
        code_segs.setdefault(o["code_seg"], []).append(o["header_seg"])
    overlap = {k: v for k, v in code_segs.items() if len(v) > 1}
    if overlap:
        warnings.append("overlay code segments shared: " +
                        ", ".join("%04X:%s" % (k, ",".join("%04X" % x for x in v))
                                  for k, v in sorted(overlap.items())))

    return {"errors": errs, "warnings": warnings}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--exe", default=os.path.join("game", "STRONG.EXE"))
    ap.add_argument("--out", default=os.path.join("doc", "fbov_manifest.json"))
    a = ap.parse_args()
    m = parse(a.exe)
    v = validate(m, open(a.exe, "rb").read())
    m["validation"] = v

    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    with open(a.out, "w", encoding="ascii") as f:
        json.dump(m, f, indent=1)

    # CSVs.
    base = os.path.dirname(a.out)
    with open(os.path.join(base, "fbov_segments.csv"), "w", newline="",
              encoding="ascii") as f:
        w = csv.writer(f)
        w.writerow(["index", "seg", "static_seg", "minoff", "maxoff", "flags", "class"])
        for e in m["segments"]:
            w.writerow([e["index"], "%04X" % e["seg"],
                        "%04X" % e["static_seg"], "%04X" % e["minoff"],
                        "%04X" % e["maxoff"], e["flags"], e["class"]])

    with open(os.path.join(base, "fbov_overlays.csv"), "w", newline="",
              encoding="ascii") as f:
        w = csv.writer(f)
        w.writerow(["header_seg", "code_seg", "code_disp", "code_file_offset",
                    "codesz", "fixupsz", "jmpcnt"])
        for e in m["overlays"]:
            w.writerow(["%04X" % e["header_seg"], "%04X" % e["code_seg"],
                        "%X" % e["code_disp"], "0x%X" % e["code_file_offset"],
                        "%04X" % e["codesz"], "%04X" % e["fixupsz"],
                        e["jmpcnt"]])

    with open(os.path.join(base, "fbov_fixups.csv"), "w", newline="",
              encoding="ascii") as f:
        w = csv.writer(f)
        w.writerow(["header_seg", "code_seg", "site_ofs", "flags",
                    "target_index", "target_seg", "target_class", "funref",
                    "trampoline_offset"])
        for e in m["fixups"]:
            w.writerow(["%04X" % e["overlay_header_seg"],
                        "%04X" % e["overlay_code_seg"],
                        "%04X" % e["site_ofs"], e["flags"],
                        e["target_index"],
                        "%04X" % (e["target_seg"] or 0),
                        e["target_class"] or "", int(e["funref"]),
                        "" if e.get("trampoline_offset") is None
                        else "%04X" % e["trampoline_offset"]])

    with open(os.path.join(base, "fbov_relocs.csv"), "w", newline="",
              encoding="ascii") as f:
        w = csv.writer(f)
        w.writerow(["index", "seg", "ofs", "file_offset", "target_seg"])
        for e in m["relocs"]:
            w.writerow([e["index"], "%04X" % e["seg"], "%04X" % e["ofs"],
                        "0x%X" % e["file_offset"],
                        "" if e["target_seg"] is None
                        else "%04X" % e["target_seg"]])

    # Summary.
    classes = {}
    for e in m["segments"]:
        classes[e["class"]] = classes.get(e["class"], 0) + 1
    print("MZ start=0x%X loaded=0x%X FBOV=0x%X nsegs=%d" % (
        m["mz"]["start_ofs"], m["mz"]["loaded_sz"], m["fbov"]["offset"],
        m["fbov"]["nsegs"]))
    print("segments:", classes)
    print("overlays:", len(m["overlays"]), "fixups:", len(m["fixups"]),
          "funrefs:", sum(1 for e in m["fixups"] if e["funref"]),
          "mz relocs:", len(m["relocs"]))
    dg = next((e for e in m["segments"] if e["static_seg"] == 0x2410), None)
    print("DGROUP 0x2410 entry:", dg)
    ov = next((e for e in m["segments"] if e["static_seg"] == 0x225d), None)
    print("_OVRDATA_ 0x225d entry:", ov)
    missing = [e for e in m["fixups"] if e["target_seg"] is None]
    print("fixups with missing target:", len(missing))
    unresolved = [e for e in m["fixups"] if e["funref"] and e["trampoline_offset"] is None]
    print("funrefs without trampoline:", len(unresolved))
    print("validation errors:", len(v["errors"]),
          "warnings:", len(v["warnings"]))
    for e in v["errors"][:20]:
        print("  ERROR", e)
    for w in v["warnings"][:10]:
        print("  WARN ", w)


if __name__ == "__main__":
    main()
