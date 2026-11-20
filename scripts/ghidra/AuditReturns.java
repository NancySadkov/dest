// Classify, for every function, which registers are actually written on the tail
// path that reaches each RET.  This distinguishes byte/word returns from far
// (DX:AX) pointer returns, which is what decides whether Ghidra may legally
// fold a constant into a string/global address.
//
// Args: out.tsv
// Output columns: address, name, declRet, declLen, kind, regs, rets, unknown
//   kind: FAR (DX written) | WORD (AX written, no DX) | BYTE (only AL/AH)
//         | MIXED | UNKNOWN (tail hits a call/jump before any return reg write)
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class AuditReturns extends GhidraScript {

    private static final Set<String> RETREGS = new HashSet<>(Arrays.asList(
            "AL", "AH", "AX", "EAX", "DX", "DL", "DH", "EDX"));

    @Override
    public void run() throws Exception {
        String out = getScriptArgs().length > 0 ? getScriptArgs()[0] : "returns.tsv";
        int nFar = 0, nWord = 0, nByte = 0, nMixed = 0, nUnknown = 0, nTotal = 0;
        PrintWriter w = new PrintWriter(out, StandardCharsets.UTF_8.name());
        w.println("address\tname\tdeclRet\tdeclLen\tkind\tregs\trets\tunknown");
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.isThunk()) continue;
            nTotal++;
            Set<String> all = new TreeSet<>();
            boolean anyUnknown = false;
            boolean anyFar = false, anyWord = false, anyByte = false;
            int rets = 0;
            InstructionIterator it =
                    currentProgram.getListing().getInstructions(f.getBody(), true);
            for (Instruction ins : it) {
                if (!ins.getMnemonicString().startsWith("RET")) continue;
                rets++;
                Set<String> r = new TreeSet<>();
                boolean u = false;
                Instruction p = ins.getPrevious();
                for (int n = 0; n < 24 && p != null; n++) {
                    if (!f.getBody().contains(p.getAddress())) break;
                    if (p.getFlowType().isCall() || p.getFlowType().isJump()
                            || p.getFlowType().isTerminal()) { u = true; break; }
                    for (Object o : p.getResultObjects())
                        if (o instanceof Register) r.add(((Register) o).getName());
                    p = p.getPrevious();
                }
                all.addAll(r);
                if (u && r.isEmpty()) { anyUnknown = true; continue; }
                if (r.contains("DX") || r.contains("EDX") || r.contains("DL")
                        || r.contains("DH")) anyFar = true;
                else if (r.contains("AX") || r.contains("EAX")) anyWord = true;
                else if (r.contains("AL") || r.contains("AH")) anyByte = true;
                else anyUnknown = true;
            }
            String kind;
            if (anyUnknown && !anyFar && !anyWord && !anyByte) kind = "UNKNOWN";
            else if (anyFar) kind = "FAR";
            else if (anyWord) kind = "WORD";
            else if (anyByte) kind = "BYTE";
            else kind = "MIXED";
            if (kind.equals("FAR")) nFar++;
            else if (kind.equals("WORD")) nWord++;
            else if (kind.equals("BYTE")) nByte++;
            else if (kind.equals("MIXED")) nMixed++;
            else nUnknown++;

            DataType dt = f.getReturnType();
            w.println(f.getEntryPoint() + "\t" + f.getName() + "\t"
                    + (dt == null ? "?" : dt.getName()) + "\t"
                    + (dt == null ? -1 : dt.getLength()) + "\t" + kind + "\t"
                    + String.join(",", all) + "\t" + rets + "\t" + anyUnknown);
        }
        w.close();
        println("functions=" + nTotal + " FAR=" + nFar + " WORD=" + nWord + " BYTE=" + nByte
                + " MIXED=" + nMixed + " UNKNOWN=" + nUnknown);
        println("wrote " + out);
    }
}
