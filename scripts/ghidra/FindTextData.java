// Print auto-named data symbols whose bytes look like ASCII text.
//
// A data blob that holds a string but was typed `undefined`/`byte` is missed by the
// string pass (which only looked at `_string` labels).  This finds those.
//
// Args: none
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;

public class FindTextData extends GhidraScript {
    static boolean auto(String n) {
        return n.matches("(data|byte|word|dword)_[0-9A-Fa-f]{4}_.*")
            || n.matches("data_DS_.*") || n.matches("data_[0-9A-Fa-f]{4}_.*");
    }

    @Override
    public void run() throws Exception {
        Memory mem = currentProgram.getMemory();
        int found = 0;
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(true)) {
            if (s.getSymbolType() != SymbolType.LABEL) continue;
            String n = s.getName();
            if (!auto(n)) continue;
            Address ad = s.getAddress();
            byte[] buf = new byte[24];
            try { mem.getBytes(ad, buf); } catch (Throwable t) { continue; }
            StringBuilder sb = new StringBuilder();
            int printable = 0;
            for (int i = 0; i < buf.length; i++) {
                int c = buf[i] & 0xff;
                if (c == 0) break;
                if (c >= 32 && c < 127) { printable++; sb.append((char) c); }
                else { sb.append('.'); }
            }
            if (printable >= 10 && sb.indexOf(" ") >= 0) {
                println(ad + "\t" + n + "\t" + sb.toString());
                found++;
            }
        }
        println("text_like=" + found);
    }
}
