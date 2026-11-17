// Recover the UI/character-sheet structs and type the UI functions.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class RecoverUiStructs extends GhidraScript {
    private Address stackAddress(int off) {
        AddressSpace sp = currentProgram.getAddressFactory().getAddressSpace("stack");
        return sp == null ? null : sp.getAddress(off);
    }

    private DataType u8(DataTypeManager dtm) {
        DataType d = dtm.getDataType("/byte");
        return d == null ? ByteDataType.dataType : d;
    }

    private DataType u16(DataTypeManager dtm) {
        DataType d = dtm.getDataType("/short");
        return d == null ? ShortDataType.dataType : d;
    }

    private DataType u32(DataTypeManager dtm) {
        DataType d = dtm.getDataType("/long");
        return d == null ? LongDataType.dataType : d;
    }

    private void padTo(StructureDataType s, DataType u8, int target) {
        // A freshly constructed dynamic StructureDataType reports length 1
        // even though its first component starts at offset 0.  Treat an
        // empty structure as length 0 so padTo() lands on the exact offset.
        int len = s.getNumComponents() == 0 ? 0 : s.getLength();
        if (target > len)
            s.add(new ArrayDataType(u8, target - len, 1), target - len,
                  "pad_" + Integer.toHexString(len), "");
    }

    private void setParams(Function f, Object[][] params) throws Exception {
        if (f == null) return;
        for (int i = f.getParameters().length - 1; i >= 0; i--) f.removeParameter(i);
        f.setCustomVariableStorage(true);
        for (Object[] p : params) {
            String name = (String) p[0];
            DataType dt = (DataType) p[1];
            int off = (Integer) p[2];
            int len = dt.getLength();
            f.addParameter(new ParameterImpl(name, dt,
                    new VariableStorage(currentProgram, stackAddress(off), len),
                    currentProgram), SourceType.USER_DEFINED);
        }
    }

    private void setByteReturn(Function f, DataType u8) throws Exception {
        if (f == null) return;
        f.setReturn(u8, new VariableStorage(currentProgram,
                currentProgram.getRegister("AL")), SourceType.USER_DEFINED);
    }

    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType u8 = u8(dtm), u16 = u16(dtm), u32 = u32(dtm);
        DataType far = dtm.getDataType("/x86.h/far_t");
        if (far == null) far = dtm.getDataType("/far_t");
        DataType farPtr = new PointerDataType(far == null ? u8 : far, 4, dtm);
        DataType bytePtr = new PointerDataType(u8, 4, dtm);

        int tx = currentProgram.startTransaction("recover UI structs");
        try {
            StructureDataType s = new StructureDataType("char_sheet_t", 0, dtm);
            s.deleteAll();
            padTo(s, u8, 0x28);
            s.add(u8, 1, "statMask", "enabled-stat bit mask");
            s.add(new ArrayDataType(u8, 6, 1), 6, "stats", "six ability scores");
            s.add(u8, 1, "cls", "class index, -1 = none");
            s.add(u8, 1, "race", "race index");
            padTo(s, u8, 0x33);
            s.add(u8, 1, "alignment", "index into GAlignmentsNames");
            s.add(u8, 1, "gender", "gender index");
            s.add(far == null ? new ArrayDataType(u8, 4, 1) : far,
                  far == null ? 4 : far.getLength(), "name", "far pointer to character name");
            padTo(s, u8, 0x3d);
            s.add(u8, 1, "active", "non-zero if the record is in play");
            s.add(u8, 1, "classStr", "class string index");
            s.add(u8, 1, "excluded", "non-zero excludes record from population average");
            padTo(s, u8, 0x4d);
            s.add(u16, 2, "population", "town population");
            s.add(u16, 2, "foodProd", "food production");
            s.add(u8, 1, "charIndex", "index into the character table, -1 = none");
            padTo(s, u8, 0x54);
            s.add(u16, 2, "income", "income");
            s.add(u32, 4, "gold", "gold on hand");
            padTo(s, u8, 0x5b);
            s.add(u16, 2, "housing", "housing capacity");
            s.add(u8, 1, "flags5d", "UI/character flags");
            padTo(s, u8, 0x60);
            s.add(u32, 4, "foodStored", "food in storage");
            padTo(s, u8, 0x7e);
            s.add(u32, 4, "foodStorage", "food storage capacity");
            padTo(s, u8, 0x84);
            s.add(u8, 1, "popularity", "popularity percentage");
            padTo(s, u8, 0x86);
            s.add(u8, 1, "level", "level/type (<9 checks)");
            s.add(u16, 2, "rank", "rank (clamped to 10 for Fund Access)");
            s.add(u8, 1, "partySlot", "party slot index, 0xff = none");
            s.add(u32, 4, "vaultStorage", "vault storage");
            padTo(s, u8, 0xa0);
            s.add(u16, 2, "maxTrade", "maximum trade");
            s.add(u16, 2, "foodSold", "food sold");
            padTo(s, u8, 0xae);
            DataType sheet = dtm.addDataType(s, DataTypeConflictHandler.REPLACE_HANDLER);
            DataType sheetPtr = new PointerDataType(sheet, 4, dtm);
            println("char_sheet_t size " + sheet.getLength());

            StructureDataType m = new StructureDataType("ui_menu_t", 0, dtm);
            m.deleteAll();
            m.add(far == null ? new ArrayDataType(u8, 4, 1) : far, 4,
                  "title", "dialog title entry");
            m.add(new ArrayDataType(far == null ? u8 : far, 3, 4), 12,
                  "items", "selectable menu entries");
            DataType menu = dtm.addDataType(m, DataTypeConflictHandler.REPLACE_HANDLER);
            DataType menuPtr = new PointerDataType(menu, 4, dtm);
            println("ui_menu_t size " + menu.getLength());

            Function alloc = getFunctionAt(toAddr("474A:075A")); // stshAlloc, DX:AX return

            Function f;
            f = getFunctionAt(toAddr("4D05:056E"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:01D4"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:03A4"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            if (alloc != null)
                f.setReturn(alloc.getReturnType(), alloc.getReturn().getVariableStorage(),
                        SourceType.USER_DEFINED);
            f = getFunctionAt(toAddr("4D05:029D"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            setByteReturn(f, u8);
            f = getFunctionAt(toAddr("4D05:02F1"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            setByteReturn(f, u8);
            f = getFunctionAt(toAddr("4D05:0340"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            setByteReturn(f, u8);
            f = getFunctionAt(toAddr("4D05:11CB"));
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:0D7B"));
            setParams(f, new Object[][] {
                {"statIndex", u8, 4}, {"sheet", sheetPtr, 6}});
            setByteReturn(f, u8);
            f = getFunctionAt(toAddr("4D05:2D79"));
            setParams(f, new Object[][] {
                {"charIndex", u8, 4}, {"arg6", u16, 6}, {"sheet", sheetPtr, 8}});
            f = getFunctionAt(toAddr("4D05:0DBE")); // abilitiesDlg
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:1095")); // alignmentDlg
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:1146")); // uiPickGender
            setParams(f, new Object[][] {{"sheet", sheetPtr, 4}});
            f = getFunctionAt(toAddr("4D05:1296")); // chargen
            setParams(f, new Object[0][]);
            if (alloc != null)
                f.setReturn(sheetPtr, alloc.getReturn().getVariableStorage(),
                        SourceType.USER_DEFINED);
            f = getFunctionAt(toAddr("6018:0F29")); // uiInputText
            setParams(f, new Object[][] {
                {"entries", farPtr, 4}, {"count", u16, 8},
                {"hint", bytePtr, 0xa}, {"flags", u8, 0xe}});
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("typed UI functions with char_sheet_t *");
    }
}
