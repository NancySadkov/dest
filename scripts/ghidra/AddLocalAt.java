// Create locals at explicit (possibly positive) stack offsets.
// Args: tsv with  functionAddr <TAB> name <TAB> typeSpec <TAB> offset [<TAB> comment]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;

public class AddLocalAt extends GhidraScript {
    private DataTypeManager dtm;

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

    private AddressSpace stackSpace(Function fn) {
        for (Variable v : fn.getLocalVariables()) {
            Address a = v.getVariableStorage().getMinAddress();
            if (a != null && a.getAddressSpace().isStackSpace()) return a.getAddressSpace();
        }
        for (Variable v : fn.getParameters()) {
            Address a = v.getVariableStorage().getMinAddress();
            if (a != null && a.getAddressSpace().isStackSpace()) return a.getAddressSpace();
        }
        return null;
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        dtm = currentProgram.getDataTypeManager();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int tx = currentProgram.startTransaction("add stack locals");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 4) { println("BADLINE " + line); continue; }
                Function fn = getFunctionAt(toAddr(f[0]));
                if (fn == null) { println("NOFUNC " + f[0]); continue; }
                DataType dt = resolve(f[2].trim());
                if (dt == null) { println("NOTYPE " + f[2]); continue; }
                AddressSpace sp = stackSpace(fn);
                if (sp == null) { println("NO_STACK " + f[0]); continue; }
                int off = Integer.decode(f[3].trim());
                VariableStorage vs = new VariableStorage(currentProgram, sp.getAddress(off),
                        dt.getLength());
                try {
                    LocalVariableImpl v = new LocalVariableImpl(f[1].trim(), 0, dt, vs,
                            currentProgram);
                    fn.addLocalVariable(v, SourceType.USER_DEFINED);
                    if (f.length > 4 && !f[4].trim().isEmpty())
                        v.setComment(f[4].trim());
                    println("added " + f[1] + " " + dt.getName() + " @ " + vs);
                } catch (Exception e) {
                    println("FAILED " + f[1] + " @ " + off + " : " + e.getClass().getSimpleName()
                            + " " + e.getMessage());
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
