// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsoc.h for the primary calling header

#ifndef VERILATED_VSOC___024ROOT_H_
#define VERILATED_VSOC___024ROOT_H_  // guard

#include "verilated.h"


class Vsoc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsoc___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(done,0,0);
    VL_OUT8(trap,0,0);
    CData/*0:0*/ soc__DOT__trace_en;
    CData/*3:0*/ soc__DOT__core__DOT__dmem_wstrb;
    CData/*0:0*/ soc__DOT__core__DOT__halted;
    CData/*0:0*/ soc__DOT__core__DOT__alu_alt;
    CData/*0:0*/ soc__DOT__core__DOT__misaligned;
    CData/*0:0*/ soc__DOT__core__DOT__rd_we;
    CData/*0:0*/ soc__DOT__core__DOT__illegal;
    CData/*6:0*/ __VdfgRegularize_hebeb780c_0_0;
    CData/*2:0*/ __VdfgRegularize_hebeb780c_0_1;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_2;
    CData/*6:0*/ __VdfgRegularize_hebeb780c_0_3;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_4;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_5;
    CData/*4:0*/ __VdfgRegularize_hebeb780c_0_6;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_7;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_8;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_10;
    CData/*4:0*/ __VdfgRegularize_hebeb780c_0_13;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_14;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_15;
    CData/*1:0*/ __VdfgRegularize_hebeb780c_0_16;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_17;
    CData/*4:0*/ __VdfgRegularize_hebeb780c_0_18;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_21;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    VL_OUT(exit_code,31,0);
    IData/*31:0*/ soc__DOT__core__DOT__dmem_addr;
    IData/*31:0*/ soc__DOT__core__DOT__dmem_wdata;
    IData/*31:0*/ soc__DOT__core__DOT__dmem_rdata;
    IData/*31:0*/ soc__DOT__core__DOT__pc;
    IData/*31:0*/ soc__DOT__core__DOT__imm_i;
    IData/*31:0*/ soc__DOT__core__DOT__imm_u;
    IData/*31:0*/ soc__DOT__core__DOT__alu_b;
    IData/*31:0*/ soc__DOT__core__DOT__alu_out;
    IData/*31:0*/ soc__DOT__core__DOT__ld_shifted;
    IData/*31:0*/ soc__DOT__core__DOT__pc_next;
    IData/*31:0*/ soc__DOT__core__DOT__rd_val;
    VlUnpacked<IData/*31:0*/, 16384> soc__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> soc__DOT__core__DOT__regs;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    std::string soc__DOT__unnamedblk1__DOT__prog;

    // INTERNAL VARIABLES
    Vsoc__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsoc___024root(Vsoc__Syms* symsp, const char* namep);
    ~Vsoc___024root();
    VL_UNCOPYABLE(Vsoc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
