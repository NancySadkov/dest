// Parameters typed as a two-byte (near) pointer but loaded with LES/LDS from their own stack slot are
// really fat pointers.  Retype them to a four-byte pointer to the same base type, which also fixes the
// offsets of the following parameters.
// Args: none (report + apply).  Prints every change.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import java.util.*;
import java.util.regex.*;

public class FarPtrParams extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    @Override
    public void run() throws Exception {
        Pattern les = Pattern.compile("^(LES|LDS) ");
        Pattern bpOff = Pattern.compile("BP \\+ 0x([0-9a-fA-F]+)");
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        int changes = 0;
        int tx = currentProgram.startTransaction("far pointer parameters");
        try {
            for (Function fn : fm.getFunctions(true)) {
                Variable[] ps = fn.getParameters();
                if (ps.length == 0) continue;
                String cc = fn.getCallingConventionName();
                boolean far = cc != null && cc.toLowerCase().contains("far");
                // repeatedly widen the first qualifying parameter, recomputing offsets each time
                boolean changed = true;
                while (changed) {
                    changed = false;
                    int cur = far ? 6 : 4;
                    for (int k = 0; k < ps.length && !changed; k++) {
                        DataType t = ps[k].getDataType();
                        int sz = slotSize(t);
                        if (sz == 2 && t instanceof Pointer) {
                            boolean loaded = false;
                            for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                                if (!les.matcher(ins.toString()).find()) continue;
                                Matcher m = bpOff.matcher(ins.toString());
                                while (m.find()) {
                                    if (Integer.parseInt(m.group(1), 16) == cur) loaded = true;
                                }
                            }
                            if (loaded) {
                                DataType base = ((Pointer) t).getDataType();
                                Pointer farPtr = new PointerDataType(base, 4,
                                        currentProgram.getDataTypeManager());
                                ps[k].setDataType(farPtr, SourceType.USER_DEFINED);
                                println("FAR " + fn.getName() + " #" + k + " " + ps[k].getName()
                                        + " : " + t.getName() + " -> " + farPtr.getName());
                                changes++;
                                changed = true;
                            }
                        }
                        cur += slotSize(ps[k].getDataType());
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("widened=" + changes);
    }
}
