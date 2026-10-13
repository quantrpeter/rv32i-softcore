// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsoc__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vsoc::Vsoc(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsoc__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , done{vlSymsp->TOP.done}
    , trap{vlSymsp->TOP.trap}
    , exit_code{vlSymsp->TOP.exit_code}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsoc::Vsoc(const char* _vcname__)
    : Vsoc(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsoc::~Vsoc() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsoc___024root___eval_debug_assertions(Vsoc___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vsoc___024root___eval_static(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_initial(Vsoc___024root* vlSelf);
VL_ATTR_COLD bool Vsoc___024root___eval_stl(Vsoc___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vsoc___024root___eval_sample(Vsoc___024root* vlSelf);
bool Vsoc___024root___eval_ico(Vsoc___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vsoc___024root___eval_act(Vsoc___024root* vlSelf);
bool Vsoc___024root___eval_inact(Vsoc___024root* vlSelf);
bool Vsoc___024root___eval_nba(Vsoc___024root* vlSelf);
bool Vsoc___024root___eval_obs(Vsoc___024root* vlSelf);
bool Vsoc___024root___eval_react(Vsoc___024root* vlSelf);
void Vsoc___024root___eval_postponed(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_final(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__stl(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__ico(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__act(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__nba(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__obs(Vsoc___024root* vlSelf);
VL_ATTR_COLD void Vsoc___024root___eval_dump_triggers__react(Vsoc___024root* vlSelf);

void Vsoc::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsoc::eval_step\n"); );
    m_evalLoop.eval();
}

void Vsoc::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vsoc___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vsoc::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vsoc::evalStatic() {
    Vsoc___024root___eval_static(&(vlSymsp->TOP));
}

void Vsoc::evalInitial() {
    Vsoc___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vsoc::evalStl(bool firstIteration) {
    return Vsoc___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vsoc::evalSample() {
    Vsoc___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vsoc::evalIco(bool firstIteration) {
    return Vsoc___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vsoc::evalAct() {
    return Vsoc___024root___eval_act(&(vlSymsp->TOP));
}

bool Vsoc::evalInact() {
    return Vsoc___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vsoc::evalNba() {
    return Vsoc___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vsoc::evalObs() {
    return Vsoc___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vsoc::evalReact() {
    return Vsoc___024root___eval_react(&(vlSymsp->TOP));
}

void Vsoc::evalPostponed() {
    Vsoc___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vsoc::evalFinal() {
    Vsoc___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersStl() {
    Vsoc___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersIco() {
    Vsoc___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersAct() {
    Vsoc___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersNba() {
    Vsoc___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersObs() {
    Vsoc___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsoc::dumpTriggersReact() {
    Vsoc___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vsoc::eventsPending() { return false; }

uint64_t Vsoc::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsoc::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsoc::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsoc::hierName() const { return vlSymsp->name(); }
const char* Vsoc::modelName() const { return "Vsoc"; }
unsigned Vsoc::threads() const { return 1; }
void Vsoc::prepareClone() const { contextp()->prepareClone(); }
void Vsoc::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsoc::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vsoc___024root__trace_decl_types(VerilatedVcd* tracep);

void Vsoc___024root__trace_init_top(Vsoc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsoc___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsoc___024root*>(voidSelf);
    Vsoc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vsoc___024root__trace_decl_types(tracep);
    Vsoc___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsoc___024root__trace_register(Vsoc___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vsoc::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsoc::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 90);
    Vsoc___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
