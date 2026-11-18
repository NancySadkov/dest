// Dump every function's stored parameters and locals to a CSV.
// Args: out.csv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ListAllVars extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(a[0]), StandardCharsets.UTF_8));
        w.println("func\tname\tkind\tvar\ttype\tlength");
        int n = 0;
        for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
            for (Variable v : fn.getParameters()) {
                w.println(fn.getEntryPoint() + "\t" + fn.getName() + "\tparam\t" + v.getName()
                        + "\t" + v.getDataType().getName() + "\t" + v.getLength());
                n++;
            }
            for (Variable v : fn.getLocalVariables()) {
                w.println(fn.getEntryPoint() + "\t" + fn.getName() + "\tlocal\t" + v.getName()
                        + "\t" + v.getDataType().getName() + "\t" + v.getLength());
                n++;
            }
        }
        w.close();
        println("wrote " + a[0] + " vars=" + n);
    }
}
