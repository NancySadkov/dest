// Set a function's return type, letting Ghidra derive the return storage from the
// type (f.setReturnType) instead of supplying a VariableStorage.
// Args: tsv of address<TAB>typePath
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

public class SetRetType extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("set ret type");
        try {
            for (String line : Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8)) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                Address at = currentProgram.getAddressFactory().getAddress(f[0]);
                Function fn = currentProgram.getFunctionManager().getFunctionAt(at);
                if (fn == null) { println("NOFUNC " + f[0]); missing++; continue; }
                DataType dt = currentProgram.getDataTypeManager().getDataType(f[1]);
                if (dt == null) { println("NOTYPE " + f[1]); missing++; continue; }
                try {
                    fn.setReturnType(dt, SourceType.USER_DEFINED);
                    println("ok " + f[0] + " " + fn.getName() + " -> "
                            + (dt.getLength() == 0 ? "void(" + dt.getName() + ")" : dt.getName()));
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + " " + e.getClass().getSimpleName() + ": "
                            + e.getMessage());
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("ok=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
