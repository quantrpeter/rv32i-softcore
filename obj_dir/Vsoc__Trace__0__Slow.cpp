// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsoc__Syms.h"


VL_ATTR_COLD void Vsoc___024root__trace_init_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vsoc___024root__trace_init_sub__TOP__0(Vsoc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_init_sub__TOP__0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"exit_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"trap",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "soc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"MEM_WORDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"exit_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"trap",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"imem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"dmem_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"imem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"dmem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"dmem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"dmem_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"is_io",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"iword",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"dword",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"trace_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::BIT);
    VL_TRACE_PUSH_PREFIX(tracep, "core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"imem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"imem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"dmem_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"dmem_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"dmem_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"dmem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"trap",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"OP_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"OP_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"OP_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"OP_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+84,0,"OP_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"OP_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"OP_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+87,0,"OP_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+88,0,"OP_FENCE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"OP_SYSTEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);

    Vsoc___024root__trace_init_dtype____0(vlSelf, tracep, "regs", 0, c+10, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"halted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"insn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"imm_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"imm_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"imm_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"imm_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"imm_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"rs1_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"rs2_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"is_reg_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"alu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"alu_alt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"alu_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"take_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+60,0,"byte_off",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"misaligned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"ld_shifted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"load_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+64,0,"store_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+66,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+67,0,"rd_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+68,0,"rd_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+69,0,"store_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+70,0,"illegal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vsoc___024root__trace_init_dtype_sub____0(Vsoc___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vsoc___024root__trace_init_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_init_dtype____0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vsoc___024root__trace_init_dtype_sub____0(Vsoc___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_init_dtype_sub____0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 31);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vsoc___024root__trace_init_top(Vsoc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_init_top\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsoc___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsoc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsoc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsoc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsoc___024root__trace_register(Vsoc___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_register\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vsoc___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vsoc___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vsoc___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vsoc___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsoc___024root__trace_const_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_const_0\n"); );
    // Body
    Vsoc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc___024root*>(voidSelf);
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vsoc___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc___024root__trace_const_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_const_0_sub_0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+76,(0x00004000U),32);
    bufp->fullIData(oldp+77,(0x0000000eU),32);
    bufp->fullIData(oldp+78,(0U),32);
    bufp->fullCData(oldp+79,(0x37U),7);
    bufp->fullCData(oldp+80,(0x17U),7);
    bufp->fullCData(oldp+81,(0x6fU),7);
    bufp->fullCData(oldp+82,(0x67U),7);
    bufp->fullCData(oldp+83,(0x63U),7);
    bufp->fullCData(oldp+84,(3U),7);
    bufp->fullCData(oldp+85,(0x23U),7);
    bufp->fullCData(oldp+86,(0x13U),7);
    bufp->fullCData(oldp+87,(0x33U),7);
    bufp->fullCData(oldp+88,(0x0fU),7);
    bufp->fullCData(oldp+89,(0x73U),7);
}

VL_ATTR_COLD void Vsoc___024root__trace_full_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsoc___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_full_0\n"); );
    // Body
    Vsoc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc___024root*>(voidSelf);
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vsoc___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsoc___024root__trace_full_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

VL_ATTR_COLD void Vsoc___024root__trace_full_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_full_0_sub_0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.soc__DOT__trace_en));
    bufp->fullBit(oldp+1,(vlSelfRef.soc__DOT__core__DOT__halted));
    bufp->fullIData(oldp+2,(vlSelfRef.soc__DOT__core__DOT__pc),32);
    bufp->fullIData(oldp+3,(vlSelfRef.soc__DOT__core__DOT__dmem_addr),32);
    bufp->fullIData(oldp+4,(vlSelfRef.soc__DOT__mem
                            [(0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                             >> 2U))]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.soc__DOT__core__DOT__dmem_wdata),32);
    bufp->fullIData(oldp+6,(vlSelfRef.soc__DOT__core__DOT__dmem_rdata),32);
    bufp->fullBit(oldp+7,((1U == (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                  >> 0x0000001cU))));
    bufp->fullSData(oldp+8,((0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                            >> 2U))),14);
    bufp->fullSData(oldp+9,((0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                            >> 2U))),14);
    Vsoc___024root__trace_full_dtype____0(vlSelf, bufp, 10, vlSelfRef.soc__DOT__core__DOT__regs);
    bufp->fullCData(oldp+42,(vlSelfRef.__VdfgRegularize_hebeb780c_0_0),7);
    bufp->fullCData(oldp+43,(vlSelfRef.__VdfgRegularize_hebeb780c_0_6),5);
    bufp->fullCData(oldp+44,(vlSelfRef.__VdfgRegularize_hebeb780c_0_1),3);
    bufp->fullCData(oldp+45,(vlSelfRef.__VdfgRegularize_hebeb780c_0_18),5);
    bufp->fullCData(oldp+46,(vlSelfRef.__VdfgRegularize_hebeb780c_0_13),5);
    bufp->fullCData(oldp+47,(vlSelfRef.__VdfgRegularize_hebeb780c_0_3),7);
    bufp->fullIData(oldp+48,(vlSelfRef.soc__DOT__core__DOT__imm_i),32);
    bufp->fullIData(oldp+49,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                               << 0x0000000cU) | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                   << 5U) 
                                                  | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_6)))),32);
    bufp->fullIData(oldp+50,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                               << 0x0000000dU) | ((
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7) 
                                                    << 0x0000000cU) 
                                                   | (0x00000800U 
                                                      & (vlSelfRef.soc__DOT__mem
                                                         [
                                                         (0x00003fffU 
                                                          & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                             >> 2U))] 
                                                         << 4U))) 
                                                  | ((0x000007e0U 
                                                      & (vlSelfRef.soc__DOT__mem
                                                         [
                                                         (0x00003fffU 
                                                          & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                             >> 2U))] 
                                                         >> 0x00000014U)) 
                                                     | (0x0000001eU 
                                                        & (vlSelfRef.soc__DOT__mem
                                                           [
                                                           (0x00003fffU 
                                                            & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                               >> 2U))] 
                                                           >> 7U)))))),32);
    bufp->fullIData(oldp+51,(vlSelfRef.soc__DOT__core__DOT__imm_u),32);
    bufp->fullIData(oldp+52,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                               << 0x00000014U) | ((
                                                   ((0x000001feU 
                                                     & (vlSelfRef.soc__DOT__mem
                                                        [
                                                        (0x00003fffU 
                                                         & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                            >> 2U))] 
                                                        >> 0x0000000bU)) 
                                                    | (1U 
                                                       & (vlSelfRef.soc__DOT__mem
                                                          [
                                                          (0x00003fffU 
                                                           & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                              >> 2U))] 
                                                          >> 0x00000014U))) 
                                                   << 0x0000000bU) 
                                                  | (0x000007feU 
                                                     & (vlSelfRef.soc__DOT__mem
                                                        [
                                                        (0x00003fffU 
                                                         & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                            >> 2U))] 
                                                        >> 0x00000014U))))),32);
    bufp->fullIData(oldp+53,(vlSelfRef.soc__DOT__core__DOT__regs
                             [vlSelfRef.__VdfgRegularize_hebeb780c_0_18]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.soc__DOT__core__DOT__regs
                             [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]),32);
    bufp->fullBit(oldp+55,((0x33U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
    bufp->fullIData(oldp+56,(vlSelfRef.soc__DOT__core__DOT__alu_b),32);
    bufp->fullBit(oldp+57,(vlSelfRef.soc__DOT__core__DOT__alu_alt));
    bufp->fullIData(oldp+58,(vlSelfRef.soc__DOT__core__DOT__alu_out),32);
    bufp->fullBit(oldp+59,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
                             ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                 ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                     ? (vlSelfRef.soc__DOT__core__DOT__regs
                                        [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                        >= vlSelfRef.soc__DOT__core__DOT__regs
                                        [vlSelfRef.__VdfgRegularize_hebeb780c_0_13])
                                     : (vlSelfRef.soc__DOT__core__DOT__regs
                                        [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                        < vlSelfRef.soc__DOT__core__DOT__regs
                                        [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]))
                                 : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                     ? VL_GTES_III(32, vlSelfRef.soc__DOT__core__DOT__regs
                                                   [vlSelfRef.__VdfgRegularize_hebeb780c_0_18], vlSelfRef.soc__DOT__core__DOT__regs
                                                   [vlSelfRef.__VdfgRegularize_hebeb780c_0_13])
                                     : VL_LTS_III(32, vlSelfRef.soc__DOT__core__DOT__regs
                                                  [vlSelfRef.__VdfgRegularize_hebeb780c_0_18], vlSelfRef.soc__DOT__core__DOT__regs
                                                  [vlSelfRef.__VdfgRegularize_hebeb780c_0_13])))
                             : ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)) 
                                & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                    ? (vlSelfRef.soc__DOT__core__DOT__regs
                                       [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                       != vlSelfRef.soc__DOT__core__DOT__regs
                                       [vlSelfRef.__VdfgRegularize_hebeb780c_0_13])
                                    : (vlSelfRef.soc__DOT__core__DOT__regs
                                       [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                       == vlSelfRef.soc__DOT__core__DOT__regs
                                       [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]))))));
    bufp->fullCData(oldp+60,((3U & vlSelfRef.soc__DOT__core__DOT__dmem_addr)),2);
    bufp->fullBit(oldp+61,(vlSelfRef.soc__DOT__core__DOT__misaligned));
    bufp->fullIData(oldp+62,(vlSelfRef.soc__DOT__core__DOT__ld_shifted),32);
    bufp->fullIData(oldp+63,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
                               ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                   ? vlSelfRef.soc__DOT__core__DOT__dmem_rdata
                                   : ((0x0000ff00U 
                                       & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                          & ((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
                                             << 8U))) 
                                      | (0x000000ffU 
                                         & vlSelfRef.soc__DOT__core__DOT__ld_shifted)))
                               : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                   ? vlSelfRef.soc__DOT__core__DOT__dmem_rdata
                                   : ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                         ? ((0x00ffff00U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                               >> 0x0000000fU)))) 
                                                << 8U)) 
                                            | (0x000000ffU 
                                               & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                  >> 8U)))
                                         : (- (IData)(
                                                      (1U 
                                                       & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                          >> 7U))))) 
                                       << 8U) | (0x000000ffU 
                                                 & vlSelfRef.soc__DOT__core__DOT__ld_shifted))))),32);
    bufp->fullCData(oldp+64,((0x0000000fU & ((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16))
                                              ? ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & vlSelfRef.soc__DOT__core__DOT__dmem_addr))
                                              : (((IData)(3U) 
                                                  << 
                                                  (3U 
                                                   & vlSelfRef.soc__DOT__core__DOT__dmem_addr)) 
                                                 | (- (IData)(
                                                              (1U 
                                                               != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16)))))))),4);
    bufp->fullIData(oldp+65,(((IData)(4U) + vlSelfRef.soc__DOT__core__DOT__pc)),32);
    bufp->fullIData(oldp+66,(vlSelfRef.soc__DOT__core__DOT__pc_next),32);
    bufp->fullIData(oldp+67,(vlSelfRef.soc__DOT__core__DOT__rd_val),32);
    bufp->fullBit(oldp+68,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_15)
                             ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10) 
                                & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                                   & ((3U == (3U & 
                                              (vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 1U))) 
                                      & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8))))
                             : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10)
                                 ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4) 
                                    & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_14))
                                 : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                                     ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_14)
                                     : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_21))))));
    bufp->fullBit(oldp+69,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10) 
                            & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                               & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_15)) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_21))))));
    bufp->fullBit(oldp+70,(vlSelfRef.soc__DOT__core__DOT__illegal));
    bufp->fullBit(oldp+71,(vlSelfRef.clk));
    bufp->fullBit(oldp+72,(vlSelfRef.rst));
    bufp->fullBit(oldp+73,(vlSelfRef.done));
    bufp->fullIData(oldp+74,(vlSelfRef.exit_code),32);
    bufp->fullCData(oldp+75,(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb),4);
}

VL_ATTR_COLD void Vsoc___024root__trace_full_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_full_dtype____0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->fullIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->fullIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->fullIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->fullIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->fullIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->fullIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->fullIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->fullIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->fullIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->fullIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->fullIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->fullIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->fullIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->fullIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->fullIData(oldp+31,(__VdtypeVar[31]),32);
}
