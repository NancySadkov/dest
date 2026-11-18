// Rebuild a structure from a TSV description, in order.
// Args: structs.tsv   (struct/dataTypePath/fieldName/comment, one component per line;
//                      a blank dataTypePath means "repeat", not used)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class RebuildStruct extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        int ok = 0, bad = 0;
        int tx = currentProgram.startTransaction("rebuild struct");
        try {
            Structure s = null;
            for (String line : lines) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                DataType dt = dtm.getDataType(f[0]);
                if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); bad++; continue; }
                s = (Structure) dt;
                if (s.getNumComponents() > 0) {
                    while (s.getNumComponents() > 0) {
                        s.deleteAtOffset(s.getComponent(0).getOffset());
                    }
                }
                break;
            }
            if (s == null) { println("no struct"); return; }
            for (String line : lines) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 4) continue;
                if (f[0].startsWith("/")) continue;
                DataType t = null;
                String spec = f[1].trim();
                java.util.regex.Matcher am =
                        java.util.regex.Pattern.compile("^(.*)\\[(\\d+)\\]$").matcher(spec);
                java.util.regex.Matcher pm =
                        java.util.regex.Pattern.compile("^(.*?)\\s*\\*(32)?$").matcher(spec);
                if (am.matches()) {
                    DataType base = dtm.getDataType(am.group(1));
                    if (base != null) {
                        t = new ArrayDataType(base, Integer.parseInt(am.group(2)), base.getLength());
                    }
                } else if (pm.matches()) {
                    DataType base = dtm.getDataType(pm.group(1));
                    if (base != null) {
                        t = new ghidra.program.model.data.PointerDataType(base,
                                pm.group(2) != null ? 4 : 2, dtm);
                    }
                } else {
                    t = dtm.getDataType(spec);
                }
                if (t == null) { println("NOTYPE " + f[1]); bad++; continue; }
                String comment = f.length > 3 ? f[3] : null;
                try {
                    s.add(t, f[2], comment);
                    ok++;
                } catch (Throwable e) {
                    println("FAIL " + f[2] + " : " + e);
                    bad++;
                }
            }
            println("length=" + s.getLength() + " added=" + ok + " bad=" + bad);
            for (int i = 0; i < s.getNumComponents(); i++) {
                DataTypeComponent c = s.getComponent(i);
                println("  +" + c.getOffset() + " " + c.getFieldName()
                        + " : " + c.getDataType().getName() + " [" + c.getLength() + "]");
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
