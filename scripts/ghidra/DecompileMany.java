// Decompile several functions. Args: outdir address...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import java.io.*;

public class DecompileMany extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String dir = a[0];
        new File(dir).mkdirs();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        DecompileOptions opt = new DecompileOptions();
        opt.setInferConstantPointers(false);
        di.setOptions(opt);
        for (int i = 1; i < a.length; i++) {
            Address at = currentProgram.getAddressFactory().getAddress(a[i]);
            Function f = currentProgram.getFunctionManager().getFunctionAt(at);
            if (f == null) {
                if (currentProgram.getListing().getInstructionAt(at) == null) {
                    try { disassemble(at); } catch (Exception e) {}
                }
                f = createFunction(at, null);
            }
            if (f == null) { println("no function " + at); continue; }
            DecompileResults res = di.decompileFunction(f, 60, monitor);
            String text = res.getDecompiledFunction().getC();
            String name = a[i].replace(':', '_');
            PrintWriter w = new PrintWriter(new FileWriter(new File(dir, name + ".c")));
            w.println("// " + a[i] + "  " + f.getName() + "  size=" + f.getBody().getNumAddresses());
            w.print(text);
            w.close();
            println("ok " + a[i] + " " + f.getName());
        }
        di.dispose();
    }
}
