// Report functions whose declared near/far convention contradicts their own return instruction.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;

public class ConvCheck extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        int nearButFar = 0, farButNear = 0, noRet = 0;
        for (Function fn : fm.getFunctions(true)) {
            boolean hasRetf = false, hasRet = false;
            for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                String m = ins.getMnemonicString();
                if (m.equalsIgnoreCase("RETF")) hasRetf = true;
                else if (m.equalsIgnoreCase("RET")) hasRet = true;
            }
            if (!hasRetf && !hasRet) { noRet++; continue; }
            String cc = fn.getCallingConventionName();
            String lc = cc == null ? "" : cc.toLowerCase();
            if (hasRetf && !hasRet && lc.contains("near")) {
                println("NEAR_BUT_FAR\t" + fn.getEntryPoint() + "\t" + fn.getName() + "\t" + cc);
                nearButFar++;
            } else if (hasRet && !hasRetf && lc.contains("far")) {
                println("FAR_BUT_NEAR\t" + fn.getEntryPoint() + "\t" + fn.getName() + "\t" + cc);
                farButNear++;
            }
        }
        println("SUMMARY nearButFar=" + nearButFar + " farButNear=" + farButNear
                + " noReturn=" + noRet);
    }
}
