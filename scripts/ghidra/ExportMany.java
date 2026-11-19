// Decompile a list of functions to files. Args: tsv with address<TAB>outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportMany extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        DecompileOptions opts = new DecompileOptions();
        opts.setProtoEvalModel("__cdecl16far");
        opts.setDefaultTimeout(1800);
        opts.setMaxPayloadMBytes(256);
        opts.setMaxInstructions(2000000);
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        ifc.setOptions(opts);
        int ok = 0, fail = 0;
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#")) continue;
            String[] f = line.split("\t");
            Address addr = currentProgram.getAddressFactory().getAddress(f[0]);
            Function fn = addr == null ? null : currentProgram.getFunctionManager().getFunctionAt(addr);
            if (fn == null) { println("nofunc " + f[0]); fail++; continue; }
            DecompileResults res = ifc.decompileFunction(fn, 1800, monitor);
            PrintWriter w = new PrintWriter(new FileWriter(f[1]));
            w.println("/* " + fn.getName() + " @ " + fn.getEntryPoint() + " */");
            if (res != null && res.decompileCompleted()) {
                w.println(res.getDecompiledFunction().getC());
                ok++;
            } else {
                w.println("/* FAILED: " + (res == null ? "null" : res.getErrorMessage()) + " */");
                fail++;
            }
            w.close();
        }
        println("exported=" + ok + " failed=" + fail);
    }
}
