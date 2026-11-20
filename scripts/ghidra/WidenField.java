// Replace a byte range in a structure with one typed field.
// Args: struct<TAB>offset<TAB>length<TAB>typePath<TAB>name
// Clears every component that starts inside [offset, offset+length), then
// inserts the new field at offset (unlike MergeField, which uses replace()).
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class WidenField extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String[] f = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8).get(0).split("\t");
        if (f.length < 5) { println("usage: struct<TAB>off<TAB>len<TAB>type<TAB>name"); return; }
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType(f[0]);
        if (!(dt instanceof Structure)) { println("NOTSTRUCT " + f[0]); return; }
        Structure s = (Structure) dt;
        int off = Integer.decode(f[1]);
        int len = Integer.decode(f[2]);
        DataType ft = dtm.getDataType(f[3]);
        if (ft != null && ft.getLength() > 0 && len > ft.getLength()
                && len % ft.getLength() == 0)
            ft = new ArrayDataType(ft, len / ft.getLength(), ft.getLength());
        if (ft == null) { println("NOTYPE " + f[3]); return; }
        int tx = currentProgram.startTransaction("widen field");
        try {
            for (DataTypeComponent c : s.getComponents()) {
                int o = c.getOffset();
                if (o >= off && o < off + len) {
                    println("clear +" + o + " " + c.getFieldName());
                    s.clearComponent(o);
                }
            }
            s.replaceAtOffset(off, ft, len, f[4], "");
            println("widened " + f[0] + "+" + off + " to " + f[3] + " " + f[4]);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
