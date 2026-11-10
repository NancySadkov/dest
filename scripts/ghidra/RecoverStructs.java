// Create the game unit/building structs and type the related globals.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class RecoverStructs extends GhidraScript {
    private DataType primitive(DataTypeManager dtm, String name) {
        return dtm.getDataType("/" + name);
    }

    private void setGlobal(Address ad, DataType type, String comment) throws Exception {
        clearListing(ad, ad.add(type.getLength() - 1));
        createData(ad, type);
        if (comment != null)
            currentProgram.getListing().setComment(ad, CommentType.PLATE, comment);
    }

    @Override
    public void run() throws Exception {
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        DataType u8 = dtm.getDataType("/byte");
        DataType s16 = dtm.getDataType("/short");
        if (u8 == null) u8 = ByteDataType.dataType;
        if (s16 == null) s16 = ShortDataType.dataType;

        int tx = currentProgram.startTransaction("recover unit/building structs");
        try {
            StructureDataType unitS = new StructureDataType("unit_t", 0, dtm);
            unitS.add(u8, 1, "bldType", "index into BuildingTypes, stride 0x27");
            unitS.add(u8, 1, "level", "level/count; compared < 8");
            unitS.add(u8, 1, "unitType", "unit/sprite type");
            unitS.add(u8, 1, "flags", "bit flags");
            unitS.add(s16, 2, "x", "map x");
            unitS.add(s16, 2, "y", "map y");
            unitS.add(u8, 1, "timer", "state timer");
            DataType unit = dtm.addDataType(unitS, DataTypeConflictHandler.REPLACE_HANDLER);

            DataType agnt = dtm.getDataType("/agnt_t");
            if (agnt == null) {
                Iterator<DataType> it = dtm.getAllDataTypes();
                while (it.hasNext()) {
                    DataType dt = it.next();
                    if (dt.getName().equals("agnt_t")) { agnt = dt; break; }
                }
            }
            StructureDataType entityS = new StructureDataType("entity_t", 0, dtm);
            if (agnt != null)
                entityS.add(agnt, agnt.getLength(), "base", "agnt_t prefix");
            else
                entityS.add(new ArrayDataType(u8, 0x34, 1), 0x34, "base", "agnt_t prefix");
            entityS.add(new ArrayDataType(u8, 0x37 - (agnt == null ? 0x34 : agnt.getLength()), 1),
                       0x37 - (agnt == null ? 0x34 : agnt.getLength()), "reserved", "");
            if (agnt instanceof Structure) {
                Structure as = (Structure) agnt;
                DataTypeComponent c0 = as.getComponentAt(0);
                if (c0 != null) { c0.setFieldName("x"); c0.setComment("map x"); }
                DataTypeComponent c2 = as.getComponentAt(2);
                if (c2 != null) { c2.setFieldName("y"); c2.setComment("map y"); }
            }
            DataType entity = dtm.addDataType(entityS, DataTypeConflictHandler.REPLACE_HANDLER);

            StructureDataType bldS = new StructureDataType("bld_inst_t", 0, dtm);
            bldS.add(s16, 2, "field0", "first 16-bit field");
            bldS.add(s16, 2, "field2", "second 16-bit field");
            bldS.add(new ArrayDataType(u8, 8, 1), 8, "data", "remaining record bytes");
            DataType bld = dtm.addDataType(bldS, DataTypeConflictHandler.REPLACE_HANDLER);

            DataType unitPtr = new PointerDataType(unit, 4, dtm);
            DataType entityPtr = new PointerDataType(entity, 4, dtm);
            DataType unitGrid = new ArrayDataType(
                    new ArrayDataType(s16, 60, 2), 148, 120);
            DataType mapFlags = new ArrayDataType(
                    new ArrayDataType(s16, 148, 2), 60, 296);
            DataType mapCells = new ArrayDataType(
                    new ArrayDataType(u8, 148, 1), 59, 148);
            unitGrid = dtm.addDataType(unitGrid, DataTypeConflictHandler.REPLACE_HANDLER);
            mapFlags = dtm.addDataType(mapFlags, DataTypeConflictHandler.REPLACE_HANDLER);
            mapCells = dtm.addDataType(mapCells, DataTypeConflictHandler.REPLACE_HANDLER);
            DataType unitGridPtr = new PointerDataType(unitGrid, 4, dtm);
            DataType mapFlagsPtr = new PointerDataType(mapFlags, 4, dtm);
            DataType mapCellsPtr = new PointerDataType(mapCells, 4, dtm);

            setGlobal(toAddr("2000:CA95"), unitPtr,
                    "far pointer to unit_t[]; stride 9, allocated 0x2A30 bytes");
            setGlobal(toAddr("2000:D18E"), entityPtr,
                    "far pointer to entity_t[]; stride 0x37");
            setGlobal(toAddr("2000:CB0D"), unitGridPtr,
                    "far pointer to uint16_t[148][60] unit grid");
            setGlobal(toAddr("2000:CB09"), mapFlagsPtr,
                    "far pointer to uint16_t[60][148] map flags");
            setGlobal(toAddr("2000:CB05"), mapCellsPtr,
                    "far pointer to uint8_t[59][148] map cells");

            Address baddr = toAddr("2410:4234");
            SymbolTable st = currentProgram.getSymbolTable();
            Symbol bsym = st.getPrimarySymbol(baddr);
            if (bsym == null)
                st.createLabel(baddr, "BldInstances", SourceType.USER_DEFINED);
            else
                bsym.setName("BldInstances", SourceType.USER_DEFINED);
            setGlobal(baddr, new ArrayDataType(bld, 75, 12),
                    "building instance records; 75 x 0xC bytes");
            Symbol bs = st.getPrimarySymbol(toAddr("2410:4228"));
            if (bs != null)
                bs.setName("s_build_clebath2_lbm_2410_4228", SourceType.USER_DEFINED);
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("created unit_t, entity_t, bld_inst_t and typed globals");
    }
}
