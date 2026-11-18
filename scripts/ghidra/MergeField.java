// Replace a byte range inside a structure with one field: struct<TAB>offset<TAB>length<TAB>typePath<TAB>name
// Works where SetFieldType cannot, because it clears the overlapping components first.
// Args: tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class MergeField extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, failed = 0;
        int tx = currentProgram.startTransaction("merge fields");
        try {
            for (String line : lines) {
                line = line.trim();
                if (line.isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 5) continue;
                DataType dt = dtm.getDataType(f[0]);
                if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); failed++; continue; }
                Structure s = (Structure) dt;
                int off = Integer.decode(f[1]);
                int len = Integer.decode(f[2]);
                DataType ft = dtm.getDataType(f[3].trim());
                if (ft == null) { println("NOTYPE " + f[3]); failed++; continue; }
                println("class " + s.getClass().getName() + " for " + f[0]);
                try {
                    // Clear the range, then set the new field.
                    for (DataTypeComponent c : s.getComponents()) {
                        if (c.getOffset() >= off && c.getOffset() + c.getLength() <= off + len) {
                            s.clearComponent(c.getOffset());
                        }
                    }
                    s.replace(off, ft, len);
                    DataTypeComponent nc = s.getComponentAt(off);
                    if (nc == null) throw new RuntimeException("no component at " + off);
                    nc.setFieldName(f[4]);
                    ok++;
                } catch (Exception e) {
                    println("FAIL " + f[0] + "+0x" + Integer.toHexString(off) + " : " + e);
                    failed++;
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("merged=" + ok + " failed=" + failed);
    }
}
