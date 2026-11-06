// List operands and references for an instruction. Args: address
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ListRefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] a = getScriptArgs();
        Address at = currentProgram.getAddressFactory().getAddress(a[0]);
        Instruction ins = currentProgram.getListing().getInstructionAt(at);
        if (ins == null) { println("no instruction at " + a[0]); return; }
        println("INSN " + ins.getAddress() + " " + ins);
        for (int op = 0; op < ins.getNumOperands(); op++) {
            println("  OP " + op + " type=" + ins.getOperandType(op)
                    + " objs=" + Arrays.toString(ins.getOpObjects(op)));
            for (Reference r : ins.getOperandReferences(op)) {
                println("    REF op=" + op + " to=" + r.getToAddress()
                        + " type=" + r.getReferenceType()
                        + " src=" + r.getSource());
            }
        }
        for (Reference r : ins.getReferencesFrom()) {
            println("  FROM ref to=" + r.getToAddress()
                    + " type=" + r.getReferenceType()
                    + " src=" + r.getSource()
                    + " op=" + r.getOperandIndex());
        }
    }
}
