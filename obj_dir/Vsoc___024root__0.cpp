// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc.h for the primary calling header

#include "Vsoc__pch.h"

void Vsoc___024root___eval_sample(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_sample\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vsoc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

bool Vsoc___024root___eval_ico(Vsoc___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_ico\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (IData)((IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.rst) 
                                                           != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.clk) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vsoc___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((2ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.soc__DOT__core__DOT__dmem_wstrb 
                        = (0x0000000fU & (((0U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_16))
                                            ? ((IData)(1U) 
                                               << (3U 
                                                   & vlSelfRef.soc__DOT__core__DOT__dmem_addr))
                                            : (((IData)(3U) 
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
            }
        }
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vsoc___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vsoc___024root___eval_act(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_act\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsoc___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsoc___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vsoc___024root___eval_inact(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_inact\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vsoc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vsoc___024root___nba_sequent__TOP__0(Vsoc___024root* vlSelf);
void Vsoc___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vsoc___024root___eval_nba(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_nba\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsoc___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vsoc___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__Vm_traceActivity[1U] = 1U;
            }
        }
        Vsoc___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vsoc___024root___eval_obs(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_obs\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vsoc___024root___eval_react(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_react\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vsoc___024root___eval_postponed(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_postponed\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vsoc___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vsoc___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___trigger_anySet__act\n"); );
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

void Vsoc___024root___nba_sequent__TOP__0(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___nba_sequent__TOP__0\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_9;
    __VdfgRegularize_hebeb780c_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_11;
    __VdfgRegularize_hebeb780c_0_11 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_12;
    __VdfgRegularize_hebeb780c_0_12 = 0;
    IData/*31:0*/ __Vdly__soc__DOT__core__DOT__pc;
    __Vdly__soc__DOT__core__DOT__pc = 0;
    CData/*0:0*/ __Vdly__soc__DOT__core__DOT__halted;
    __Vdly__soc__DOT__core__DOT__halted = 0;
    CData/*7:0*/ __VdlyVal__soc__DOT__mem__v0;
    __VdlyVal__soc__DOT__mem__v0 = 0;
    SData/*13:0*/ __VdlyDim0__soc__DOT__mem__v0;
    __VdlyDim0__soc__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__mem__v0;
    __VdlySet__soc__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__soc__DOT__mem__v1;
    __VdlyVal__soc__DOT__mem__v1 = 0;
    SData/*13:0*/ __VdlyDim0__soc__DOT__mem__v1;
    __VdlyDim0__soc__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__mem__v1;
    __VdlySet__soc__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__soc__DOT__mem__v2;
    __VdlyVal__soc__DOT__mem__v2 = 0;
    SData/*13:0*/ __VdlyDim0__soc__DOT__mem__v2;
    __VdlyDim0__soc__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__mem__v2;
    __VdlySet__soc__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__soc__DOT__mem__v3;
    __VdlyVal__soc__DOT__mem__v3 = 0;
    SData/*13:0*/ __VdlyDim0__soc__DOT__mem__v3;
    __VdlyDim0__soc__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__mem__v3;
    __VdlySet__soc__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__core__DOT__regs__v0;
    __VdlySet__soc__DOT__core__DOT__regs__v0 = 0;
    IData/*31:0*/ __VdlyVal__soc__DOT__core__DOT__regs__v32;
    __VdlyVal__soc__DOT__core__DOT__regs__v32 = 0;
    CData/*4:0*/ __VdlyDim0__soc__DOT__core__DOT__regs__v32;
    __VdlyDim0__soc__DOT__core__DOT__regs__v32 = 0;
    CData/*0:0*/ __VdlySet__soc__DOT__core__DOT__regs__v32;
    __VdlySet__soc__DOT__core__DOT__regs__v32 = 0;
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelfRef.soc__DOT__trace_en) 
                       & (~ (IData)(vlSelfRef.rst))) 
                      & (~ (IData)(vlSelfRef.soc__DOT__core__DOT__halted)))))) {
        VL_WRITEF_NX("[trace] pc=%08x insn=%08x\n",2
                     , '#',32,vlSelfRef.soc__DOT__core__DOT__pc
                     , '#',32,vlSelfRef.soc__DOT__mem
                     [(0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                      >> 2U))]);
    }
    __Vdly__soc__DOT__core__DOT__halted = vlSelfRef.soc__DOT__core__DOT__halted;
    __VdlySet__soc__DOT__core__DOT__regs__v0 = 0U;
    __VdlySet__soc__DOT__core__DOT__regs__v32 = 0U;
    __Vdly__soc__DOT__core__DOT__pc = vlSelfRef.soc__DOT__core__DOT__pc;
    __VdlySet__soc__DOT__mem__v0 = 0U;
    __VdlySet__soc__DOT__mem__v1 = 0U;
    __VdlySet__soc__DOT__mem__v2 = 0U;
    __VdlySet__soc__DOT__mem__v3 = 0U;
    if (vlSelfRef.rst) {
        __Vdly__soc__DOT__core__DOT__pc = 0U;
        __Vdly__soc__DOT__core__DOT__halted = 0U;
        __VdlySet__soc__DOT__core__DOT__regs__v0 = 1U;
    } else if ((1U & (~ (IData)(vlSelfRef.soc__DOT__core__DOT__halted)))) {
        if (vlSelfRef.soc__DOT__core__DOT__illegal) {
            if ((0x73U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_0))) {
                VL_WRITEF_NX("[core] %s at pc=%08x\n",2
                             , '#',48,((0x00100000U 
                                        & vlSelfRef.soc__DOT__mem
                                        [(0x00003fffU 
                                          & (vlSelfRef.soc__DOT__core__DOT__pc 
                                             >> 2U))])
                                        ? 0x000045425245414bULL
                                        : 0x0000004543414c4cULL)
                             , '#',32,vlSelfRef.soc__DOT__core__DOT__pc);
            } else {
                VL_WRITEF_NX("[core] TRAP: illegal/misaligned insn %08x at pc=%08x\n",2
                             , '#',32,vlSelfRef.soc__DOT__mem
                             [(0x00003fffU & (vlSelfRef.soc__DOT__core__DOT__pc 
                                              >> 2U))]
                             , '#',32,vlSelfRef.soc__DOT__core__DOT__pc);
            }
            __Vdly__soc__DOT__core__DOT__halted = 1U;
        } else {
            __Vdly__soc__DOT__core__DOT__pc = vlSelfRef.soc__DOT__core__DOT__pc_next;
            if (((IData)(vlSelfRef.soc__DOT__core__DOT__rd_we) 
                 & (0U != (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_6)))) {
                __VdlyVal__soc__DOT__core__DOT__regs__v32 
                    = vlSelfRef.soc__DOT__core__DOT__rd_val;
                __VdlyDim0__soc__DOT__core__DOT__regs__v32 
                    = vlSelfRef.__VdfgRegularize_hebeb780c_0_6;
                __VdlySet__soc__DOT__core__DOT__regs__v32 = 1U;
            }
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.done = 0U;
        vlSelfRef.exit_code = 0U;
    } else if ((0U != (IData)(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb))) {
        if ((1U == (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                    >> 0x0000001cU))) {
            if (VL_UNLIKELY(((0U == (0x0000000fU & vlSelfRef.soc__DOT__core__DOT__dmem_addr))))) {
                VL_WRITEF_NX("%c",1, '#',8,(0x000000ffU 
                                            & vlSelfRef.soc__DOT__core__DOT__dmem_wdata));
                VL_FFLUSH_MT();} else if ((4U == (0x0000000fU 
                                                  & vlSelfRef.soc__DOT__core__DOT__dmem_addr))) {
                vlSelfRef.done = 1U;
                vlSelfRef.exit_code = vlSelfRef.soc__DOT__core__DOT__dmem_wdata;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb))) {
                __VdlyVal__soc__DOT__mem__v0 = (0x000000ffU 
                                                & vlSelfRef.soc__DOT__core__DOT__dmem_wdata);
                __VdlyDim0__soc__DOT__mem__v0 = (0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                    >> 2U));
                __VdlySet__soc__DOT__mem__v0 = 1U;
            }
            if ((2U & (IData)(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb))) {
                __VdlyVal__soc__DOT__mem__v1 = (0x000000ffU 
                                                & (vlSelfRef.soc__DOT__core__DOT__dmem_wdata 
                                                   >> 8U));
                __VdlyDim0__soc__DOT__mem__v1 = (0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                    >> 2U));
                __VdlySet__soc__DOT__mem__v1 = 1U;
            }
            if ((4U & (IData)(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb))) {
                __VdlyVal__soc__DOT__mem__v2 = (0x000000ffU 
                                                & (vlSelfRef.soc__DOT__core__DOT__dmem_wdata 
                                                   >> 0x10U));
                __VdlyDim0__soc__DOT__mem__v2 = (0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                    >> 2U));
                __VdlySet__soc__DOT__mem__v2 = 1U;
            }
            if ((8U & (IData)(vlSelfRef.soc__DOT__core__DOT__dmem_wstrb))) {
                __VdlyVal__soc__DOT__mem__v3 = (vlSelfRef.soc__DOT__core__DOT__dmem_wdata 
                                                >> 0x18U);
                __VdlyDim0__soc__DOT__mem__v3 = (0x00003fffU 
                                                 & (vlSelfRef.soc__DOT__core__DOT__dmem_addr 
                                                    >> 2U));
                __VdlySet__soc__DOT__mem__v3 = 1U;
            }
        }
    }
    vlSelfRef.soc__DOT__core__DOT__halted = __Vdly__soc__DOT__core__DOT__halted;
    if (__VdlySet__soc__DOT__core__DOT__regs__v0) {
        vlSelfRef.soc__DOT__core__DOT__regs[0U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[1U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[2U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[3U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[4U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[5U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[6U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[7U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[8U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[9U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[10U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[11U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[12U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[13U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[14U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[15U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[16U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[17U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[18U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[19U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[20U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[21U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[22U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[23U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[24U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[25U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[26U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[27U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[28U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[29U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[30U] = 0U;
        vlSelfRef.soc__DOT__core__DOT__regs[31U] = 0U;
    }
    if (__VdlySet__soc__DOT__core__DOT__regs__v32) {
        vlSelfRef.soc__DOT__core__DOT__regs[__VdlyDim0__soc__DOT__core__DOT__regs__v32] 
            = __VdlyVal__soc__DOT__core__DOT__regs__v32;
    }
    vlSelfRef.soc__DOT__core__DOT__pc = __Vdly__soc__DOT__core__DOT__pc;
    if (__VdlySet__soc__DOT__mem__v0) {
        vlSelfRef.soc__DOT__mem[__VdlyDim0__soc__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.soc__DOT__mem
                [__VdlyDim0__soc__DOT__mem__v0]) | (IData)(__VdlyVal__soc__DOT__mem__v0));
    }
    if (__VdlySet__soc__DOT__mem__v1) {
        vlSelfRef.soc__DOT__mem[__VdlyDim0__soc__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.soc__DOT__mem
                [__VdlyDim0__soc__DOT__mem__v1]) | 
               ((IData)(__VdlyVal__soc__DOT__mem__v1) 
                << 8U));
    }
    if (__VdlySet__soc__DOT__mem__v2) {
        vlSelfRef.soc__DOT__mem[__VdlyDim0__soc__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.soc__DOT__mem
                [__VdlyDim0__soc__DOT__mem__v2]) | 
               ((IData)(__VdlyVal__soc__DOT__mem__v2) 
                << 0x00000010U));
    }
    if (__VdlySet__soc__DOT__mem__v3) {
        vlSelfRef.soc__DOT__mem[__VdlyDim0__soc__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.soc__DOT__mem
                [__VdlyDim0__soc__DOT__mem__v3]) | 
               ((IData)(__VdlyVal__soc__DOT__mem__v3) 
                << 0x00000018U));
    }
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

void Vsoc___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vsoc___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vsoc___024root___eval_debug_assertions(Vsoc___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsoc___024root___eval_debug_assertions\n"); );
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
