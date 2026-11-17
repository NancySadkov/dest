// Rename structure fields from a TSV (struct<TAB>offset<TAB>name<TAB>comment).
// Args: fields.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RenameFields extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, missing = 0, failed = 0;
        int tx = currentProgram.startTransaction("rename fields");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                if (f.length < 3) continue;
                DataType dt = dtm.getDataType(f[0]);
                if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); missing++; continue; }
                Structure s = (Structure) dt;
                int off = Integer.decode(f[1]);
                DataTypeComponent c = s.getComponentAt(off);
                if (c == null) { println("NOFIELD " + f[0] + "+" + f[1]); missing++; continue; }
                String comment = f.length > 3 ? f[3] : "";
                try {
                    s.replaceAtOffset(off, c.getDataType(), c.getLength(),
                                      f[2], comment);
                    ok++;
                } catch (Throwable t) {
                    println("FAIL " + f[0] + "+" + f[1] + " : " + t);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " missing=" + missing + " failed=" + failed);
    }
}
