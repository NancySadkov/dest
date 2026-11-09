// Name the BSS globals used by the recovered in-game code.
// Evidence is recorded as a plate comment at each symbol.
//@category DeSt
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

public class AnnotateBss extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[][] defs = {
            { "CA95", "GUnits",
              "Far pointer to the unit array allocated by init_buffers (0x2A30 bytes); stride 9." },
            { "CA99", "GUnitCount",
              "Number of valid unit slots; starts at 0xF8 and grows when units are added." },
            { "D1E6", "GLeaderCount",
              "Number of leaders/entities iterated by the turn update code." },
            { "D19F", "GMenuGfxOfs",
              "Offset of the menu/title RLE bitmap loaded by blitLoadRleGfx." },
            { "D1A1", "GMenuGfxSeg",
              "Segment of the menu/title RLE bitmap; paired with GMenuGfxOfs." },
            { "CA91", "GPopulationLo",
              "Low word of the 32-bit population counter printed by litoa10." },
            { "CA93", "GPopulationHi",
              "High word of the 32-bit population counter." },
            { "CB0D", "GUnitGrid",
              "Far pointer to the 0x4560-byte unit grid; rows are 0x78 bytes, entries are 2 bytes." },
            { "CB09", "GMapFlags",
              "Far pointer to the 0x4560-byte map flag array; rows are 0x128 bytes, entries are 2 bytes." },
            { "CA90", "GGameInProgress",
              "Non-zero while a game is loaded/running; the main menu uses it to choose the Begin Play item." }
        };
        int tx = currentProgram.startTransaction("annotate BSS");
        int n = 0;
        try {
            SymbolTable st = currentProgram.getSymbolTable();
            Listing lst = currentProgram.getListing();
            for (String[] d : defs) {
                Address ad = toAddr("2000:" + d[0]);
                Symbol s = st.getPrimarySymbol(ad);
                if (s == null) s = st.createLabel(ad, d[1], SourceType.USER_DEFINED);
                else s.setName(d[1], SourceType.USER_DEFINED);
                lst.setComment(ad, CommentType.PLATE, d[2]);
                n++;
            }
        } finally {
            currentProgram.endTransaction(tx, true);
        }
        println("annotated " + n + " BSS globals");
    }
}
