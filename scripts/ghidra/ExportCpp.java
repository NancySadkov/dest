// Export the whole program as C/C++ using Ghidra's CppExporter.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.util.exporter.*;
import ghidra.app.decompiler.*;
import java.io.*;

public class ExportCpp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String out = a.length > 0 ? a[0] : "st_export.c";
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        CppExporter ex = new CppExporter(opts, true, true, true, true, true, "");
        ex.export(new File(out), currentProgram,
                   currentProgram.getMemory().getLoadedAndInitializedAddressSet(), monitor);
        println("wrote " + out);
    }
}
