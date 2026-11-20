// List structure fields whose names are type paths or otherwise not identifiers.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class ListBadFields extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("struct\toffset\tname\ttype\tlength");
        int n = 0;
        Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
        while (it.hasNext()) {
            DataType dt = it.next();
            if (!(dt instanceof Structure)) continue;
            Structure s = (Structure) dt;
            for (DataTypeComponent c : s.getComponents()) {
                String nm = c.getFieldName();
                if (nm == null) continue;
                boolean bad = nm.indexOf('/') >= 0 || nm.indexOf('.') >= 0
                        || nm.equals("undefined") || nm.matches("undefined[0-9]")
                        || nm.startsWith("UNK") || nm.indexOf(':') >= 0;
                if (!bad) continue;
                w.println(s.getName() + "\t" + c.getOffset() + "\t" + nm + "\t"
                        + c.getDataType().getName() + "\t" + c.getLength());
                n++;
            }
        }
        w.close();
        println("bad field names: " + n);
    }
}
