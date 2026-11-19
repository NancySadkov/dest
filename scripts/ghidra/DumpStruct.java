// Print a structure's components as rebuild rows:
//   offset  typeSpec  name  comment
// typeSpec is basePath + " *32"/" *" for pointers and basePath + "[n]" for arrays.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class DumpStruct extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        DataType dt = currentProgram.getDataTypeManager().getDataType(a[0]);
        if (!(dt instanceof Structure)) { println("NOTSTRUCT " + a[0]); return; }
        Structure s = (Structure) dt;
        println("STRUCT " + s.getPathName() + " size=" + s.getLength()
                + " components=" + s.getNumComponents());
        for (DataTypeComponent c : s.getComponents()) {
            DataType t = c.getDataType();
            String spec;
            if (t instanceof Pointer) {
                int len = t.getLength();
                spec = ((Pointer) t).getDataType().getPathName() + (len == 4 ? " *32" : " *");
            } else if (t instanceof Array) {
                Array at = (Array) t;
                spec = at.getDataType().getPathName() + "[" + at.getNumElements() + "]";
            } else {
                spec = t.getPathName();
            }
            println(String.format("%-4d\t%s\t%s\t%s", c.getOffset(), spec,
                    c.getFieldName() == null ? "" : c.getFieldName(),
                    c.getComment() == null ? "" : c.getComment()));
        }
    }
}
