// Report how many string symbols are readable and whether a given text is in the map.
// Args: text...
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.Symbol;
import java.util.*;

public class StringMapProbe extends GhidraScript {
    @Override
    public void run() throws Exception {
        Map<String, Long> m = new HashMap<>();
        int syms = 0, read = 0, failed = 0;
        for (Symbol s : currentProgram.getSymbolTable().getAllSymbols(false)) {
            String n = s.getName();
            if (!n.startsWith("s_") && !n.startsWith("str_")) continue;
            syms++;
            StringBuilder sb = new StringBuilder();
            try {
                for (int i = 0; i < 200; i++) {
                    byte b = currentProgram.getMemory().getByte(s.getAddress().add(i));
                    if (b == 0) break;
                    sb.append((char) (b & 0xff));
                }
            } catch (Exception e) {
                failed++;
                continue;
            }
            if (sb.length() == 0) continue;
            read++;
            if (!m.containsKey(sb.toString())) m.put(sb.toString(), s.getAddress().getOffset());
        }
        println("s_symbols=" + syms + " readable=" + read + " failed=" + failed + " map=" + m.size());
        for (String a : getScriptArgs()) {
            Long v = m.get(a);
            println("lookup \"" + a + "\" -> " + (v == null ? "MISSING" : "0x" + Long.toHexString(v)));
        }
        int shown = 0;
        for (Map.Entry<String, Long> e : m.entrySet()) {
            if (shown++ >= 5) break;
            println("   sample \"" + e.getKey() + "\" @0x" + Long.toHexString(e.getValue()));
        }
    }
}
