// Replace a byte range in a structure with one typed field (array-aware, ordinal deletion).
// Args: tsv with struct<TAB>offset<TAB>length<TAB>baseType<TAB>name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class WidenField2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] f = Files.readAllLines(Paths.get(getScriptArgs()[0]), StandardCharsets.UTF_8)
                .get(0).split("\t");
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType(f[0]);
        if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); return; }
        Structure s = (Structure) dt;
        int off = Integer.decode(f[1]);
        int len = Integer.decode(f[2]);
        DataType base = dtm.getDataType(f[3]);
        if (base == null) { println("NOTYPE " + f[3]); return; }
        DataType field = (len > base.getLength() && len % base.getLength() == 0)
                ? new ArrayDataType(base, len / base.getLength(), base.getLength())
                : base;
        println("field " + field.getName() + " len=" + field.getLength());
        int tx = currentProgram.startTransaction("widen2");
        try {
            List<Integer> ords = new ArrayList<>();
            for (DataTypeComponent c : s.getComponents())
                if (c.getOffset() >= off && c.getOffset() < off + len) ords.add(c.getOrdinal());
            ords.sort(Collections.reverseOrder());
            for (int o : ords) {
                println("delete ordinal " + o);
                s.delete(o);
            }
            s.replaceAtOffset(off, field, len, f[4],
                    "GUESS: inferred from layout and manual terminology; no code reader or writer exists");
            println("OK +" + off + " -> " + field.getName() + " " + f[4]
                    + "  structLen=" + s.getLength());
        } catch (Exception e) {
            println("FAIL " + e.getClass().getSimpleName() + ": " + e.getMessage());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
