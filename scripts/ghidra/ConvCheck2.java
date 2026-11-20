// Report far functions whose parameters are still laid out on the near base, i.e. the function has
// no explicit calling convention (or a near one), a RETF, parameters, and its first parameter
// starts at Stack[0x2].
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;

public class ConvCheck2 extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        int hits = 0;
        for (Function fn : fm.getFunctions(true)) {
            Variable[] ps = fn.getParameters();
            if (ps.length == 0) continue;
            boolean hasRetf = false, hasRet = false;
            for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                String m = ins.getMnemonicString();
                if (m.equalsIgnoreCase("RETF")) hasRetf = true;
                else if (m.equalsIgnoreCase("RET")) hasRet = true;
            }
            if (!hasRetf || hasRet) continue;
            String cc = fn.getCallingConventionName();
            String lc = cc == null ? "" : cc.toLowerCase();
            if (lc.contains("far")) continue;
            String st = ps[0].getVariableStorage().toString();
            if (!st.startsWith("Stack[0x2]")) continue;
            println(fn.getEntryPoint() + "\t" + fn.getName() + "\tcc=" + cc
                    + "\tparams=" + ps.length + "\tfirst=" + ps[0].getName() + ":" + st);
            hits++;
        }
        println("SUMMARY nearLayoutFarFuncs=" + hits);
    }
}
