// Print bytes at an address. Args: address length
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;

public class PeekBytes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address addr = currentProgram.getAddressFactory().getAddress(a[0]);
        int len = Integer.parseInt(a[1], 16);
        Memory mem = currentProgram.getMemory();
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < len; i++) {
            Address x = addr.add(i);
            b.append(String.format("%02X ", mem.getByte(x) & 0xff));
            if ((i & 15) == 15) b.append("\n");
        }
        println(a[0] + ": " + b);
    }
}
