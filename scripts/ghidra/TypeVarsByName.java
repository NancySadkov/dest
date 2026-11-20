// Apply data types to parameters/locals addressed by function name.
// Args: tsv with  functionName <TAB> varName <TAB> typeSpec
// typeSpec supports the same forms as SetVarType ("/x", "base *", "base *32", "T[N]").
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;

public class TypeVarsByName extends GhidraScript {
    private DataTypeManager dtm;
    private Map<String, Function> byName = new HashMap<>();

    private DataType resolve(String spec) {
        Matcher am = Pattern.compile("^(.+)\\[(\\d+)\\]$").matcher(spec);
        if (spec.endsWith(" *32")) {
            DataType b = dtm.getDataType(spec.substring(0, spec.length() - 4).trim());
            return b == null ? null : new PointerDataType(b, 4, dtm);
        }
        if (spec.endsWith(" *")) {
            DataType b = dtm.getDataType(spec.substring(0, spec.length() - 2).trim());
            return b == null ? null : new PointerDataType(b, 2, dtm);
        }
        if (am.matches()) {
            DataType b = dtm.getDataType(am.group(1).trim());
            return b == null ? null : new ArrayDataType(b, Integer.parseInt(am.group(2)), b.getLength());
        }
        return dtm.getDataType(spec);
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        dtm = currentProgram.getDataTypeManager();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            byName.putIfAbsent(f.getName(), f);
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int ok = 0, nofn = 0, novar = 0, notype = 0;
        int tx = currentProgram.startTransaction("type vars by name");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Function fn = byName.get(f[0].trim());
                if (fn == null) { nofn++; continue; }
                DataType dt = resolve(f[2].trim());
                if (dt == null) { notype++; continue; }
                Variable hit = null;
                for (Variable v : fn.getParameters())
                    if (v.getName().equals(f[1].trim())) { hit = v; break; }
                if (hit == null)
                    for (Variable v : fn.getLocalVariables())
                        if (v.getName().equals(f[1].trim())) { hit = v; break; }
                if (hit == null) { novar++; continue; }
                hit.setDataType(dt, SourceType.USER_DEFINED);
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("typed=" + ok + " nofunc=" + nofn + " novar=" + novar + " notype=" + notype);
    }
}
