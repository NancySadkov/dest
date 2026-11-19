// Replace an address range with one scalar data type and label it.
// Args: TSV with address<TAB>typePath<TAB>name<TAB>comment
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

public class RetypeData extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("retype data");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Address base = currentProgram.getAddressFactory().getAddress(f[0]);
                DataType t = dtm.getDataType(f[1]);
                if (base == null || t == null) { println("BAD " + f[0] + " / " + f[1]); failed++; continue; }
                String name = f[2].trim();
                String comment = f.length > 3 ? f[3].trim() : "";
                try {
                    clearListing(base, base.add(t.getLength() - 1));
                    createData(base, t);
                    Symbol s = st.getPrimarySymbol(base);
                    if (s != null) s.setName(name, SourceType.USER_DEFINED);
                    else st.createLabel(base, name, SourceType.USER_DEFINED);
                    if (!comment.isEmpty()) lst.setComment(base, CodeUnit.EOL_COMMENT, comment);
                    ok++;
                    println("data " + base + " " + f[1] + " " + name);
                } catch (Throwable e) {
                    println("FAIL " + f[0] + " : " + e);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("data=" + ok + " failed=" + failed);
    }
}
