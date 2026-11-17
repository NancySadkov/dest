// Set a structure field's type and name.
// Args: tsv with struct<TAB>offset<TAB>typePath<TAB>name<TAB>comment
// A typePath ending in " *" is built as a four-byte far pointer to the named
// type, which is what a far pointer is in this 16-bit program.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class SetFieldType extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("set field types");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                if (f.length < 4) continue;
                DataType dt = dtm.getDataType(f[0]);
                if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); failed++; continue; }
                Structure s = (Structure) dt;
                int off = Integer.decode(f[1]);
                DataType fieldType;
                String spec = f[2].trim();
                if (spec.endsWith(" *")) {
                    DataType base = dtm.getDataType(spec.substring(0, spec.length() - 2).trim());
                    if (base == null) { println("NOTYPE " + spec); failed++; continue; }
                    fieldType = new PointerDataType(base, 4, dtm);
                } else {
                    fieldType = dtm.getDataType(spec);
                    if (fieldType == null) { println("NOTYPE " + spec); failed++; continue; }
                }
                String comment = f.length > 4 ? f[4] : "";
                try {
                    s.replaceAtOffset(off, fieldType, fieldType.getLength(), f[3], comment);
                    ok++;
                } catch (Throwable t) {
                    println("FAIL " + f[0] + "+" + f[1] + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("typed=" + ok + " failed=" + failed);
    }
}
