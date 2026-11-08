import json, os, re, sys

ROOT = r"C:\Users\nangl\d\code\dest"
hdr_hex = sys.argv[1]
hdr = int(hdr_hex, 16)
m = json.load(open(os.path.join(ROOT, "doc", "fbov_manifest.json")))
ov = [x for x in m["overlays"] if x["header_seg"] == hdr][0]
seg = ov["code_seg"]
segname = "OV_%04X_TEXT" % seg
name = "ov_%04x" % seg
src = os.path.join(ROOT, "src", name + ".c")
lines = open(src, encoding="ascii").read().splitlines()

sig_re = re.compile(r'^[^\n]*__cdecl16far\s+f_%04x_([0-9a-fA-F]{4})\s*\([^\n]*\)\s*$' % seg)
sig_idxs = [i for i, l in enumerate(lines)
            if sig_re.match(l) and not l.strip().endswith(';')]
header = lines[:sig_idxs[0]]
proto = []
blocks = []
for start in sig_idxs:
    end = start
    while end < len(lines) and lines[end].rstrip() != '}':
        end += 1
    sig = lines[start]
    addr = int(sig_re.match(sig).group(1), 16)
    blocks.append((addr, lines[start:end + 1]))
    proto.append(sig.replace('register ', '') + ';')

# Table gaps for this overlay (from gen_overlay_asm.py output).
gaps = []
exe = open(os.path.join(ROOT, "game", "STRONG.EXE"), "rb").read()
code = exe[ov["code_file_offset"]:ov["code_file_offset"] + ov["codesz"]]
import capstone
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_16)
p = 0
while p < ov["codesz"]:
    if code[p:p + 3] != b"\x55\x8b\xec":
        q = p
        while q + 2 < ov["codesz"] and code[q:q + 3] != b"\x55\x8b\xec":
            q += 1
        gaps.append((p, q))
        p = q
        continue
    end = None
    for ins in md.disasm(code[p:], p):
        if ins.mnemonic == "retf":
            end = ins.address + len(ins.bytes)
            break
    if end is None:
        break
    p = end

# Assign blocks to chunks by table boundaries.
chunks = [[] for _ in range(len(gaps) + 1)]
g = 0
for addr, blk in blocks:
    while g < len(gaps) and addr >= gaps[g][1]:
        g += 1
    chunks[g].append(blk)

outdir = os.path.join(ROOT, "tmp", "chunkbuild")
os.makedirs(outdir, exist_ok=True)
hdrname = "h%04x.h" % seg
hlines = ['#include "dgroup.h"', '#pragma codeseg ' + segname, '']
hlines += proto
hlines += ['']
open(os.path.join(outdir, hdrname), "w", encoding="ascii", newline="").write("\n".join(hlines) + "\n")

files = []
for i, ch in enumerate(chunks):
    fn = "c%04x_%d.c" % (seg, i)
    txt = ['#include "%s"' % hdrname, '#pragma codeseg ' + segname, ''] 
    for blk in ch:
        txt += blk
        txt.append('')
    open(os.path.join(outdir, fn), "w", encoding="ascii", newline="").write("\n".join(txt) + "\n")
    files.append(fn)
    if i < len(gaps):
        a, b = gaps[i]
        an = "t%04x_%d.asm" % (seg, i)
        data = code[a:b]
        alines = [segname + " SEGMENT BYTE PUBLIC 'CODE'"]
        for j in range(0, len(data), 16):
            alines.append('db ' + ','.join('0%02Xh' % v for v in data[j:j + 16]))
        alines += [segname + " ENDS", "END", ""]
        open(os.path.join(outdir, an), "w", encoding="ascii", newline="").write("\r\n".join(alines))
        files.append(an)

bat = ["@echo off", "mode con lines=50",
       "E:\\BIN\\TASM.EXE dglink.asm"]
for f in files:
    if f.endswith(".asm"):
        bat.append("E:\\BIN\\TASM.EXE " + f)
    else:
        bat.append("D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c " + f)
bat.append("D:\\BIN\\TCC.EXE -ml -1 -G -O -ID:\\INCLUDE -IC:\\ -LD:\\LIB -w- -c stubs.c")
objs = []
for f in files:
    if f.endswith('.asm'):
        objs.append(f[:-4] + ".obj")
    else:
        objs.append(f[:-2] + ".obj")
open(os.path.join(outdir, "link.rsp"), "w", newline="").write(
    "/m dglink.obj " + " ".join(objs) + " stubs.obj, out.exe, out.map\r\n")
bat.append("D:\\BIN\\TLINK.EXE @link.rsp")
bat.append("pause")
open(os.path.join(outdir, "build.bat"), "w", newline="").write("\r\n".join(bat) + "\r\n")

conf = ("[sdl]\nfullscreen = false\noutput = surface\n"
        "[dosbox]\nmachine = svga_s3\nmemsize = 16\n"
        "[cpu]\ncore = normal\ncputype = 386\ncycles = max\n"
        "[mixer]\nnosound = true\n[sblaster]\nsbtype = none\n[midi]\nmididevice = none\n"
        "[autoexec]\nmount c " + outdir.replace("\\", "\\\\") + "\n"
        "mount d C:\\Users\\nangl\\d\\code\\dest\\tools\\TC30\n"
        "mount e C:\\Users\\nangl\\d\\code\\dest\\tools\\BC30\n"
        "c:\ncall build.bat\n")
open(os.path.join(ROOT, "tmp", "chunkbuild.conf"), "w").write(conf)
print("chunks", len(chunks), "gaps", [(hex(a), hex(b)) for a, b in gaps])
print("files", files)
