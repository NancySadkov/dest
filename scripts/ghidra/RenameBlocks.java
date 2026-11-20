// Rename memory blocks from a TSV of old<TAB>new.
// Args: tsv
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.MemoryBlock;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;

public class RenameBlocks extends GhidraScript {
    @Override
    public void run() throws Exception {
        int ok = 0, missing = 0;
        int tx = currentProgram.startTransaction("rename blocks");
        try {
            for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]),
                    StandardCharsets.UTF_8)) {
                if (line.trim().isEmpty() || line.startsWith("#")) continue;
                String[] f = line.split("\t");
                MemoryBlock b = null;
                for (MemoryBlock m : currentProgram.getMemory().getBlocks())
                    if (m.getName().equals(f[0])) { b = m; break; }
                if (b == null) { println("NOBLOCK " + f[0]); missing++; continue; }
                String old = b.getName();
                b.setName(f[1].trim());
                println("renamed " + old + " -> " + b.getName());
                ok++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("renamed=" + ok + " missing=" + missing);
    }
}
