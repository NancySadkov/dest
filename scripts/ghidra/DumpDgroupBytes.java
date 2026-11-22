// Write the DGROUP image to a binary file. Args: seg start end outfile
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.*;
import java.io.*;

public class DumpDgroupBytes extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address start = currentProgram.getAddressFactory().getAddress(a[0] + ":" + a[1]);
        Address end = currentProgram.getAddressFactory().getAddress(a[0] + ":" + a[2]);
        Memory mem = currentProgram.getMemory();
        long n = end.subtract(start);
        byte[] buf = new byte[(int) n];
        int read = 0;
        for (int i = 0; i < n; i++) {
            try {
                buf[i] = mem.getByte(start.add(i));
            } catch (Exception e) {
                buf[i] = 0;
            }
            read++;
        }
        FileOutputStream f = new FileOutputStream(a[3]);
        f.write(buf);
        f.close();
        println("wrote " + read + " bytes to " + a[3]);
    }
}
