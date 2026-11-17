// Rename parameters and locals from a TSV: address<TAB>old<TAB>new[<TAB>type].
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
                String[] f = line.split("\t");
                if (f.length < 3) continue;
                Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = fm.getFunctionAt(ad);
                if (fn == null) { println("NOFUNC " + f[0]); missing++; continue; }
                Variable hit = null;
                for (Variable v : fn.getParameters()) if (v.getName().equals(f[1])) hit = v;
                if (hit == null)
                    for (Variable v : fn.getLocalVariables()) if (v.getName().equals(f[1])) hit = v;
                if (hit == null) { println("NOVAR " + f[0] + " " + f[1]); missing++; continue; }
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
                    println("FAIL " + f[0] + " " + f[1] + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
