// Report functions with parameters laid out on the near base whose body contains RETF and whose
// convention is not far.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;

public class ConvCheck3 extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        int hits = 0;
        for (Function fn : fm.getFunctions(true)) {
            Variable[] ps = fn.getParameters();
            if (ps.length == 0) continue;
            String cc = fn.getCallingConventionName();
            String lc = cc == null ? "" : cc.toLowerCase();
            if (lc.contains("far")) continue;
            String st = ps[0].getVariableStorage().toString();
            if (!st.startsWith("Stack[0x2]")) continue;
            int retf = 0;
            for (Instruction ins : lst.getInstructions(fn.getBody(), true))
                if (ins.getMnemonicString().equalsIgnoreCase("RETF")) retf++;
            if (retf == 0) continue;
            println(fn.getEntryPoint() + "\t" + fn.getName() + "\tcc=" + cc + "\tretf=" + retf
                    + "\tparams=" + ps.length + "\tfirst=" + ps[0].getName() + ":" + st);
            hits++;
        }
        println("SUMMARY hits=" + hits);
    }
}
