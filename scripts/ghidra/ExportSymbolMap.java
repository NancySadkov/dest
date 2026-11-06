// Export symbols and their data types in a segment range.
// Args: seg outfile.csv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;

public class ExportSymbolMap extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        int seg = Integer.parseInt(a[0], 16);
        Address start = currentProgram.getAddressFactory().getAddress(
                String.format("%04X:0000", seg));
        Address end = currentProgram.getAddressFactory().getAddress(
                String.format("%04X:FFFF", seg));
        PrintWriter w = new PrintWriter(new FileWriter(a[1]));
        w.println("offset,name,type,length,repr");
        SymbolTable st = currentProgram.getSymbolTable();
        Listing lst = currentProgram.getListing();
        SymbolIterator it = st.getSymbolIterator();
        int n = 0;
        while (it.hasNext()) {
            Symbol s = it.next();
            Address ad = s.getAddress();
            if (ad == null || ad.compareTo(start) < 0 || ad.compareTo(end) > 0)
                continue;
            if (s.isExternal()) continue;
            Data d = lst.getDataAt(ad);
            String type = "";
            int len = 0;
            String repr = "";
            if (d != null) {
                type = d.getDataType() == null ? "?" : d.getDataType().getName();
                len = d.getLength();
                try { repr = d.getDefaultValueRepresentation(); } catch (Throwable t) { }
                if (repr == null) repr = "";
                repr = repr.replace("\r", "\\r").replace("\n", "\\n");
                if (repr.length() > 120) repr = repr.substring(0, 120) + "...";
            }
            int off = (int) ad.subtract(start);
            w.println(String.format("%04X,%s,%s,%d,%s", off,
                    s.getName(), type, len, repr));
            n++;
        }
        w.close();
        println("symbols in " + a[0] + " = " + n);
    }
}
