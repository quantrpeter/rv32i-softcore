// Verilator testbench: runs the SoC until the program writes EXIT, the core
// traps, or the cycle limit is hit. Plusargs:
//   +prog=<file.hex>      program image (required)
//   +max-cycles=<n>       cycle limit (default 10M)
//   +vcd=<file.vcd>       dump waveforms
//   +trace                print every instruction
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>

#include "Vsoc.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    auto ctx = std::make_unique<VerilatedContext>();
    ctx->commandArgs(argc, argv);
    auto top = std::make_unique<Vsoc>(ctx.get());

    uint64_t max_cycles = 10'000'000;
    if (const char* a = ctx->commandArgsPlusMatch("max-cycles="); a && *a)
        max_cycles = std::strtoull(a + std::strlen("+max-cycles="), nullptr, 0);

    std::unique_ptr<VerilatedVcdC> vcd;
    if (const char* a = ctx->commandArgsPlusMatch("vcd="); a && *a) {
        ctx->traceEverOn(true);
        vcd = std::make_unique<VerilatedVcdC>();
        top->trace(vcd.get(), 99);
        vcd->open(a + std::strlen("+vcd="));
    }

    uint64_t cycle = 0;
    auto tick = [&] {
        top->clk = 1;
        top->eval();
        if (vcd) vcd->dump(ctx->time());
        ctx->timeInc(1);
        top->clk = 0;
        top->eval();
        if (vcd) vcd->dump(ctx->time());
        ctx->timeInc(1);
        ++cycle;
    };

    top->rst = 1;
    top->clk = 0;
    top->eval();
    for (int i = 0; i < 2; ++i) tick();
    top->rst = 0;
    cycle = 0;

    while (!top->done && !top->trap && cycle < max_cycles && !ctx->gotFinish()) tick();

    if (vcd) vcd->close();
    top->final();
    std::fflush(stdout);

    if (top->done) {
        std::fprintf(stderr, "[sim] exit code %u after %llu cycles\n", top->exit_code,
                     (unsigned long long)cycle);
        return top->exit_code == 0 ? 0 : 1;
    }
    if (top->trap) {
        std::fprintf(stderr, "[sim] core trapped after %llu cycles\n", (unsigned long long)cycle);
        return 2;
    }
    std::fprintf(stderr, "[sim] timeout after %llu cycles\n", (unsigned long long)cycle);
    return 3;
}
