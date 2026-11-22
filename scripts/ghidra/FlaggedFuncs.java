// List functions with special flags: inline, no-return, thunk, external.
// Args: out.tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import java.io.*;

public class FlaggedFuncs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            String flags = "";
            if (f.isInline()) flags += "INLINE ";
            if (f.hasNoReturn()) flags += "NORET ";
            if (f.isThunk()) flags += "THUNK ";
            if (f.isExternal()) flags += "EXTERNAL ";
            if (!flags.isEmpty())
                w.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + flags.trim());
        }
        w.close();
    }
}
