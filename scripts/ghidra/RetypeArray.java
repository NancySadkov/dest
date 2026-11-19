// Replace an address range with an array of a given element type.
// Args: TSV with address<TAB>elementTypePath<TAB>count<TAB>name<TAB>comment
// Clears the range (removing labels inside it), creates the array and relabels the base.
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

public class RetypeArray extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("retype array");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                Address base = currentProgram.getAddressFactory().getAddress(f[0]);
                DataType elem = dtm.getDataType(f[1]);
                int count;
                try { count = Integer.decode(f[2]); } catch (Exception e) { println("BADCOUNT " + f[0]); failed++; continue; }
                if (base == null || elem == null) { println("BAD " + f[0] + " / " + f[1]); failed++; continue; }
                String name = f.length > 3 ? f[3].trim() : "";
                String comment = f.length > 4 ? f[4].trim() : "";
                try {
                    Address last = base.add((long) elem.getLength() * count - 1);
                    clearListing(base, last);
                    ArrayDataType arr = new ArrayDataType(elem, count, elem.getLength());
                    createData(base, arr);
                    if (!name.isEmpty()) {
                        Symbol s = st.getPrimarySymbol(base);
                        if (s != null) s.setName(name, SourceType.USER_DEFINED);
                        else st.createLabel(base, name, SourceType.USER_DEFINED);
                    }
                    if (!comment.isEmpty()) lst.setComment(base, CodeUnit.EOL_COMMENT, comment);
                    ok++;
                    println("array " + base + " " + f[1] + "[" + count + "] " + name);
                } catch (Throwable e) {
                    println("FAIL " + f[0] + " : " + e);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("arrays=" + ok + " failed=" + failed);
    }
}
