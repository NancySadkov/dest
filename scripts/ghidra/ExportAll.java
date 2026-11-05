// Export decompiled C for functions. Args: outdir [filter]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class ExportAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args.length > 0 ? args[0] : "export";
        String filter = args.length > 1 ? args[1] : "";
        File dir = new File(outdir);
        dir.mkdirs();

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        ifc.setOptions(opts);

        FunctionManager fm = currentProgram.getFunctionManager();
        int ok = 0, fail = 0, skip = 0;
        PrintWriter idx = new PrintWriter(new FileWriter(new File(dir, "index.tsv")));
        idx.println("address\tname\tsize\tsegment\tfile\tstatus");
        for (Function f : fm.getFunctions(true)) {
            String name = f.getName();
            if (f.isThunk()) { skip++; continue; }
            if (filter.length() > 0 && !f.getEntryPoint().toString().startsWith(filter)
                    && !name.contains(filter)) { continue; }
            Address a = f.getEntryPoint();
            MemoryBlock b = currentProgram.getMemory().getBlock(a);
            String seg = b != null ? b.getName() : "?";
            String base = seg + "__" + name.replace('/', '_').replace('\\','_')
                    .replace(':', '_').replace('*','_').replace('?','_')
                    .replace('<','_').replace('>','_').replace('|','_')
                    .replace('"','_');
            String file = base + ".c";
            DecompileResults res = ifc.decompileFunction(f, 60, monitor);
            String body;
            String status;
            if (res != null && res.decompileCompleted()) {
                body = res.getDecompiledFunction().getC();
                status = "ok";
                ok++;
            } else {
                body = "// FAILED " + (res == null ? "null" : res.getErrorMessage());
                status = "fail";
                fail++;
            }
            PrintWriter w = new PrintWriter(new FileWriter(new File(dir, file)));
            w.println("// " + name + " @ " + a + "  [" + seg + "]");
            w.println("// recovered by DeSt ghidra export");
            w.println(body);
            w.close();
            idx.println(a + "\t" + name + "\t" + f.getBody().getNumAddresses()
                    + "\t" + seg + "\t" + file + "\t" + status);
        }
        idx.close();
        println("exported ok=" + ok + " fail=" + fail + " skippedThunks=" + skip);
    }
}
