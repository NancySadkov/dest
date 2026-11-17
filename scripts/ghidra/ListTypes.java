// Print data type paths matching a name.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.util.*;

public class ListTypes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String needle = a.length > 0 ? a[0] : "";
        Iterator<DataType> it = currentProgram.getDataTypeManager().getAllDataTypes();
        while (it.hasNext()) {
            DataType d = it.next();
            if (d.getName().toLowerCase().contains(needle.toLowerCase()))
                println(d.getPathName() + " size=" + d.getLength());
        }
    }
}
