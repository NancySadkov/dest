// Set a parameter's or local variable's datatype by function address and variable name.
// Args: tsv with address<TAB>varname<TAB>typePath<TAB>comment
// A typePath ending in " *" builds a two-byte near pointer to the named type.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class SetVarType extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("set variable types");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Address addr = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = addr == null ? null : currentProgram.getFunctionManager().getFunctionAt(addr);
                if (fn == null) { println("NOFUNC " + f[0]); missing++; continue; }
                String spec = f[2].trim();
                DataType dt;
                java.util.regex.Matcher am = java.util.regex.Pattern
                        .compile("^(.+)\\[(\\d+)\\]$").matcher(spec);
                if (spec.endsWith(" *")) {
                    DataType base = dtm.getDataType(spec.substring(0, spec.length() - 2).trim());
                    if (base == null) { println("NOTYPE " + spec); failed++; continue; }
                    dt = new PointerDataType(base, 2, dtm);
                } else if (am.matches()) {
                    DataType base = dtm.getDataType(am.group(1).trim());
                    if (base == null) { println("NOTYPE " + spec); failed++; continue; }
                    dt = new ArrayDataType(base, Integer.parseInt(am.group(2)), base.getLength());
                } else {
                    dt = dtm.getDataType(spec);
                    if (dt == null) { println("NOTYPE " + spec); failed++; continue; }
                }
                Variable target = null;
                for (Variable v : fn.getParameters())
                    if (v.getName().equals(f[1])) { target = v; break; }
                if (target == null)
                    for (Variable v : fn.getLocalVariables())
                        if (v.getName().equals(f[1])) { target = v; break; }
                if (target == null) { println("NOVAR " + f[0] + " " + f[1]); missing++; continue; }
                try {
                    target.setDataType(dt, SourceType.USER_DEFINED);
                    if (f.length > 3 && !f[3].trim().isEmpty())
                        target.setComment(f[3].trim());
                    ok++;
                    println("typed " + f[0] + " " + f[1] + " " + dt.getName());
                } catch (Throwable t) {
                    println("FAIL " + f[0] + " " + f[1] + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("typed=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
