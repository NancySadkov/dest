// Remove an unused data type. Args: path
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;

public class DeleteType extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType dt = dtm.getDataType(a[0]);
        if (dt == null) { println("missing " + a[0]); return; }
        int tx = currentProgram.startTransaction("delete type");
        try {
            dtm.remove(dt, monitor);
            println("removed " + a[0]);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
