// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsoc__Syms.h"


void Vsoc___024root__trace_chg_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsoc___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_chg_0\n"); );
    // Body
    Vsoc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc___024root*>(voidSelf);
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vsoc___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsoc___024root__trace_chg_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vsoc___024root__trace_chg_0_sub_0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_chg_0_sub_0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.soc__DOT__trace_en));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+1,(vlSelfRef.soc__DOT__core__DOT__halted));
        bufp->chgIData(oldp+2,(vlSelfRef.soc__DOT__core__DOT__pc),32);
        bufp->chgIData(oldp+3,(vlSelfRef.soc__DOT__core__DOT__dmem_addr),32);
        bufp->chgIData(oldp+4,(vlSelfRef.soc__DOT__mem
                               [(0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                >> 2U))]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.soc__DOT__core__DOT__dmem_wdata),32);
        bufp->chgIData(oldp+6,(vlSelfRef.soc__DOT__core__DOT__dmem_rdata),32);
        bufp->chgBit(oldp+7,((1U == (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                     >> 0x0000001cU))));
        bufp->chgSData(oldp+8,((0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                               >> 2U))),14);
        bufp->chgSData(oldp+9,((0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                               >> 2U))),14);
        Vsoc___024root__trace_chg_dtype____0(vlSelf, bufp, 10, vlSelfRef.soc__DOT__core__DOT__regs);
        bufp->chgCData(oldp+42,(vlSelfRef.__VdfgRegularize_hebeb780c_0_0),7);
        bufp->chgCData(oldp+43,(vlSelfRef.__VdfgRegularize_hebeb780c_0_6),5);
        bufp->chgCData(oldp+44,(vlSelfRef.__VdfgRegularize_hebeb780c_0_1),3);
        bufp->chgCData(oldp+45,(vlSelfRef.__VdfgRegularize_hebeb780c_0_18),5);
        bufp->chgCData(oldp+46,(vlSelfRef.__VdfgRegularize_hebeb780c_0_13),5);
        bufp->chgCData(oldp+47,(vlSelfRef.__VdfgRegularize_hebeb780c_0_3),7);
        bufp->chgIData(oldp+48,(vlSelfRef.soc__DOT__core__DOT__imm_i),32);
        bufp->chgIData(oldp+49,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                  << 0x0000000cU) | 
                                 (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                   << 5U) | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_6)))),32);
        bufp->chgIData(oldp+50,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                  << 0x0000000dU) | 
                                 ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7) 
                                    << 0x0000000cU) 
                                   | (0x00000800U & 
                                      (vlSelfRef.soc__DOT__mem
                                       [(0x00003fffU 
                                         & (vlSelfRef.soc__DOT__core__DOT__pc 
                                            >> 2U))] 
                                       << 4U))) | (
                                                   (0x000007e0U 
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
        bufp->chgIData(oldp+51,(vlSelfRef.soc__DOT__core__DOT__imm_u),32);
        bufp->chgIData(oldp+52,((((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                  << 0x00000014U) | 
                                 ((((0x000001feU & 
                                     (vlSelfRef.soc__DOT__mem
                                      [(0x00003fffU 
                                        & (vlSelfRef.soc__DOT__core__DOT__pc 
                                           >> 2U))] 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.soc__DOT__mem
                                             [(0x00003fffU 
                                               & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                  >> 2U))] 
                                             >> 0x00000014U))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.soc__DOT__mem
                                      [(0x00003fffU 
                                        & (vlSelfRef.soc__DOT__core__DOT__pc 
                                           >> 2U))] 
                                      >> 0x00000014U))))),32);
        bufp->chgIData(oldp+53,(vlSelfRef.soc__DOT__core__DOT__regs
                                [vlSelfRef.__VdfgRegularize_hebeb780c_0_18]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.soc__DOT__core__DOT__regs
                                [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]),32);
        bufp->chgBit(oldp+55,((0x33U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))));
        bufp->chgIData(oldp+56,(vlSelfRef.soc__DOT__core__DOT__alu_b),32);
        bufp->chgBit(oldp+57,(vlSelfRef.soc__DOT__core__DOT__alu_alt));
        bufp->chgIData(oldp+58,(vlSelfRef.soc__DOT__core__DOT__alu_out),32);
        bufp->chgBit(oldp+59,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
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
        bufp->chgCData(oldp+60,((3U & vlSelfRef.soc__DOT__core__DOT__dmem_addr)),2);
        bufp->chgBit(oldp+61,(vlSelfRef.soc__DOT__core__DOT__misaligned));
        bufp->chgIData(oldp+62,(vlSelfRef.soc__DOT__core__DOT__ld_shifted),32);
        bufp->chgIData(oldp+63,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
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
                                          << 8U) | 
                                         (0x000000ffU 
                                          & vlSelfRef.soc__DOT__core__DOT__ld_shifted))))),32);
        bufp->chgCData(oldp+64,((0x0000000fU & ((0U 
                                                 == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16))
                                                 ? 
                                                ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & vlSelfRef.soc__DOT__core__DOT__dmem_addr))
                                                 : 
                                                (((IData)(3U) 
                                                  << 
                                                  (3U 
                                                   & vlSelfRef.soc__DOT__core__DOT__dmem_addr)) 
                                                 | (- (IData)(
                                                              (1U 
                                                               != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16)))))))),4);
        bufp->chgIData(oldp+65,(((IData)(4U) + vlSelfRef.soc__DOT__core__DOT__pc)),32);
        bufp->chgIData(oldp+66,(vlSelfRef.soc__DOT__core__DOT__pc_next),32);
        bufp->chgIData(oldp+67,(vlSelfRef.soc__DOT__core__DOT__rd_val),32);
        bufp->chgBit(oldp+68,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_15)
                                ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10) 
                                   & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                                      & ((3U == (3U 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
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
        bufp->chgBit(oldp+69,(((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10) 
                               & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                                  & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_15)) 
                                     & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_21))))));
        bufp->chgBit(oldp+70,(vlSelfRef.soc__DOT__core__DOT__illegal));
    }
    bufp->chgBit(oldp+71,(vlSelfRef.clk));
    bufp->chgBit(oldp+72,(vlSelfRef.rst));
    bufp->chgBit(oldp+73,(vlSelfRef.done));
    bufp->chgIData(oldp+74,(vlSelfRef.exit_code),32);
    bufp->chgCData(oldp+75,(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb),4);
}

void Vsoc___024root__trace_chg_dtype____0(Vsoc___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_chg_dtype____0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vsoc___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root__trace_cleanup\n"); );
    // Body
    Vsoc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc___024root*>(voidSelf);
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
