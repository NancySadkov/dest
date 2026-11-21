// Turn off `varArgs` for functions that declare no named parameter.
//
// Ghidra renders such a function's signature as `f(void...)`, which is not valid
// C, and there is nothing for the variadic part to follow.  A zero-parameter
// function is simply `f(void)`.
//
// Only functions whose name does not start with `ovr_` are touched: an overlay
// stub shares its target's signature, so clearing it on the stub would clear it
// on the target too.
//
// Args: [apply]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class FixVarArgs extends GhidraScript {
    @Override
    public void run() throws Exception {
        boolean apply = getScriptArgs().length > 0 && getScriptArgs()[0].equals("apply");
        int n = 0;
        int tx = currentProgram.startTransaction("clear pointless varargs");
        try {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                if (!f.hasVarArgs()) continue;
                if (f.getParameterCount() != 0) continue;
                if (f.getName().startsWith("ovr_")) continue;
                println((apply ? "CLEAR " : "WOULD CLEAR ") + f.getEntryPoint() + " " + f.getName());
                if (apply) f.setVarArgs(false);
                n++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println((apply ? "cleared=" : "would-clear=") + n);
    }
}
