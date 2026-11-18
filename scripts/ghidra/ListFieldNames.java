// Print a structure's components with the AuditNaming auto-field verdict.
// Args: structName
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.util.regex.*;

public class ListFieldNames extends GhidraScript {
    static final Pattern AUTO_FIELD = Pattern.compile(
        "^(field\\d*_0x[0-9a-f]+|unnamed\\w*|pad_\\d+|unk\\w*|FUN_\\w+|DAT_\\w+)$");

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType(a[0]);
        if (!(dt instanceof Structure)) { println("NOTSTRUCT " + a[0]); return; }
        Structure s = (Structure) dt;
        println("STRUCT " + s.getPathName() + " components=" + s.getNumComponents());
        int auto = 0;
        for (int i = 0; i < s.getNumComponents(); i++) {
            DataTypeComponent c = s.getComponent(i);
            String n = c.getFieldName();
            boolean isAuto = (n == null) || AUTO_FIELD.matcher(n).matches();
            if (isAuto) auto++;
            println(String.format("+%-4d %-18s %-24s len=%-3d %s",
                    c.getOffset(), n == null ? "(null)" : n,
                    c.getDataType().getName(), c.getLength(), isAuto ? "AUTO" : ""));
        }
        println("AUTO " + auto);
    }
}
