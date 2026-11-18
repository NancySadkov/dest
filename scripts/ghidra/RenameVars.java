// Rename parameters and locals from a TSV: address-or-name<TAB>old<TAB>new[<TAB>type].
//
// The first column is normally a function address.  When AddressFactory cannot resolve it to a
// function (overlay segments such as 22a6:xxxx live in another address space, so getFunctionAt
// returns null), the column is treated as a global function name and resolved through the
// FunctionManager instead.  Names must identify exactly one function.
//
// Args: renames.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RenameVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        FunctionManager fm = currentProgram.getFunctionManager();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("rename vars");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Function fn = null;
                String ref = f[0];
                Address ad = currentProgram.getAddressFactory().getAddress(ref);
                if (ad != null) fn = fm.getFunctionAt(ad);
                if (fn == null) {
                    List<Function> found = new ArrayList<>();
                    String want = ref.trim();
                    for (Function cand : fm.getFunctions(true))
                        if (cand.getName().equals(want)) found.add(cand);
                    if (found.size() == 1) {
                        fn = found.get(0);
                        println("BYNAME " + want + " -> " + fn.getEntryPoint());
                    } else if (found.size() > 1) {
                        println("AMBIG " + want + " (" + found.size() + " functions)");
                    }
                }
                if (fn == null) { println("NOFUNC " + ref); missing++; continue; }
                Variable hit = null;
                for (Variable v : fn.getParameters()) if (v.getName().equals(f[1])) hit = v;
                if (hit == null)
                    for (Variable v : fn.getLocalVariables()) if (v.getName().equals(f[1])) hit = v;
                if (hit == null) { println("NOVAR " + ref + " " + f[1]); missing++; continue; }
                try {
                    if (f.length > 3 && !f[3].isEmpty()) {
                        String spec = f[3].trim();
                        DataType t;
                        if (spec.endsWith(" *")) {
                            DataType base = dtm.getDataType(spec.substring(0, spec.length() - 2).trim());
                            t = base == null ? null
                                    : new ghidra.program.model.data.PointerDataType(base, 4, dtm);
                        } else {
                            t = dtm.getDataType(spec);
                        }
                        if (t != null) hit.setDataType(t, SourceType.USER_DEFINED);
                    }
                    hit.setName(f[2], SourceType.USER_DEFINED);
                    ok++;
                } catch (Throwable t) {
                    println("FAIL " + ref + " " + f[1] + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
