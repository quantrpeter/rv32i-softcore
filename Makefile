# Simple RV32I soft core on Verilator.
#   make            build the simulator
#   make run PROG=fib [ARGS=+trace]
#   make test       run every program in sw/ and check exit codes

VERILATOR ?= verilator
PYTHON    ?= python3
PROG      ?= hello
ARGS      ?=

RTL  := rtl/rv32i_core.sv rtl/soc.sv
SIM  := obj_dir/Vsoc
PROGS := $(basename $(notdir $(wildcard sw/*.s)))

all: $(SIM)

$(SIM): $(RTL) sim/main.cpp
	$(VERILATOR) --cc --exe --build -j 0 -Wall --trace -O3 -CFLAGS -std=c++17 \
		--top-module soc $(RTL) sim/main.cpp -o Vsoc

build/%.hex: sw/%.s tools/asm.py
	@mkdir -p build
	$(PYTHON) tools/asm.py $< -o $@

run: $(SIM) build/$(PROG).hex
	./$(SIM) +prog=build/$(PROG).hex $(ARGS)

test: $(SIM) $(PROGS:%=build/%.hex)
	@fail=0; for p in $(PROGS); do \
		if ./$(SIM) +prog=build/$$p.hex > build/$$p.log 2>&1; then echo "PASS $$p"; \
		else echo "FAIL $$p (see build/$$p.log)"; fail=1; fi; \
	done; exit $$fail

clean:
	rm -rf obj_dir build

.PHONY: all run test clean
.PRECIOUS: build/%.hex
