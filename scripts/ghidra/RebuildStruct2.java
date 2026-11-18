// Rebuild a structure from a TSV, in order, with no extra marker column:
//   structPath<TAB>typePath<TAB>fieldName<TAB>comment
// All existing components of the struct named on the first data line are deleted first.
// Args: structs.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class RebuildStruct2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Structure s = null;
        String first = null;
        for (String line : lines) {
            if (line.trim().isEmpty() || line.startsWith("#")) continue;
            first = line.split("\t", -1)[0];
            break;
        }
        if (first == null) { println("no rows"); return; }
        DataType dt = dtm.getDataType(first);
        if (!(dt instanceof Structure)) { println("NOTSTRUCT " + first); return; }
        s = (Structure) dt;
        int ok = 0, bad = 0;
        int tx = currentProgram.startTransaction("rebuild struct2");
        try {
            while (s.getNumComponents() > 0) {
                s.deleteAtOffset(s.getComponent(0).getOffset());
            }
            for (String line : lines) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t", -1);
                if (f.length < 3) continue;
                String spec = f[1].trim();
                DataType t = null;
                Matcher am = Pattern.compile("^(.*)\\[(\\d+)\\]$").matcher(spec);
                Matcher pm = Pattern.compile("^(.*?)\\s*\\*(32)?$").matcher(spec);
                if (am.matches()) {
                    DataType base = dtm.getDataType(am.group(1));
                    if (base != null) t = new ArrayDataType(base, Integer.parseInt(am.group(2)), base.getLength());
                } else if (pm.matches()) {
                    DataType base = dtm.getDataType(pm.group(1));
                    if (base != null) t = new PointerDataType(base, pm.group(2) != null ? 4 : 2, dtm);
                } else {
                    t = dtm.getDataType(spec);
                }
                if (t == null) { println("NOTYPE " + spec); bad++; continue; }
                try {
                    s.add(t, f[2], f.length > 3 && !f[3].trim().isEmpty() ? f[3].trim() : null);
                    ok++;
                } catch (Throwable e) {
                    println("FAIL " + f[2] + " : " + e);
                    bad++;
                }
            }
            println("size=" + s.getLength() + " fields=" + s.getNumComponents());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("added=" + ok + " bad=" + bad);
    }
}
