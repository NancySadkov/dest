// Export global data with initialisers recovered from the original image.
// Args: outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportData extends GhidraScript {
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

    private String typeDecl(DataType dt, String name) {
        if (dt instanceof Array) {
            Array a = (Array) dt;
            return typeDecl(a.getDataType(), name + "[" + a.getNumElements() + "]");
        }
        if (dt instanceof Pointer) {
            Pointer p = (Pointer) dt;
            return typeDecl(p.getDataType(), "*" + name);
        }
        if (dt instanceof TypeDef) return dt.getName() + " " + name;
        String dn = dt.getName();
        if (dn.contains("String")) return "char " + name + "[]";
        if (dt instanceof FunctionDefinition) return null;
        if (dt instanceof VoidDataType) return null;
        if (dt instanceof Dynamic) return "undefined " + name + "[]";
        String tn = dt.getDisplayName();
        if (tn == null || tn.length() == 0 || tn.equals("undefined")) tn = "undefined";
        return tn + " " + name;
    }

    private String initOf(Data d, int depth) throws Exception {
        if (depth > 8) return "0";
        DataType dt = d.getDataType();
        if (dt instanceof Pointer) {
            String rep = d.getDefaultValueRepresentation();
            return rep == null ? "0" : rep;
        }
        if (dt.getName().contains("String")) {
            String rep = d.getDefaultValueRepresentation();
            if (rep != null && rep.startsWith("\"")) return rep;
        }
        int n = d.getNumComponents();
        if (n > 0) {
            if (d.isUnion() || n > 8192) return "{ " + initOf(d.getComponent(0), depth + 1) + " }";
            StringBuilder b = new StringBuilder("{ ");
            for (int i = 0; i < n; i++) {
                if (i > 0) b.append(", ");
                b.append(initOf(d.getComponent(i), depth + 1));
            }
            b.append(" }");
            return b.toString();
        }
        String rep = d.getDefaultValueRepresentation();
        if (rep == null || rep.length() == 0) rep = "0";
        return rep;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String out = args.length > 0 ? args[0] : "st_data.c";
        PrintWriter w = new PrintWriter(new FileWriter(out));
        w.println("/* Global data with original initialisers (recovered image). */");
        w.println("#include \"recovered.h\"");
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
            public int compare(Symbol a, Symbol b) { return a.getAddress().compareTo(b.getAddress()); }
        });
        int n = 0;
        for (Symbol s : syms) {
            String name = s.getName();
            if (seen.contains(name)) continue;
            long key = s.getAddress().getOffset();
            if (seenAddr.contains(key)) continue;
            Data d = lst.getDataAt(s.getAddress());
            if (d == null) continue;
            MemoryBlock b = currentProgram.getMemory().getBlock(s.getAddress());
            if (b == null) continue;
            String decl = typeDecl(d.getDataType(), name);
            if (decl == null) continue;
            seen.add(name);
            seenAddr.add(key);
            if (b.isInitialized()) {
                try {
                    w.println(decl + " = " + initOf(d, 0) + ";");
                } catch (Throwable t) {
                    w.println(decl + ";");
                }
            } else {
                w.println(decl + ";");
            }
            n++;
        }
        w.close();
        println("wrote " + out + " symbols=" + n);
    }
}
