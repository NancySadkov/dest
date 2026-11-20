// For each address in a TSV, list every reference with its access kind (read / write), so a global
// with no reader anywhere can be shown rather than assumed.
// The reference type is used when Ghidra classified it; otherwise the operand whose scalar matches
// the address (DS-relative or BSS-relative) is inspected.
// Args: tsv with address<TAB>name
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.OperandType;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class RefKinds extends GhidraScript {
    static final long DGROUP_DELTA = 0x4100L;   // DS:0x8fxx <-> BSS 0xd0xx observed mapping

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]), StandardCharsets.UTF_8);
        ReferenceManager rm = currentProgram.getReferenceManager();
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing lst = currentProgram.getListing();
        for (String line : lines) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("#") || line.startsWith("address\t")) continue;
            String[] f = line.split("\t");
            Address ad = currentProgram.getAddressFactory().getAddress(f[0]);
            if (ad == null) { println("BADADDR " + f[0]); continue; }
            long off = ad.getOffset() & 0xffff;
            int reads = 0, writes = 0, other = 0;
            StringBuilder sb = new StringBuilder();
            for (Reference r : rm.getReferencesTo(ad)) {
                Address from = r.getFromAddress();
                Instruction ins = lst.getInstructionAt(from);
                if (ins == null) { other++; sb.append(" !").append(from); continue; }
                RefType rt = r.getReferenceType();
                String kind = null;
                if (rt.isWrite()) kind = "w";
                else if (rt.isRead()) kind = "r";
                if (kind == null) {
                    for (int i = 0; i < ins.getNumOperands(); i++) {
                        boolean hit = false;
                        for (Object o : ins.getOpObjects(i)) {
                            if (o instanceof Address && ((Address) o).equals(ad)) hit = true;
                            if (o instanceof Scalar) {
                                long v = ((Scalar) o).getUnsignedValue() & 0xffff;
                                if (v == off || v == ((off + DGROUP_DELTA) & 0xffff)) hit = true;
                            }
                        }
                        if (!hit) continue;
                        int t = ins.getOperandType(i);
                        if ((t & OperandType.WRITE) != 0) kind = "w";
                        else if ((t & OperandType.READ) != 0) kind = "r";
                    }
                }
                if (kind == null) kind = "?";
                if (kind.equals("w")) writes++;
                else if (kind.equals("r")) reads++;
                else other++;
                Function fn = fm.getFunctionContaining(from);
                sb.append(" ").append(kind).append("@").append(from)
                  .append("(").append(fn == null ? "-" : fn.getName()).append(")");
            }
            println(f[0] + "\t" + f[1] + "\treads=" + reads + "\twrites=" + writes
                    + "\tother=" + other + sb);
        }
    }
}
