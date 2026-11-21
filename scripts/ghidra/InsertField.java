// Insert typed fields at explicit offsets in a structure (shifts later components).
// Args: TSV with struct<TAB>offset<TAB>length<TAB>baseType<TAB>name[<TAB>comment]
// Rows must be given from the HIGHEST offset down, because each insert shifts
// everything after it.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class InsertField extends GhidraScript {
    @Override
    public void run() throws Exception {
        List<String> lines = Files.readAllLines(Paths.get(getScriptArgs()[0]),
                StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("insert fields");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 5) { println("BADLINE " + line); continue; }
                DataType dt = dtm.getDataType(f[0]);
                if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); failed++; continue; }
                Structure s = (Structure) dt;
                int off = Integer.decode(f[1]);
                int len = Integer.decode(f[2]);
                DataType base = dtm.getDataType(f[3]);
                if (base == null) { println("NOTYPE " + f[3]); failed++; continue; }
                DataType field = (len > base.getLength() && len % base.getLength() == 0)
                        ? new ArrayDataType(base, len / base.getLength(), base.getLength())
                        : base;
                String comment = f.length > 5 && !f[5].trim().isEmpty()
                        ? f[5].trim() : null;
                int before = s.getLength();
                try {
                    s.insertAtOffset(off, field, len, f[4], comment);
                    println(f[0] + "." + f[4] + " @" + f[1] + " len " + before + " -> "
                            + s.getLength());
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + "." + f[4] + " : " + e.getClass().getSimpleName()
                            + " " + e.getMessage());
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("inserted=" + ok + " failed=" + failed);
    }
}
