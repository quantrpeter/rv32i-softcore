// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc.h for the primary calling header

#include "Vsoc__pch.h"

VL_ATTR_COLD void Vsoc___024root___eval_static(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_static\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.soc__DOT__unnamedblk1__DOT__prog = ""s;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vsoc___024root___eval_initial(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_initial\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        IData/*31:0*/ __Vinline_0__eval_initial__TOP_soc__DOT____VlemExpr_0;
        IData/*31:0*/ __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
        __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
        __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00004000U, __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)) {
            vlSelfRef.soc__DOT__mem[(0x00003fffU & __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)] = 0U;
            __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i 
                = ((IData)(1U) + __Vinline_0__eval_initial__TOP_soc__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i);
        }
        __Vinline_0__eval_initial__TOP_soc__DOT____VlemExpr_0 
            = VL_VALUEPLUSARGS_INN(64, "prog=%s"s, 
                                   vlSelfRef.soc__DOT__unnamedblk1__DOT__prog);
        if (VL_LIKELY((__Vinline_0__eval_initial__TOP_soc__DOT____VlemExpr_0))) {
            VL_READMEM_N(true, 32, 16384, 0, vlSelfRef.soc__DOT__unnamedblk1__DOT__prog
                         ,  &(vlSelfRef.soc__DOT__mem)
                         , 0, ~0ULL);
        } else {
            VL_WRITEF_NX("[%0t] %%Fatal: soc.sv:42: Assertion failed in %m: usage: +prog=<file.hex>\n",3, 'M',vlSymsp->name(),"soc.unnamedblk1", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1));
            VL_STOP_MT("rtl/soc.sv", 42, "", false);
        }
        vlSelfRef.soc__DOT__trace_en = (0U != VL_TESTPLUSARGS_I("trace"s));
    }
    {
        // Inlined CFunc: __Vm_traceActivitySetAll
        vlSelfRef.__Vm_traceActivity[0U] = 1U;
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsoc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vsoc___024root___stl_sequent__TOP__0(Vsoc___024root* vlSelf);

VL_ATTR_COLD bool Vsoc___024root___eval_stl(Vsoc___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_stl\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vsoc___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vsoc___024root___stl_sequent__TOP__0(vlSelf);
                {
                    // Inlined CFunc: __Vm_traceActivitySetAll
                    vlSelfRef.__Vm_traceActivity[0U] = 1U;
                    vlSelfRef.__Vm_traceActivity[1U] = 1U;
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__stl(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__stl\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsoc___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__ico(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__ico\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsoc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__act(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__act\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsoc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__nba(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__nba\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsoc___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__obs(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__obs\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__react(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_dump_triggers__react\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsoc___024root___eval_final(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_final\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsoc___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vsoc___024root___stl_sequent__TOP__0(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___stl_sequent__TOP__0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_9;
    __VdfgRegularize_hebeb780c_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_11;
    __VdfgRegularize_hebeb780c_0_11 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_12;
    __VdfgRegularize_hebeb780c_0_12 = 0;
    // Body
    vlSelfRef.trap = vlSelfRef.soc__DOT__core__DOT__halted;
    vlSelfRef.soc__DOT__core__DOT__imm_u = (0xfffff000U 
                                            & vlSelfRef.soc__DOT__mem
                                            [(0x00003fffU 
                                              & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                 >> 2U))]);
    __VdfgRegularize_hebeb780c_0_11 = (1U & (vlSelfRef.soc__DOT__mem
                                             [(0x00003fffU 
                                               & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                  >> 2U))] 
                                             >> 1U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_8 = (1U 
                                                & vlSelfRef.soc__DOT__mem
                                                [(0x00003fffU 
                                                  & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                     >> 2U))]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_4 = (1U 
                                                & (vlSelfRef.soc__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                       >> 2U))] 
                                                   >> 4U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_10 = (1U 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 5U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_15 = (1U 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 6U));
    __VdfgRegularize_hebeb780c_0_9 = (1U & (vlSelfRef.soc__DOT__mem
                                            [(0x00003fffU 
                                              & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                 >> 2U))] 
                                            >> 2U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_16 = (3U 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x0000000cU));
    __VdfgRegularize_hebeb780c_0_12 = (1U & (vlSelfRef.soc__DOT__mem
                                             [(0x00003fffU 
                                               & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                  >> 2U))] 
                                             >> 3U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_1 = (7U 
                                                & (vlSelfRef.soc__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x0000000cU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = (1U 
                                                & (vlSelfRef.soc__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x0000000cU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_5 = (1U 
                                                & (vlSelfRef.soc__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                       >> 2U))] 
                                                   >> 0x0000000dU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_17 = (1U 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x0000000eU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_6 = (0x0000001fU 
                                                & (vlSelfRef.soc__DOT__mem
                                                   [
                                                   (0x00003fffU 
                                                    & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                       >> 2U))] 
                                                   >> 7U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_3 = (vlSelfRef.soc__DOT__mem
                                                [(0x00003fffU 
                                                  & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                     >> 2U))] 
                                                >> 0x00000019U);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_18 = (0x0000001fU 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x0000000fU));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_13 = (0x0000001fU 
                                                 & (vlSelfRef.soc__DOT__mem
                                                    [
                                                    (0x00003fffU 
                                                     & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                        >> 2U))] 
                                                    >> 0x00000014U));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = (0x0000007fU 
                                                & vlSelfRef.soc__DOT__mem
                                                [(0x00003fffU 
                                                  & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                     >> 2U))]);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_7 = (vlSelfRef.soc__DOT__mem
                                                [(0x00003fffU 
                                                  & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                     >> 2U))] 
                                                >> 0x0000001fU);
    vlSelfRef.__VdfgRegularize_hebeb780c_0_14 = ((~ (IData)(__VdfgRegularize_hebeb780c_0_12)) 
                                                 & (3U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.soc__DOT__mem
                                                     [
                                                     (0x00003fffU 
                                                      & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                         >> 2U))])));
    vlSelfRef.soc__DOT__core__DOT__alu_alt = ((vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x0000001eU) 
                                              & ((0x33U 
                                                  == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)) 
                                                 | (5U 
                                                    == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))));
    vlSelfRef.soc__DOT__core__DOT__imm_i = (((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                             << 0x0000000cU) 
                                            | (vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x00000014U));
    vlSelfRef.soc__DOT__core__DOT__dmem_addr = (vlSelfRef.soc__DOT__core__DOT__regs
                                                [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                + (
                                                   ((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                                    << 0x0000000cU) 
                                                   | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                       << 5U) 
                                                      | ((0x23U 
                                                          == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                                          ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_6)
                                                          : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_13)))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_21 = ((~ (IData)(__VdfgRegularize_hebeb780c_0_9)) 
                                                 & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_14));
    vlSelfRef.soc__DOT__core__DOT__alu_b = ((0x33U 
                                             == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))
                                             ? vlSelfRef.soc__DOT__core__DOT__regs
                                            [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]
                                             : vlSelfRef.soc__DOT__core__DOT__imm_i);
    vlSelfRef.soc__DOT__core__DOT__dmem_wdata = (vlSelfRef.soc__DOT__core__DOT__regs
                                                 [vlSelfRef.__VdfgRegularize_hebeb780c_0_13] 
                                                 << 
                                                 (0x00000018U 
                                                  & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                     << 3U)));
    vlSelfRef.soc__DOT__core__DOT__misaligned = (((1U 
                                                   == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16)) 
                                                  & vlSelfRef.soc__DOT__core__DOT__dmem_addr) 
                                                 | ((2U 
                                                     == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16)) 
                                                    & (0U 
                                                       != 
                                                       (3U 
                                                        & vlSelfRef.soc__DOT__core__DOT__dmem_addr))));
    vlSelfRef.soc__DOT__core__DOT__dmem_rdata = ((1U 
                                                  == 
                                                  (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                   >> 0x0000001cU))
                                                  ? 0U
                                                  : vlSelfRef.soc__DOT__mem
                                                 [(0x00003fffU 
                                                   & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                      >> 2U))]);
    vlSelfRef.soc__DOT__core__DOT__alu_out = ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
                                               ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                                   ? 
                                                  ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                                    ? 
                                                   (vlSelfRef.soc__DOT__core__DOT__regs
                                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                    & vlSelfRef.soc__DOT__core__DOT__alu_b)
                                                    : 
                                                   (vlSelfRef.soc__DOT__core__DOT__regs
                                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                    | vlSelfRef.soc__DOT__core__DOT__alu_b))
                                                   : 
                                                  ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                                    ? 
                                                   ((IData)(vlSelfRef.soc__DOT__core__DOT__alu_alt)
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelfRef.soc__DOT__core__DOT__regs
                                                                   [vlSelfRef.__VdfgRegularize_hebeb780c_0_18], 
                                                                   (0x0000001fU 
                                                                    & vlSelfRef.soc__DOT__core__DOT__alu_b))
                                                     : 
                                                    (vlSelfRef.soc__DOT__core__DOT__regs
                                                     [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                     >> 
                                                     (0x0000001fU 
                                                      & vlSelfRef.soc__DOT__core__DOT__alu_b)))
                                                    : 
                                                   (vlSelfRef.soc__DOT__core__DOT__regs
                                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                    ^ vlSelfRef.soc__DOT__core__DOT__alu_b)))
                                               : ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                                   ? 
                                                  ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                                    ? 
                                                   (vlSelfRef.soc__DOT__core__DOT__regs
                                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                    < vlSelfRef.soc__DOT__core__DOT__alu_b)
                                                    : 
                                                   VL_LTS_III(32, vlSelfRef.soc__DOT__core__DOT__regs
                                                              [vlSelfRef.__VdfgRegularize_hebeb780c_0_18], vlSelfRef.soc__DOT__core__DOT__alu_b))
                                                   : 
                                                  ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                                    ? 
                                                   (vlSelfRef.soc__DOT__core__DOT__regs
                                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                    << 
                                                    (0x0000001fU 
                                                     & vlSelfRef.soc__DOT__core__DOT__alu_b))
                                                    : 
                                                   ((IData)(vlSelfRef.soc__DOT__core__DOT__alu_alt)
                                                     ? 
                                                    (vlSelfRef.soc__DOT__core__DOT__regs
                                                     [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                     - vlSelfRef.soc__DOT__core__DOT__alu_b)
                                                     : 
                                                    (vlSelfRef.soc__DOT__core__DOT__regs
                                                     [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                                     + vlSelfRef.soc__DOT__core__DOT__alu_b)))));
    vlSelfRef.soc__DOT__core__DOT__pc_next = ((IData)(4U) 
                                              + vlSelfRef.soc__DOT__core__DOT__pc);
    vlSelfRef.soc__DOT__core__DOT__illegal = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
        if ((0x00000020U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
            } else if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                            vlSelfRef.soc__DOT__core__DOT__pc_next 
                                = (vlSelfRef.soc__DOT__core__DOT__pc 
                                   + (((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                       << 0x00000014U) 
                                      | ((((0x000001feU 
                                            & (vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x0000000bU)) 
                                           | (1U & 
                                              (vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x00000014U))) 
                                          << 0x0000000bU) 
                                         | (0x000007feU 
                                            & (vlSelfRef.soc__DOT__mem
                                               [(0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                    >> 2U))] 
                                               >> 0x00000014U)))));
                        } else {
                            vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                        }
                    } else {
                        vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                    }
                } else {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                        vlSelfRef.soc__DOT__core__DOT__pc_next 
                            = (0xfffffffeU & (vlSelfRef.soc__DOT__core__DOT__regs
                                              [vlSelfRef.__VdfgRegularize_hebeb780c_0_18] 
                                              + vlSelfRef.soc__DOT__core__DOT__imm_i));
                        vlSelfRef.soc__DOT__core__DOT__illegal 
                            = (0U != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1));
                    } else {
                        vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                    }
                } else {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((1U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
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
                                    [vlSelfRef.__VdfgRegularize_hebeb780c_0_13]))))) {
                        vlSelfRef.soc__DOT__core__DOT__pc_next 
                            = (vlSelfRef.soc__DOT__core__DOT__pc 
                               + (((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7))) 
                                   << 0x0000000dU) 
                                  | ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_7) 
                                       << 0x0000000cU) 
                                      | (0x00000800U 
                                         & (vlSelfRef.soc__DOT__mem
                                            [(0x00003fffU 
                                              & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                 >> 2U))] 
                                            << 4U))) 
                                     | ((0x000007e0U 
                                         & (vlSelfRef.soc__DOT__mem
                                            [(0x00003fffU 
                                              & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                 >> 2U))] 
                                            >> 0x00000014U)) 
                                        | (0x0000001eU 
                                           & (vlSelfRef.soc__DOT__mem
                                              [(0x00003fffU 
                                                & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                   >> 2U))] 
                                              >> 7U))))));
                    }
                    vlSelfRef.soc__DOT__core__DOT__illegal 
                        = (1U == (3U & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1) 
                                        >> 1U)));
                } else {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else {
                vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
            }
        } else {
            vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
        if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
            } else if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                    if ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)))) {
                        vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                    }
                } else {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else {
                vlSelfRef.soc__DOT__core__DOT__illegal 
                    = ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                 >> 1U))) || ((1U & 
                                               (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
                                              || ((0U 
                                                   != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3)) 
                                                  & (~ 
                                                     ((0x20U 
                                                       == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3)) 
                                                      & ((0U 
                                                          == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
                                                         | (5U 
                                                            == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1))))))));
            }
        } else {
            vlSelfRef.soc__DOT__core__DOT__illegal 
                = ((1U & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                          >> 3U)) || ((1U & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                             >> 2U)) 
                                      || ((1U & (~ 
                                                 ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                                  >> 1U))) 
                                          || ((1U & 
                                               (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
                                              || (IData)(
                                                         ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1) 
                                                            >> 2U) 
                                                           | (IData)(vlSelfRef.soc__DOT__core__DOT__misaligned)) 
                                                          | (3U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1)))))))));
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
        if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
        } else if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)))) {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else {
                vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
            }
        } else {
            vlSelfRef.soc__DOT__core__DOT__illegal 
                = ((1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                             >> 1U))) || ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
                                          || (((1U 
                                                == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
                                               & (0U 
                                                  != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))) 
                                              | (((5U 
                                                   == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
                                                  & (0U 
                                                     != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))) 
                                                 & (0x20U 
                                                    != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3))))));
        }
    } else if ((8U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
        if ((4U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
            if ((2U & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                if ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0)))) {
                    vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
                }
            } else {
                vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
            }
        } else {
            vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
        }
    } else {
        vlSelfRef.soc__DOT__core__DOT__illegal = ((1U 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                                      >> 2U)) 
                                                  || ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0) 
                                                           >> 1U))) 
                                                      || ((1U 
                                                           & (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) 
                                                          || (((3U 
                                                                == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1)) 
                                                               | (3U 
                                                                  == 
                                                                  (3U 
                                                                   & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_1) 
                                                                      >> 1U)))) 
                                                              | (IData)(vlSelfRef.soc__DOT__core__DOT__misaligned)))));
    }
    if ((0U != (3U & vlSelfRef.soc__DOT__core__DOT__pc_next))) {
        vlSelfRef.soc__DOT__core__DOT__illegal = 1U;
    }
    vlSelfRef.soc__DOT__core__DOT__ld_shifted = (vlSelfRef.soc__DOT__core__DOT__dmem_rdata 
                                                 >> 
                                                 (0x00000018U 
                                                  & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                     << 3U)));
    if (vlSelfRef.__VdfgRegularize_hebeb780c_0_15) {
        if (vlSelfRef.__VdfgRegularize_hebeb780c_0_10) {
            vlSelfRef.soc__DOT__core__DOT__rd_we = 
                ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                 & ((3U == (3U & (vlSelfRef.soc__DOT__mem
                                  [(0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                                   >> 2U))] 
                                  >> 1U))) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)));
            vlSelfRef.soc__DOT__core__DOT__rd_val = 
                ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)
                  ? vlSelfRef.soc__DOT__core__DOT__alu_out
                  : ((IData)(__VdfgRegularize_hebeb780c_0_9)
                      ? ((IData)(__VdfgRegularize_hebeb780c_0_11)
                          ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)
                              ? ((IData)(4U) + vlSelfRef.soc__DOT__core__DOT__pc)
                              : vlSelfRef.soc__DOT__core__DOT__alu_out)
                          : vlSelfRef.soc__DOT__core__DOT__alu_out)
                      : vlSelfRef.soc__DOT__core__DOT__alu_out));
        } else {
            vlSelfRef.soc__DOT__core__DOT__rd_we = 0U;
            vlSelfRef.soc__DOT__core__DOT__rd_val = vlSelfRef.soc__DOT__core__DOT__alu_out;
        }
    } else if (vlSelfRef.__VdfgRegularize_hebeb780c_0_10) {
        if (vlSelfRef.__VdfgRegularize_hebeb780c_0_4) {
            vlSelfRef.soc__DOT__core__DOT__rd_we = vlSelfRef.__VdfgRegularize_hebeb780c_0_14;
            vlSelfRef.soc__DOT__core__DOT__rd_val = 
                ((IData)(__VdfgRegularize_hebeb780c_0_12)
                  ? vlSelfRef.soc__DOT__core__DOT__alu_out
                  : ((IData)(__VdfgRegularize_hebeb780c_0_9)
                      ? ((IData)(__VdfgRegularize_hebeb780c_0_11)
                          ? ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)
                              ? vlSelfRef.soc__DOT__core__DOT__imm_u
                              : vlSelfRef.soc__DOT__core__DOT__alu_out)
                          : vlSelfRef.soc__DOT__core__DOT__alu_out)
                      : vlSelfRef.soc__DOT__core__DOT__alu_out));
        } else {
            vlSelfRef.soc__DOT__core__DOT__rd_we = 0U;
            vlSelfRef.soc__DOT__core__DOT__rd_val = vlSelfRef.soc__DOT__core__DOT__alu_out;
        }
    } else if (vlSelfRef.__VdfgRegularize_hebeb780c_0_4) {
        vlSelfRef.soc__DOT__core__DOT__rd_we = vlSelfRef.__VdfgRegularize_hebeb780c_0_14;
        vlSelfRef.soc__DOT__core__DOT__rd_val = ((IData)(__VdfgRegularize_hebeb780c_0_12)
                                                  ? vlSelfRef.soc__DOT__core__DOT__alu_out
                                                  : 
                                                 ((IData)(__VdfgRegularize_hebeb780c_0_9)
                                                   ? 
                                                  ((IData)(__VdfgRegularize_hebeb780c_0_11)
                                                    ? 
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)
                                                     ? 
                                                    (vlSelfRef.soc__DOT__core__DOT__pc 
                                                     + vlSelfRef.soc__DOT__core__DOT__imm_u)
                                                     : vlSelfRef.soc__DOT__core__DOT__alu_out)
                                                    : vlSelfRef.soc__DOT__core__DOT__alu_out)
                                                   : vlSelfRef.soc__DOT__core__DOT__alu_out));
    } else {
        vlSelfRef.soc__DOT__core__DOT__rd_we = vlSelfRef.__VdfgRegularize_hebeb780c_0_21;
        vlSelfRef.soc__DOT__core__DOT__rd_val = ((IData)(__VdfgRegularize_hebeb780c_0_12)
                                                  ? vlSelfRef.soc__DOT__core__DOT__alu_out
                                                  : 
                                                 ((IData)(__VdfgRegularize_hebeb780c_0_9)
                                                   ? vlSelfRef.soc__DOT__core__DOT__alu_out
                                                   : 
                                                  ((IData)(__VdfgRegularize_hebeb780c_0_11)
                                                    ? 
                                                   ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_8)
                                                     ? 
                                                    ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_17)
                                                      ? 
                                                     ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                                       ? vlSelfRef.soc__DOT__core__DOT__dmem_rdata
                                                       : 
                                                      ((0x0000ff00U 
                                                        & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                           & ((- (IData)((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2))) 
                                                              << 8U))) 
                                                       | (0x000000ffU 
                                                          & vlSelfRef.soc__DOT__core__DOT__ld_shifted)))
                                                      : 
                                                     ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5)
                                                       ? vlSelfRef.soc__DOT__core__DOT__dmem_rdata
                                                       : 
                                                      ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)
                                                          ? 
                                                         ((0x00ffff00U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                                             >> 0x0000000fU)))) 
                                                              << 8U)) 
                                                          | (0x000000ffU 
                                                             & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                                >> 8U)))
                                                          : 
                                                         (- (IData)(
                                                                    (1U 
                                                                     & (vlSelfRef.soc__DOT__core__DOT__ld_shifted 
                                                                        >> 7U))))) 
                                                        << 8U) 
                                                       | (0x000000ffU 
                                                          & vlSelfRef.soc__DOT__core__DOT__ld_shifted))))
                                                     : vlSelfRef.soc__DOT__core__DOT__alu_out)
                                                    : vlSelfRef.soc__DOT__core__DOT__alu_out)));
    }
    vlSelfRef.soc__DOT__core__DOT__dmem_wstrb = (0x0000000fU 
                                                 & (((0U 
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
                                                                    != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16)))))) 
                                                    & (- (IData)(
                                                                 ((~ 
                                                                   ((IData)(vlSelfRef.soc__DOT__core__DOT__illegal) 
                                                                    | ((IData)(vlSelfRef.rst) 
                                                                       | (IData)(vlSelfRef.soc__DOT__core__DOT__halted)))) 
                                                                  & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_10) 
                                                                     & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_4)) 
                                                                        & ((~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_15)) 
                                                                           & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_21)))))))));
}

bool Vsoc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vsoc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsoc___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsoc___024root___ctor_var_reset(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___ctor_var_reset\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->exit_code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18122477208205310872ull);
    vlSelf->trap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18214934560881419504ull);
    for (int __Vi0 = 0; __Vi0 < 16384; ++__Vi0) {
        vlSelf->soc__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5913278152994935587ull);
    }
    vlSelf->soc__DOT__trace_en = 0;
    vlSelf->soc__DOT__core__DOT__dmem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7937214134923144774ull);
    vlSelf->soc__DOT__core__DOT__dmem_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16936906361065882451ull);
    vlSelf->soc__DOT__core__DOT__dmem_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2306961955314037047ull);
    vlSelf->soc__DOT__core__DOT__dmem_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10739229713171620094ull);
    vlSelf->soc__DOT__core__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4787277902939111264ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->soc__DOT__core__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15988691084188365160ull);
    }
    vlSelf->soc__DOT__core__DOT__halted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12099197478305120489ull);
    vlSelf->soc__DOT__core__DOT__imm_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6366249259924062931ull);
    vlSelf->soc__DOT__core__DOT__imm_u = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2421808375415896443ull);
    vlSelf->soc__DOT__core__DOT__alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6205997462914848785ull);
    vlSelf->soc__DOT__core__DOT__alu_alt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17198671505942671105ull);
    vlSelf->soc__DOT__core__DOT__alu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1049585996272920597ull);
    vlSelf->soc__DOT__core__DOT__misaligned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2891958485223350035ull);
    vlSelf->soc__DOT__core__DOT__ld_shifted = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10534119509663768994ull);
    vlSelf->soc__DOT__core__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18223528553745900833ull);
    vlSelf->soc__DOT__core__DOT__rd_val = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8315891585111628270ull);
    vlSelf->soc__DOT__core__DOT__rd_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10766109712335648929ull);
    vlSelf->soc__DOT__core__DOT__illegal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5931458097459884495ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_0 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_1 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_2 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_3 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_4 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_5 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_6 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_7 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_8 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_10 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_13 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_14 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_15 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_16 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_17 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_18 = 0;
    vlSelf->__VdfgRegularize_hebeb780c_0_21 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
