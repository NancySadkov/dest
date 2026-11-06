// Remove data references that Ghidra's constant analyzer attached to
// segment-register constants (0x2410, 0x2337, ...).  Those constants are
// segments, not pointers into DGROUP; leaving the reference makes the
// decompiler render e.g. 0x2410 as "<string> + n".
//
// Args: <doc_dir>
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class StripSegmentRefs extends GhidraScript {
    private int hex(String s) {
        s = s.trim();
        if (s.isEmpty()) return 0;
        if (s.startsWith("0x") || s.startsWith("0X")) s = s.substring(2);
        return Integer.parseInt(s, 16);
    }

    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String doc = a[0];
        Set<Integer> segs = new HashSet<>();
        segs.add(0x1000);
        segs.add(0x2410);
        segs.add(0x225D);
        segs.add(0x2D5A);

        BufferedReader r = Files.newBufferedReader(
                Paths.get(doc, "fbov_segments.csv"));
        String ln;
        while ((ln = r.readLine()) != null) {
            if (ln.startsWith("index")) continue;
            String[] c = ln.split(",");
            segs.add(hex(c[2]));
        }
        r.close();

        r = Files.newBufferedReader(Paths.get(doc, "fbov_overlays.csv"));
        while ((ln = r.readLine()) != null) {
            if (ln.startsWith("header_seg")) continue;
            String[] c = ln.split(",");
            segs.add(hex(c[1])); // header_static_seg
            segs.add(hex(c[2])); // code_seg
        }
        r.close();

        ReferenceManager rm = currentProgram.getReferenceManager();
        int tx = currentProgram.startTransaction("strip segment constants");
        int removed = 0;
        try {
            Listing lst = currentProgram.getListing();
            InstructionIterator it = lst.getInstructions(true);
            while (it.hasNext()) {
                Instruction ins = it.next();
                for (int op = 0; op < ins.getNumOperands(); op++) {
                    Object[] objs = ins.getOpObjects(op);
                    boolean hit = false;
                    for (Object o : objs) {
                        if (o instanceof Scalar) {
                            long v = ((Scalar) o).getUnsignedValue();
                            if (segs.contains((int) (v & 0xFFFF))) hit = true;
                        }
                    }
                    if (!hit) continue;
                    Reference[] refs = ins.getOperandReferences(op);
                    for (Reference ref : refs) {
                        ins.removeOperandReference(op, ref.getToAddress());
                        removed++;
                    }
                }
            }
            println("STRIPPED segment-constant references=" + removed
                    + " segments=" + segs.size());
        } finally {
            currentProgram.endTransaction(tx, true);
        }
    }
}
