// Dump every function: address, name, thunk target, size, and whether the name looks generated.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ListFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new OutputStreamWriter(
                new FileOutputStream(a[0]), StandardCharsets.UTF_8));
        w.println("address\tname\tthunk\tsize\tparams\tnoReturn");
        int n = 0;
        for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
            Function t = fn.isThunk() ? fn.getThunkedFunction(true) : null;
            w.println(fn.getEntryPoint() + "\t" + fn.getName() + "\t"
                    + (t == null ? "" : t.getName()) + "\t" + fn.getBody().getNumAddresses()
                    + "\t" + fn.getParameterCount() + "\t" + fn.hasNoReturn());
            n++;
        }
        w.close();
        println("wrote " + a[0] + " funcs=" + n);
    }
}
