// Give every remaining default symbol a deterministic, type-based name.
// LAB_*     -> L_<function>_<offset>
// DAT_*     -> <type>_<block>_<offset>
// SUB_*     -> sub_<block>_<offset>
// UNK_*     -> unk_<block>_<offset>
// unsymbolized defined data -> data_<block>_<offset>_<type>
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class BulkNameRemaining extends GhidraScript {
    private Set<String> used = new HashSet<String>();

    private String sanitize(String s) {
        if (s == null || s.length() == 0) return "data";
        String r = s.replaceAll("[^A-Za-z0-9_]", "_");
        while (r.contains("__")) r = r.replace("__", "_");
        if (r.length() > 24) r = r.substring(0, 24);
        return r;
    }

    private String blockName(Address a) {
        MemoryBlock b = currentProgram.getMemory().getBlock(a);
        return b == null ? "mem" : sanitize(b.getName());
    }

    private String rel(Address a) {
        MemoryBlock b = currentProgram.getMemory().getBlock(a);
        if (b == null) return String.format("%04X", a.getOffset() & 0xFFFF);
        long off = a.subtract(b.getStart());
        return String.format("%04X", off & 0xFFFF);
    }

    private String typeName(Address a) {
        Data d = currentProgram.getListing().getDataAt(a);
        if (d == null || d.getDataType() == null) return "data";
        return sanitize(d.getDataType().getName());
    }

    private String unique(String base) {
        String n = base;
        int k = 1;
        while (used.contains(n)) {
            k++;
            n = base + "_" + k;
        }
        used.add(n);
        return n;
    }

    @Override
    public void run() throws Exception {
        int tx = currentProgram.startTransaction("bulk name");
        int n = 0, fail = 0;
        try {
            SymbolTable st = currentProgram.getSymbolTable();
            for (Symbol s : st.getAllSymbols(true)) {
                if (s.isExternal()) continue;
                Address a = s.getAddress();
                if (a == null) continue;
                String old = s.getName();
                String base = null;
                if (old.startsWith("LAB_")) {
                    Function f = currentProgram.getFunctionManager().getFunctionContaining(a);
                    base = "L_" + (f == null ? blockName(a) : sanitize(f.getName())) + "_" + rel(a);
                }
                else if (old.startsWith("DAT_")) {
                    base = typeName(a) + "_" + blockName(a) + "_" + rel(a);
                }
                else if (old.startsWith("SUB_")) {
                    base = "sub_" + blockName(a) + "_" + rel(a);
                }
                else if (old.startsWith("UNK_")) {
                    base = "unk_" + blockName(a) + "_" + rel(a);
                }
                if (base == null) {
                    used.add(old);
                    continue;
                }
                String name = unique(base);
                try {
                    s.setName(name, SourceType.USER_DEFINED);
                    n++;
                } catch (Throwable t) {
                    fail++;
                }
            }
            // Defined data with no symbol.
            for (Data d : currentProgram.getListing().getDefinedData(true)) {
                Address a = d.getAddress();
                if (st.getSymbols(a).length != 0) continue;
                String base = "data_" + blockName(a) + "_" + rel(a) + "_" + typeName(a);
                String name = unique(base);
                try {
                    st.createLabel(a, name, SourceType.USER_DEFINED);
                    n++;
                } catch (Throwable t) {
                    fail++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed " + n + " failed " + fail);
    }
}
