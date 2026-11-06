// Export every defined data item in the DGROUP block (0x2410) together with
// its type, length, value and reference count.
// Args: outfile.csv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ExportDgroup extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress("2410:0000");
        Address end = currentProgram.getAddressFactory().getAddress("2410:88FF");
        PrintWriter w = new PrintWriter(new FileWriter(a[0]));
        w.println("offset,length,type,pointer,components,repr,refs");
        Listing lst = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        AddressSet set = new AddressSet(start, end);
        DataIterator it = lst.getData(set, true);
        int n = 0;
        while (it.hasNext()) {
            Data d = it.next();
            Address ad = d.getAddress();
            int off = (int) ad.subtract(start);
            DataType dt = d.getDataType();
            String repr = "";
            try { repr = d.getDefaultValueRepresentation(); } catch (Throwable t) { }
            if (repr == null) repr = "";
            repr = repr.replace("\r", "\\r").replace("\n", "\\n");
            if (repr.length() > 120) repr = repr.substring(0, 120) + "...";
            int refs = 0;
            ReferenceIterator ri = rm.getReferencesTo(ad);
            while (ri.hasNext()) { ri.next(); refs++; }
            w.println(String.format("%04X,%d,%s,%d,%d,%s,%d",
                    off, d.getLength(), dt == null ? "?" : dt.getName(),
                    dt instanceof Pointer ? 1 : 0, d.getNumComponents(),
                    repr, refs));
            n++;
        }
        w.close();
        println("DGROUP data items=" + n + " -> " + a[0]);
    }
}
