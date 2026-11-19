// List functions whose signature is still Ghidra's default: addr, name, params, return.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;

public class ListDefaultProto extends GhidraScript {
    @Override
    public void run() throws Exception {
        int n = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.getSignatureSource() == SourceType.DEFAULT) {
                n++;
                println(f.getEntryPoint() + "\t" + f.getName() + "\t"
                        + f.getParameterCount() + "\t" + f.getReturnType().getName()
                        + "\t" + f.getSignatureSource());
            }
        }
        println("TOTAL " + n);
    }
}
