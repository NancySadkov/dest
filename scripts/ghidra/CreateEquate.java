// Create/apply an equate for a scalar value. Args: name hexvalue
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.*;
import ghidra.program.model.symbol.*;

public class CreateEquate extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        String name = a[0];
        long val = Long.parseLong(a[1], 16);
        int tx = currentProgram.startTransaction("create equate");
        int n = 0;
        try {
            EquateTable et = currentProgram.getEquateTable();
            Equate e = et.getEquate(name);
            if (e == null) e = et.createEquate(name, val);
            for (Instruction ins : currentProgram.getListing().getInstructions(true)) {
                for (int i = 0; i < ins.getNumOperands(); i++) {
                    for (Object o : ins.getOpObjects(i)) {
                        if (o instanceof Scalar && ((Scalar) o).getUnsignedValue() == val) {
                            e.addReference(ins.getAddress(), i);
                            n++;
                        }
                    }
                }
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("equate " + name + " refs " + n);
    }
}
