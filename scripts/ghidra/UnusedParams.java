// For every function with parameters, compute each parameter's stack offset and report the trailing
// ones never accessed as [BP+off] anywhere in the body.
// Layout: [BP+0] saved BP, [BP+2] return offset, [BP+4] return segment only for far functions, so the
// first parameter starts at [BP+6] for a far function and [BP+4] for a near one.  The near/far test is
// taken from the function's own return instruction (RET vs RETF).
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import java.util.*;

public class UnusedParams extends GhidraScript {
    @Override
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        for (Function fn : fm.getFunctions(true)) {
            Variable[] ps = fn.getParameters();
            if (ps.length == 0) continue;
            boolean far = false;
            for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                String m = ins.getMnemonicString();
                if (m.equalsIgnoreCase("RETF")) { far = true; break; }
                if (m.equalsIgnoreCase("RET")) break;
            }
            Set<Integer> used = new HashSet<>();
            for (Instruction ins : lst.getInstructions(fn.getBody(), true))
                for (int i = 0; i < ins.getNumOperands(); i++)
                    for (Object o : ins.getOpObjects(i))
                        if (o instanceof Scalar) {
                            long v = ((Scalar) o).getSignedValue();
                            if (v >= 4 && v < 0x200) used.add((int) v);
                        }
            int[] offs = new int[ps.length];
            int cur = far ? 6 : 4;
            for (int k = 0; k < ps.length; k++) {
                offs[k] = cur;
                DataType t = ps[k].getDataType();
                int len = t.getLength();
                if (len <= 0 || len > 4) len = (t instanceof Pointer) ? 4 : 2;
                cur += len;
            }
            int unusedCount = 0;
            boolean trailing = true;
            StringBuilder sb = new StringBuilder();
            for (int k = ps.length - 1; k >= 0; k--) {
                DataType t = ps[k].getDataType();
                int len = t.getLength();
                if (len <= 0 || len > 4) len = (t instanceof Pointer) ? 4 : 2;
                boolean any = false;
                for (int b = 0; b < len; b++) if (used.contains(offs[k] + b)) any = true;
                if (any) trailing = false;
                if (!any && trailing) {
                    unusedCount++;
                    sb.append(" #").append(k).append('(').append(ps[k].getName()).append(')');
                }
            }
            if (unusedCount > 0)
                println(fn.getEntryPoint() + "\t" + fn.getName() + "\t" + (far ? "far" : "near")
                        + "\tparams=" + ps.length + "\ttrailUnused=" + unusedCount + sb);
        }
    }
}
