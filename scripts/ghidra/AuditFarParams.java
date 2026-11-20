// Report-only audit of near/far parameter mistakes.
//
// Two independent pieces of evidence are collected per function:
//   LES/LDS [BP+d]  - the four bytes at BP+d are loaded as one far pointer
//   PUSH [BP+d+2] ; PUSH [BP+d] - the two words are passed on as one far pointer
//   maxBP           - the highest positive BP displacement the body touches
//
// A parameter is reported when the slot its near-pointer type occupies is read
// as half of a far pointer, or when the body touches stack slots past the end of
// the declared parameter area (i.e. the prototype is too small).
//
// Args: out.tsv   (no model changes)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.data.Pointer;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Variable;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.*;
import java.util.regex.*;

public class AuditFarParams extends GhidraScript {
    static int slotSize(DataType t) {
        int len = t.getLength();
        if (len <= 0) return 2;
        return len <= 2 ? 2 : 4;
    }

    @Override
    public void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "farparams.tsv";
        Pattern bpPlus = Pattern.compile("BP \\+ 0x([0-9a-fA-F]+)");
        Pattern lesLds = Pattern.compile("^(LES|LDS) ");
        int nFunc = 0, nLes = 0, nPush = 0, nOver = 0;
        PrintWriter w = new PrintWriter(out, StandardCharsets.UTF_8.name());
        w.println("function\taddress\tdisp\tkind\tparamIndex\tparamName\tparamType"
                + "\tparamLen\taligned4\tmaxBP\tparamAreaEnd");
        for (Function fn : currentProgram.getFunctionManager().getFunctions(true)) {
            if (fn.isThunk()) continue;
            Variable[] ps = fn.getParameters();
            if (ps.length == 0) continue;
            nFunc++;
            String cc = fn.getCallingConventionName();
            boolean farcc = cc != null && cc.toLowerCase().contains("far");
            int start = farcc ? 6 : 4;
            List<int[]> span = new ArrayList<>();   // {bpStart, paramIndex}
            int cur = start;
            for (int k = 0; k < ps.length; k++) {
                span.add(new int[]{cur, k});
                cur += slotSize(ps[k].getDataType());
            }
            int areaEnd = cur;

            Set<Integer> lesDisp = new TreeSet<>();
            Set<Integer> pushDisp = new TreeSet<>();
            int maxBP = -1;
            List<Instruction> insns = new ArrayList<>();
            for (Instruction ins : currentProgram.getListing().getInstructions(fn.getBody(), true))
                insns.add(ins);

            for (int i = 0; i < insns.size(); i++) {
                Instruction ins = insns.get(i);
                String s = ins.toString();
                Matcher m = bpPlus.matcher(s);
                while (m.find()) {
                    int d = Integer.parseInt(m.group(1), 16);
                    maxBP = Math.max(maxBP, d);
                    if (lesLds.matcher(s).find()) lesDisp.add(d);
                }
                // PUSH [BP+d+2] followed by PUSH [BP+d]
                String pat = "PUSH word ptr \\[BP \\+ 0x([0-9a-fA-F]+)\\]";
                Matcher a = Pattern.compile(pat).matcher(s);
                if (a.matches() && i + 1 < insns.size()) {
                    int d2 = Integer.parseInt(a.group(1), 16);
                    Matcher b = Pattern.compile(pat).matcher(insns.get(i + 1).toString());
                    if (b.matches() && Integer.parseInt(b.group(1), 16) == d2 - 2) {
                        pushDisp.add(d2 - 2);
                    }
                }
            }

            for (int d : lesDisp) {
                int[] e = find(span, d);
                int k = e == null ? -1 : e[1];
                DataType t = k < 0 ? null : ps[k].getDataType();
                boolean near = t instanceof Pointer && t.getLength() == 2;
                w.println(fn.getName() + "\t" + fn.getEntryPoint() + "\t" + d + "\tLES\t" + k
                        + "\t" + (k < 0 ? "-" : ps[k].getName()) + "\t"
                        + (t == null ? "-" : t.getName()) + "\t"
                        + (t == null ? -1 : t.getLength()) + "\t" + ((d - 2) % 4 == 0) + "\t"
                        + maxBP + "\t" + areaEnd);
                nLes++;
                if (near) {}
            }
            for (int d : pushDisp) {
                if (lesDisp.contains(d)) continue;
                int[] e = find(span, d);
                int k = e == null ? -1 : e[1];
                DataType t = k < 0 ? null : ps[k].getDataType();
                w.println(fn.getName() + "\t" + fn.getEntryPoint() + "\t" + d + "\tPUSHPAIR\t" + k
                        + "\t" + (k < 0 ? "-" : ps[k].getName()) + "\t"
                        + (t == null ? "-" : t.getName()) + "\t"
                        + (t == null ? -1 : t.getLength()) + "\t" + ((d - 2) % 4 == 0) + "\t"
                        + maxBP + "\t" + areaEnd);
                nPush++;
            }
            if (maxBP >= areaEnd) {
                w.println(fn.getName() + "\t" + fn.getEntryPoint() + "\t-\tOVERFLOW\t-1\t-\t-\t-1\t-\t"
                        + maxBP + "\t" + areaEnd);
                nOver++;
            }
        }
        w.close();
        println("functions_with_params=" + nFunc + " LES=" + nLes + " PUSHPAIR=" + nPush
                + " OVERFLOW=" + nOver);
        println("wrote " + out);
    }

    private static int[] find(List<int[]> span, int d) {
        int[] best = null;
        for (int[] e : span) {
            if (e[0] <= d && d < e[0] + 2) return e;
            if (e[0] <= d && (best == null || e[0] > best[0])) best = e;
        }
        return best;
    }
}
