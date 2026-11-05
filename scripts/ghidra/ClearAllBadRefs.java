// Remove all references in the program whose target is not a real address.
// Args: [dryRun]
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ClearAllBadRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        boolean dry = getScriptArgs().length > 0 && getScriptArgs()[0].equals("dry");
        ReferenceManager rm = currentProgram.getReferenceManager();
        Address min = currentProgram.getMinAddress();
        Address max = currentProgram.getMaxAddress();
        List<Reference> bad = new ArrayList<Reference>();
        ReferenceIterator it = rm.getReferenceIterator(min);
        int total = 0;
        while (it.hasNext()) {
            Reference r = it.next();
            total++;
            Address to = r.getToAddress();
            boolean isBad = false;
            if (to == null) isBad = true;
            else if (to.equals(Address.NO_ADDRESS)) isBad = true;
            else {
                AddressSpace sp = to.getAddressSpace();
                if (sp == null || sp.getName().equalsIgnoreCase("NO ADDRESS")
                        || sp.getName().equalsIgnoreCase("BAD ADDRESS")) isBad = true;
            }
            if (isBad) bad.add(r);
        }
        println("refs=" + total + " bad=" + bad.size());
        for (Reference r : bad) println("  " + r.getFromAddress() + " " + r.getReferenceType() + " -> " + r.getToAddress());
        if (!dry) {
            int tx = currentProgram.startTransaction("clear all bad refs");
            try {
                for (Reference r : bad) rm.delete(r);
            } finally {
                currentProgram.endTransaction(tx, true);
            }
        }
    }
}
