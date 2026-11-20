// For every function with parameters, compute each parameter's stack offset and report the trailing
// ones never accessed as [BP+off] anywhere in the body.
// Layout: [BP+0] saved BP, [BP+2] return offset, [BP+4] return segment (far only), so the first
// parameter starts at [BP+6] for a far function and [BP+4] for a near one.  Every argument occupies at
// least one full word: byte/word parameters take 2 bytes, 32-bit values and far pointers take 4.
// The offsets are read from the rendered instruction text, which is the form verified by hand.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import java.util.*;
import java.util.regex.*;

public class UnusedParams extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    @Override
    public void run() throws Exception {
        Pattern bpOff = Pattern.compile("BP \\+ 0x([0-9a-fA-F]+)");
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        for (Function fn : fm.getFunctions(true)) {
            Variable[] ps = fn.getParameters();
            if (ps.length == 0) continue;
            String cc = fn.getCallingConventionName();
            boolean far;
            if (cc != null && cc.toLowerCase().contains("far")) far = true;
            else if (cc != null && cc.toLowerCase().contains("near")) far = false;
            else {
                far = false;
                for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                    String m = ins.getMnemonicString();
                    if (m.equalsIgnoreCase("RETF")) { far = true; break; }
                    if (m.equalsIgnoreCase("RET")) break;
                }
            }
            Set<Integer> used = new HashSet<>();
            for (Instruction ins : lst.getInstructions(fn.getBody(), true)) {
                Matcher mt = bpOff.matcher(ins.toString());
                while (mt.find()) used.add(Integer.parseInt(mt.group(1), 16));
            }
            int[] offs = new int[ps.length];
            int cur = far ? 6 : 4;
            for (int k = 0; k < ps.length; k++) {
                offs[k] = cur;
                cur += slotSize(ps[k].getDataType());
            }
            int unusedTrailing = 0;
            boolean trailing = true;
            StringBuilder sb = new StringBuilder();
            for (int k = ps.length - 1; k >= 0; k--) {
                int len = slotSize(ps[k].getDataType());
                boolean any = false;
                for (int b = 0; b < len; b++) if (used.contains(offs[k] + b)) any = true;
                if (any) trailing = false;
                if (!any && trailing) {
                    unusedTrailing++;
                    sb.append(" #").append(k).append('(').append(ps[k].getName()).append(')');
                }
            }
            if (unusedTrailing > 0)
                println(fn.getEntryPoint() + "\t" + fn.getName() + "\t" + (far ? "far" : "near")
                        + "\tparams=" + ps.length + "\ttrailUnused=" + unusedTrailing + sb);
        }
    }
}
