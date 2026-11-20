// Insert a typed field at an offset in a structure (shifts later components).
// Args: struct<TAB>offset<TAB>length<TAB>baseType<TAB>name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class InsertField extends GhidraScript {
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
        int tx = currentProgram.startTransaction("insert field");
        try {
            println("before len=" + s.getLength() + " comps=" + s.getNumComponents());
            s.insertAtOffset(off, field, len, f[4],
                    "GUESS: inferred from layout and manual terminology; no code reader or writer exists");
            println("after  len=" + s.getLength() + " comps=" + s.getNumComponents());
        } catch (Exception e) {
            println("FAIL " + e.getClass().getSimpleName() + ": " + e.getMessage());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
