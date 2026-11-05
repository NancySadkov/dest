// Export data types to a C header with Ghidra's DataTypeWriter.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.*;
import java.io.*;

public class ExportTypes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String out = a.length > 0 ? a[0] : "st_types.h";
        Writer w = new FileWriter(out);
        DataTypeWriter dtw = new DataTypeWriter(currentProgram.getDataTypeManager(), w, false);
        dtw.write(currentProgram.getDataTypeManager(), monitor);
        w.close();
        println("wrote " + out);
    }
}
