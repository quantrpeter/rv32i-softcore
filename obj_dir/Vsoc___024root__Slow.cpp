// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsoc.h for the primary calling header

#include "Vsoc__pch.h"

void Vsoc___024root___ctor_var_reset(Vsoc___024root* vlSelf);

Vsoc___024root::Vsoc___024root(Vsoc__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vsoc___024root___ctor_var_reset(this);
}

void Vsoc___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsoc___024root::~Vsoc___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
