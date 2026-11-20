// Remove an equate by name. Args: name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.Equate;

public class RemoveEquate extends GhidraScript {
    @Override
    public void run() throws Exception {
        String name = getScriptArgs()[0];
        Equate e = currentProgram.getEquateTable().getEquate(name);
        if (e == null) { println("no equate " + name); return; }
        int tx = currentProgram.startTransaction("remove equate");
        try {
            currentProgram.getEquateTable().removeEquate(name);
            println("removed equate " + name);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
