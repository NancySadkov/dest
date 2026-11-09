// Attach a jump-table override to the menu function.
// Args: function_addr table_addr target1 ...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import java.util.*;
import java.lang.reflect.*;

public class AddJumpTable extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address fnAddr = toAddr(a[0]);
        Address table = toAddr(a[1]);
        ArrayList<Address> cases = new ArrayList<Address>();
        for (int i = 2; i < a.length; i++) cases.add(toAddr(a[i]));
        Function f = currentProgram.getFunctionManager().getFunctionAt(fnAddr);
        if (f == null) { println("no function at " + fnAddr); return; }
        int tx = currentProgram.startTransaction("jump table");
        try {
            JumpTable jt = new JumpTable(table, cases, false, 2);
            Field of = JumpTable.class.getDeclaredField("override");
            of.setAccessible(true);
            of.set(jt, jt.new BasicOverride(cases));
            jt.writeOverride(f);
            println("wrote jump table with " + cases.size() + " cases");
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
