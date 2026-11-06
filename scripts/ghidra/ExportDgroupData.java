// Export DGROUP symbols with addresses, C declarations and exact initialisers.
// Args: seg outfile.csv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;

public class ExportDgroupData extends GhidraScript {
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

    private boolean isFarStruct(DataType dt) {
        if (dt == null) return false;
        if (dt instanceof Structure) return true;
        String n = dt.getName();
        if (n != null && (n.equals("far_t") || n.equals("Pfar_t"))) return true;
        if (dt instanceof TypeDef) {
            DataType base = ((TypeDef) dt).getDataType();
            if (base instanceof Structure) return true;
            String bn = base.getName();
            return bn != null && bn.equals("far_t");
        }
        return false;
    }

    private String toC(String rep, DataType dt) {
        if (rep == null) return "0";
        rep = rep.trim();
        if (rep.length() == 0) return "0";
        if (rep.startsWith("\"") || rep.startsWith("'")) return rep;
        if (rep.equalsIgnoreCase("true")) return "1";
        if (rep.equalsIgnoreCase("false")) return "0";
        if (rep.equalsIgnoreCase("NULL")) return "0";
        if (rep.matches("^-?0x[0-9A-Fa-f]+\\s+.*")) rep = rep.split("\\s+")[0];
        if (rep.matches("^-?[0-9A-Fa-f]+h\\s+.*")) rep = rep.split("\\s+")[0];
        java.util.regex.Matcher sa = java.util.regex.Pattern
                .compile("^([0-9A-Fa-f]{1,4}):([0-9A-Fa-f]{1,4})$").matcher(rep);
        if (sa.matches()) {
            String seg = sa.group(1), off = sa.group(2);
            if (dt instanceof Pointer)
                return "(void far *)(0x" + seg + "0000UL + 0x" + off + "UL)";
            if (isFarStruct(dt)) return "{ 0x" + off + ", 0x" + seg + " }";
            return "0x" + seg + "0000UL + 0x" + off + "UL";
        }
        java.util.regex.Matcher hm = java.util.regex.Pattern
                .compile("^(-?)(?:0x)?([0-9A-Fa-f]+)h$").matcher(rep);
        if (hm.matches()) return hm.group(1) + "0x" + hm.group(2);
        return rep;
    }

    private String initOf(Data d, int depth) throws Exception {
        if (depth > 8) return "0";
        DataType dt = d.getDataType();
        String rep = d.getDefaultValueRepresentation();
        if (rep != null && rep.trim().startsWith("\"")) return rep.trim();
        if (dt instanceof Pointer) return toC(rep, dt);
        if (dt.getName().contains("String") && rep != null && rep.trim().startsWith("\""))
            return rep.trim();
        if (dt instanceof Dynamic) return "{ " + toC(rep, null) + " }";
        if (dt instanceof Array && d.getNumComponents() == 0)
            return "{ " + toC(rep, ((Array) dt).getDataType()) + " }";
        int n = d.getNumComponents();
        if (n > 0) {
            if (d.isUnion()) return "{ " + initOf(d.getComponent(0), depth + 1) + " }";
            StringBuilder b = new StringBuilder("{ ");
            for (int i = 0; i < n; i++) {
                if (i > 0) b.append(", ");
                b.append(initOf(d.getComponent(i), depth + 1));
            }
            b.append(" }");
            return b.toString();
        }
        return toC(rep, dt);
    }

    private String q(String s) {
        if (s == null) s = "";
        return "\"" + s.replace("\"", "\"\"") + "\"";
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int seg = Integer.parseInt(a[0], 16);
        Address start = currentProgram.getAddressFactory().getAddress(
                String.format("%04X:0000", seg));
        Address end = currentProgram.getAddressFactory().getAddress(
                String.format("%04X:FFFF", seg));
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        w.println("offset,name,length,decl,init");
        Listing lst = currentProgram.getListing();
        SymbolTable st = currentProgram.getSymbolTable();
        List<Symbol> syms = new ArrayList<Symbol>();
        for (Symbol s : st.getAllSymbols(true)) {
            if (s.getSymbolType() == SymbolType.FUNCTION) continue;
            if (s.getParentNamespace().getID() != currentProgram.getGlobalNamespace().getID()) continue;
            if (!s.isPrimary()) continue;
            Address ad = s.getAddress();
            if (ad == null || ad.compareTo(start) < 0 || ad.compareTo(end) > 0) continue;
            if (s.isExternal()) continue;
            String n = s.getName();
            if (n.contains(".") || n.contains("[") || n.contains("+") || n.contains("::")) continue;
            if (n.startsWith("LAB_") || n.startsWith("switchD_") || n.startsWith("caseD_")) continue;
            syms.add(s);
        }
        syms.sort(new Comparator<Symbol>() {
            public int compare(Symbol x, Symbol y) { return x.getAddress().compareTo(y.getAddress()); }
        });
        int n = 0;
        for (Symbol s : syms) {
            Data d = lst.getDataAt(s.getAddress());
            if (d == null) continue;
            String decl = typeDecl(d.getDataType(), s.getName());
            if (decl == null) continue;
            String init = "";
            try { init = initOf(d, 0); } catch (Throwable t) { init = ""; }
            int off = (int) s.getAddress().subtract(start);
            w.println(String.format("%04X,%s,%d,%s,%s", off, q(s.getName()),
                    d.getLength(), q(decl), q(init)));
            n++;
        }
        w.close();
        println("wrote " + a[1] + " symbols=" + n);
    }
}
