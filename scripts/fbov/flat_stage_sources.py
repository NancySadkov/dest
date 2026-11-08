import json, os, re, shutil, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SRC = os.path.join(ROOT, "src")
OUT = os.path.join(ROOT, "tmp", "flat")
os.makedirs(OUT, exist_ok=True)

m = json.load(open(os.path.join(ROOT, "doc", "fbov_manifest.json")))
renamed = 0
for ov in m["overlays"]:
    code = ov["code_seg"]
    hdr = ov["header_seg"]
    src = os.path.join(SRC, "ov_%04x.c" % code)
    if not os.path.exists(src):
        continue
    s = open(src, encoding="ascii").read()
    for t in ov.get("trampolines") or []:
        old = "f_%04x_%04x" % (code, t["target_ofs"])
        new = "f_%04x_%04x" % (hdr, t["header_off"])
        if old in s:
            s = re.sub(r"\b%s\b" % old, new, s)
            renamed += 1
    open(os.path.join(OUT, "ov_%04x.c" % code), "w",
         encoding="ascii", newline="").write(s)

# main as-is; the flat link uses the f_0000_2747 stub
main = open(os.path.join(SRC, "main.c"), encoding="ascii").read()
open(os.path.join(OUT, "main.c"), "w", encoding="ascii", newline="").write(main)

for f in ("compat.h", "types.h", "dgroup.h"):
    p = os.path.join(ROOT, "tmp", "ovbuild", f)
    if os.path.exists(p):
        shutil.copyfile(p, os.path.join(OUT, f))
shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "stubs.c"),
                os.path.join(OUT, "stubs.c"))
shutil.copyfile(os.path.join(ROOT, "scripts", "fbov", "start.asm"),
                os.path.join(OUT, "start.asm"))
print("renamed", renamed, "functions")
