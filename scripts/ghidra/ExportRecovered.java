// Recover the whole program into a source tree: one C file per module,
// plus types, globals and prototypes headers.
// Args: <outdir> [addressPrefixFilter]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportRecovered extends GhidraScript {
    private static final String IDCHARS =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_";

    private String sanitizeIdent(String s) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (IDCHARS.indexOf(c) >= 0) b.append(c);
            else b.append('_');
        }
        String r = b.toString();
        if (r.isEmpty()) r = "x";
        if (Character.isDigit(r.charAt(0))) r = "_" + r;
        return r;
    }

    private String moduleName(MemoryBlock b) {
        if (b == null) return "unknown";
        String n = b.getName();
        if (n.matches("OVC\\d+.*")) {
            int us = n.indexOf('_');
            String num = n.substring(3, us >= 0 ? us : n.length());
            String rest = us >= 0 ? n.substring(us + 1) : "";
            int dot = rest.indexOf('.');
            if (dot >= 0) rest = rest.substring(0, dot);
            rest = sanitizeIdent(rest);
            if (rest.equals("x")) rest = "";
            return "ovc" + num + (rest.isEmpty() ? "" : "_" + rest);
        }
        if (n.matches("OVR\\d+.*")) return "ovr_stubs";
        if (n.contains("_TEXT_crtl")) return "crtl";
        if (n.contains("_TEXT_main")) return "main";
        if (n.contains("_TEXT_mouse")) return "mouse";
        if (n.contains("_TEXT_video")) return "video";
        if (n.contains("_OVRTEXT_")) return "ovl";
        if (n.contains("_TEXT_")) return sanitizeIdent(n.substring(n.indexOf("_TEXT_") + 6));
        return sanitizeIdent(n);
    }

    private String typeDecl(DataType dt, String name) {
        if (dt instanceof Array) {
            Array a = (Array) dt;
            return typeDecl(a.getDataType(), name + "[" + a.getNumElements() + "]");
        }
        if (dt instanceof Pointer) {
            Pointer p = (Pointer) dt;
            return typeDecl(p.getDataType(), "*" + name);
        }
        if (dt instanceof TypeDef) {
            return dt.getName() + " " + name;
        }
        String dn = dt.getName();
        if (dn.contains("String")) return "char " + name + "[]";
        if (dt instanceof FunctionDefinition) return null;
        if (dt instanceof VoidDataType) return null;
        if (dt instanceof BitFieldDataType) return dt.getName() + " " + name;
        if (dt instanceof Dynamic) return "undefined " + name + "[]";
        String tn = dt.getDisplayName();
        if (tn == null || tn.length() == 0 || tn.equals("undefined")) tn = "undefined";
        return tn + " " + name;
    }

    private String extractSignature(String content) {
        String s = content.replaceAll("(?s)/\\*.*?\\*/", " ");
        int brace = s.indexOf('{');
        if (brace < 0) return null;
        s = s.substring(0, brace).trim().replaceAll("\\s+", " ");
        if (!s.endsWith(")")) return null;
        return s + ";";
    }

    private void writeTypes(File f) throws Exception {
        File tmp = new File(f.getPath() + ".tmp");
        Writer w = new FileWriter(tmp);
        DataTypeWriter dtw = new DataTypeWriter(currentProgram.getDataTypeManager(), w, false);
        dtw.write(currentProgram.getDataTypeManager(), monitor);
        w.close();
        // Borland/Turbo C++ 3.0 is a 16-bit compiler and has no 64-bit integer
        // type. Keep the generated header parseable by degrading 64-bit
        // placeholders to 32 bits; the few CRT routines that truly need 64 bits
        // are not part of the game-code rebuild.
        StringBuilder sb = new StringBuilder();
        BufferedReader r = new BufferedReader(new FileReader(tmp));
        String line;
        while ((line = r.readLine()) != null) {
            line = line.replace("unsigned long long", "unsigned long");
            line = line.replace("signed long long", "signed long");
            line = line.replace("long long", "long");
            sb.append(line).append('\n');
        }
        r.close();
        tmp.delete();
        PrintWriter out = new PrintWriter(new FileWriter(f));
        out.print(sb.toString());
        out.close();
    }

    private void writeGlobals(File dir) throws Exception {
        PrintWriter h = new PrintWriter(new FileWriter(new File(dir, "st_globals.h")));
        PrintWriter c = new PrintWriter(new FileWriter(new File(dir, "st_globals.c")));
        h.println("/* Global data recovered from the original image. */");
        h.println("#ifndef ST_GLOBALS_H");
        h.println("#define ST_GLOBALS_H");
        c.println("#include \"recovered.h\"");
        Set<String> seen = new HashSet<String>();
        Set<Long> seenAddr = new HashSet<Long>();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        List<Symbol> syms = new ArrayList<Symbol>();
        for (Symbol s : st.getAllSymbols(true)) {
            if (s.getSymbolType() == SymbolType.FUNCTION) continue;
            if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
            if (!s.isPrimary()) continue;
            String n = s.getName();
            if (n.contains(".") || n.contains("[") || n.contains("+") || n.contains("::")) continue;
            if (n.startsWith("LAB_") || n.startsWith("switchD_") || n.startsWith("caseD_")) continue;
            syms.add(s);
        }
        syms.sort(new Comparator<Symbol>() {
            public int compare(Symbol a, Symbol b) {
                return a.getAddress().compareTo(b.getAddress());
            }
        });
        for (Symbol s : syms) {
            String n = s.getName();
            if (seen.contains(n)) continue;
            Data d = lst.getDataAt(s.getAddress());
            if (d == null) continue;
            long key = s.getAddress().getOffset();
            if (seenAddr.contains(key)) continue;
            String decl = typeDecl(d.getDataType(), n);
            if (decl == null) continue;
            seen.add(n);
            seenAddr.add(key);
            h.println("extern " + decl + ";");
            c.println(decl + ";");
        }
        h.println("#endif");
        h.close();
        c.close();
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args.length > 0 ? args[0] : "recovered";
        String filter = args.length > 1 ? args[1] : "";
        File dir = new File(outdir);
        dir.mkdirs();

        // types
        writeTypes(new File(dir, "st_types.h"));
        // globals
        writeGlobals(dir);

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        ifc.setOptions(opts);

        // group functions by module
        LinkedHashMap<String, List<Function>> mods = new LinkedHashMap<String, List<Function>>();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (Function f : fm.getFunctions(true)) {
            if (f.isThunk()) continue;
            if (filter.length() > 0 && !f.getEntryPoint().toString().startsWith(filter)) continue;
            MemoryBlock b = currentProgram.getMemory().getBlock(f.getEntryPoint());
            if (b == null || !b.isExecute()) continue;
            if (b.getName().startsWith("DOS21") || b.getName().contains("FakeVdisk")) continue;
            String m = moduleName(b);
            List<Function> l = mods.get(m);
            if (l == null) { l = new ArrayList<Function>(); mods.put(m, l); }
            l.add(f);
        }

        PrintWriter idx = new PrintWriter(new FileWriter(new File(dir, "index.tsv")));
        idx.println("module\taddress\tname\tsize\tstatus\tfile\tsignature");
        PrintWriter protos = new PrintWriter(new FileWriter(new File(dir, "st_functions.h")));
        protos.println("/* Recovered function prototypes. */");
        protos.println("#ifndef ST_FUNCTIONS_H");
        protos.println("#define ST_FUNCTIONS_H");
        Set<String> emitted = new HashSet<String>();
        int ok = 0, fail = 0;
        List<String> failed = new ArrayList<String>();

        for (Map.Entry<String, List<Function>> e : mods.entrySet()) {
            String mod = e.getKey();
            List<Function> funcs = e.getValue();
            funcs.sort(new Comparator<Function>() {
                public int compare(Function a, Function b) {
                    return a.getEntryPoint().compareTo(b.getEntryPoint());
                }
            });
            PrintWriter w = new PrintWriter(new FileWriter(new File(dir, mod + ".c")));
            MemoryBlock b = currentProgram.getMemory().getBlock(funcs.get(0).getEntryPoint());
            w.println("/*");
            w.println(" * " + mod + ".c - recovered from STRONG.EXE");
            w.println(" * memory block: " + (b != null ? b.getName() : "?"));
            if (b != null) w.println(" * range: " + b.getStart() + " - " + b.getEnd());
            w.println(" * functions: " + funcs.size());
            w.println(" */");
            w.println("#include \"recovered.h\"");
            w.println();
            for (Function f : funcs) {
                String name = f.getName();
                DecompileResults res = null;
                boolean good = false;
                String msg = "";
                int fsize = (int) f.getBody().getNumAddresses();
                try {
                    int t1 = fsize > 3000 ? 60 : 90;
                    res = ifc.decompileFunction(f, t1, monitor);
                    good = res != null && res.decompileCompleted();
                    if (!good && fsize <= 2000) {
                        res = ifc.decompileFunction(f, 240, monitor);
                        good = res != null && res.decompileCompleted();
                    }
                } catch (Throwable t) {
                    msg = t.toString();
                }
                w.println();
                w.println("/* " + f.getEntryPoint() + " */");
                if (good) {
                    String body = res.getDecompiledFunction().getC();
                    String sig = res.getDecompiledFunction().getSignature();
                    w.println(body);
                    if (emitted.add(name)) {
                        if (!sig.endsWith(";")) sig += ";";
                        protos.println(sig);
                    }
                    idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                            + fsize + "\tok\t" + mod + ".c\t" + sig.replace('\t',' '));
                    ok++;
                } else {
                    if (msg.isEmpty()) msg = res == null ? "null" : res.getErrorMessage();
                    if (msg == null) msg = "unknown";
                    File hard = new File(dir, "hard/" + mod + "__" + sanitizeIdent(name) + ".c");
                    if (hard.isFile()) {
                        StringBuilder sb = new StringBuilder();
                        BufferedReader hr = new BufferedReader(new FileReader(hard));
                        String ln;
                        while ((ln = hr.readLine()) != null) sb.append(ln).append('\n');
                        hr.close();
                        w.println("/* recovered by relaxed-limit retry */");
                        w.println(sb.toString());
                        String hs = extractSignature(sb.toString());
                        if (hs != null && emitted.add(name)) protos.println(hs);
                        idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                                + fsize + "\tok-hard\t" + mod + ".c\trelaxed retry");
                        ok++;
                    } else {
                        w.println("/* DECOMPILATION FAILED: " + msg.replace("*/", "* /") + " */");
                        w.println("void " + sanitizeIdent(name) + "(void) { /* failed */ }");
                        idx.println(mod + "\t" + f.getEntryPoint() + "\t" + name + "\t"
                                + fsize + "\tfail\t" + mod + ".c\t" + msg.replace('\t',' '));
                        failed.add(mod + " " + f.getEntryPoint() + " " + name + " : " + msg);
                        fail++;
                    }
                }
            }
            w.close();
        }
        // Fallback prototypes for functions that failed in this run (a relaxed
        // retry may still provide the body from hard/).
        for (Function f : fm.getFunctions(true)) {
            if (f.isThunk()) continue;
            MemoryBlock fb = currentProgram.getMemory().getBlock(f.getEntryPoint());
            if (fb == null || !fb.isExecute()) continue;
            if (fb.getName().startsWith("DOS21") || fb.getName().contains("FakeVdisk")) continue;
            if (emitted.add(f.getName()))
                protos.println("undefined " + f.getName() + "();");
        }
        // overlay thunk prototypes (calls in recovered code go through these)
        for (Function f : fm.getFunctions(true)) {
            if (!f.isThunk()) continue;
            if (emitted.add(f.getName()))
                protos.println("undefined " + f.getName() + "();");
        }
        protos.println("#endif");
        protos.close();
        idx.close();

        // module dispatcher header + stub file for overlay thunks
        PrintWriter rh = new PrintWriter(new FileWriter(new File(dir, "recovered.h")));
        rh.println("/* Aggregated header for the auto-recovered source tree. */");
        rh.println("#ifndef ST_RECOVERED_H");
        rh.println("#define ST_RECOVERED_H");
        rh.println("#include \"st_compat.h\"");
        rh.println("#include \"st_types.h\"");
        rh.println("#include \"st_globals.h\"");
        rh.println("#include \"st_functions.h\"");
        rh.println("#endif");
        rh.close();

        PrintWriter ch = new PrintWriter(new FileWriter(new File(dir, "st_compat.h")));
        ch.println("/* Compatibility shims for Ghidra's decompiler output. */");
        ch.println("#ifndef ST_COMPAT_H");
        ch.println("#define ST_COMPAT_H");
        ch.println("#ifdef __BORLANDC__");
        ch.println("#define __cdecl16far");
        ch.println("#define __cdecl16near __cdecl");
        ch.println("#define __stdcall16far __pascal");
        ch.println("#define __stdcall16near __pascal");
        ch.println("#else");
        ch.println("#define __cdecl16far");
        ch.println("#define __cdecl16near");
        ch.println("#define __stdcall16far");
        ch.println("#define __stdcall16near");
        ch.println("#define __cdecl");
        ch.println("#define __pascal");
        ch.println("#define __fastcall");
        ch.println("#define far");
        ch.println("#define near");
        ch.println("#endif");
        ch.println("typedef unsigned short code(void);");
        ch.println("code *swi(int vector);");
        ch.println("#define CONCAT11(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint8_t)(b)))");
        ch.println("#define CONCAT12(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))");
        ch.println("#define CONCAT13(a,b) ((uint16_t)(((uint8_t)(a) << 8) | (uint16_t)(b)))");
        ch.println("#define CONCAT14(a,b) CONCAT12(a,b)");
        ch.println("#define CONCAT21(a,b) ((uint16_t)(((uint16_t)(a) >> 8) | ((uint16_t)(b) << 8)))");
        ch.println("#define CONCAT22(a,b) ((uint32_t)(((uint16_t)(a) << 16) | (uint16_t)(b)))");
        ch.println("#define CONCAT31(a,b) CONCAT22(a,b)");
        ch.println("#define CONCAT44(a,b) ((uint32_t)(((uint32_t)(a) << 16) | (uint16_t)(b)))");
        ch.println("#define CARRY1(a,b) ((uint8_t)((uint16_t)(a) + (uint16_t)(b) > 0xff))");
        ch.println("#define CARRY2(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) > 0xffff))");
        ch.println("#define CARRY4(a,b) ((uint8_t)((uint32_t)(a) + (uint32_t)(b) < (uint32_t)(a)))");
        ch.println("#define SBORROW1(a,b) ((uint8_t)((int16_t)(int8_t)(a) - (int16_t)(int8_t)(b) < -0x80))");
        ch.println("#define SBORROW2(a,b) ((uint8_t)((int32_t)(int16_t)(a) - (int32_t)(int16_t)(b) < -0x8000))");
        ch.println("#define SBORROW4(a,b) ((uint8_t)((int32_t)(a) - (int32_t)(b) < 0))");
        ch.println("#define SUB41(x,n) ((uint8_t)((uint16_t)(x) >> ((n)*8)))");
        ch.println("#define SUB42(x,n) ((uint16_t)((uint32_t)(x) >> ((n)*8)))");
        ch.println("#define SUB84(x,n) ((uint32_t)(x) >> ((n)*8))");
        ch.println("#define SEXT12(x) ((int16_t)(int8_t)(x))");
        ch.println("#define SEXT13(x) SEXT12(x)");
        ch.println("#define SEXT14(x) SEXT12(x)");
        ch.println("#define SEXT21(x) ((int32_t)(int16_t)(x))");
        ch.println("#define SEXT22(x) SEXT21(x)");
        ch.println("#define SEXT24(x) SEXT21(x)");
        ch.println("#define SEXT31(x) ((int32_t)(int8_t)(x))");
        ch.println("#define SEXT41(x) SEXT31(x)");
        ch.println("#define ZEXT12(x) ((uint16_t)(uint8_t)(x))");
        ch.println("#define ZEXT14(x) ZEXT12(x)");
        ch.println("#define ZEXT21(x) ((uint32_t)(uint16_t)(x))");
        ch.println("#define ZEXT22(x) ZEXT21(x)");
        ch.println("#define ZEXT24(x) ZEXT21(x)");
        ch.println("#define ZEXT41(x) ((uint32_t)(uint8_t)(x))");
        ch.println("#endif");
        ch.close();

        PrintWriter os = new PrintWriter(new FileWriter(new File(dir, "ovr_stubs.c")));
        os.println("/* Borland VROOMM overlay thunks (INT 3Fh). */");
        os.println("#include \"recovered.h\"");
        int nth = 0;
        for (Function f : fm.getFunctions(true)) {
            if (!f.isThunk()) continue;
            Function t = f.getThunkedFunction(true);
            os.println("/* " + f.getEntryPoint() + " -> " + (t == null ? "?" : t.getName()) + " */");
            nth++;
        }
        os.close();

        PrintWriter man = new PrintWriter(new FileWriter(new File(dir, "MANIFEST.md")));
        man.println("# Recovered source manifest\n");
        man.println("Auto-generated by `scripts/ghidra/ExportRecovered.java`.");
        man.println("Modules: " + mods.size() + ", functions: " + (ok + fail)
                + " (ok " + ok + ", failed " + fail + "), overlay thunks: " + nth + ".\n");
        man.println("| module | functions |");
        man.println("|---|---|");
        for (Map.Entry<String, List<Function>> e : mods.entrySet())
            man.println("| " + e.getKey() + " | " + e.getValue().size() + " |");
        if (!failed.isEmpty()) {
            man.println("\n## Failed decompilations\n");
            for (String s : failed) man.println("- " + s);
        }
        man.close();
        println("recovered modules=" + mods.size() + " ok=" + ok + " fail=" + fail + " thunks=" + nth);
    }
}
