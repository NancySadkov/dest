// Remove local variables (not just symbols) from a function, so a widened datatype can take their
// stack slots.  Args: tsv with address<TAB>varname
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RemoveVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        int ok = 0, missing = 0;
        int tx = currentProgram.startTransaction("remove variables");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address addr = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = addr == null ? null : currentProgram.getFunctionManager().getFunctionAt(addr);
                if (fn == null) { println("NOFUNC " + f[0]); missing++; continue; }
                Variable hit = null;
                for (Variable v : fn.getLocalVariables())
                    if (v.getName().equals(f[1])) { hit = v; break; }
                if (hit == null) { println("NOVAR " + f[0] + " " + f[1]); missing++; continue; }
                fn.removeVariable(hit);
                ok++;
                println("removed " + f[1] + " from " + fn.getName());
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("removed=" + ok + " missing=" + missing);
    }
}
