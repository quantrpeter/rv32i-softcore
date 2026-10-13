// Minimal SoC: RV32I core + unified RAM + two memory-mapped registers.
//
// Memory map:
//   0x0000_0000  RAM (MEM_WORDS * 4 bytes), program loaded via +prog=<hex>
//   0x1000_0000  UART_TX  (write: print low byte to stdout)
//   0x1000_0004  EXIT     (write: stop simulation, value = exit code)
module soc #(
    parameter int MEM_WORDS = 16384  // 64 KiB
) (
    input  logic        clk,
    input  logic        rst,
    output logic        done,
    output logic [31:0] exit_code,
    output logic        trap
);
  localparam int AW = $clog2(MEM_WORDS);

  /* verilator lint_off UNUSEDSIGNAL */
  logic [31:0] imem_addr, dmem_addr;
  /* verilator lint_on UNUSEDSIGNAL */
  logic [31:0] imem_rdata, dmem_wdata, dmem_rdata;
  logic [ 3:0] dmem_wstrb;

  rv32i_core core (
      .clk,
      .rst,
      .imem_addr,
      .imem_rdata,
      .dmem_addr,
      .dmem_wdata,
      .dmem_wstrb,
      .dmem_rdata,
      .trap
  );

  logic [31:0] mem[MEM_WORDS];

  initial begin
    string prog;
    for (int i = 0; i < MEM_WORDS; i++) mem[i] = 32'b0;
    if ($value$plusargs("prog=%s", prog)) $readmemh(prog, mem);
    else $fatal(1, "usage: +prog=<file.hex>");
  end

  wire is_io = dmem_addr[31:28] == 4'h1;
  wire [AW-1:0] iword = imem_addr[AW+1:2];
  wire [AW-1:0] dword = dmem_addr[AW+1:2];

  assign imem_rdata = mem[iword];
  assign dmem_rdata = is_io ? 32'b0 : mem[dword];

  always_ff @(posedge clk) begin
    if (rst) begin
      done      <= 1'b0;
      exit_code <= 32'b0;
    end else if (|dmem_wstrb) begin
      if (is_io) begin
        case (dmem_addr[3:0])
          4'h0: begin
            $write("%c", dmem_wdata[7:0]);
            $fflush;
          end
          4'h4: begin
            done      <= 1'b1;
            exit_code <= dmem_wdata;
          end
          default: ;
        endcase
      end else begin
        for (int i = 0; i < 4; i++)
          if (dmem_wstrb[i]) mem[dword][i*8+:8] <= dmem_wdata[i*8+:8];
      end
    end
  end

  // +trace prints every retired instruction
  bit trace_en;
  initial trace_en = $test$plusargs("trace") != 0;
  always_ff @(posedge clk)
    if (trace_en && !rst && !trap) $display("[trace] pc=%08x insn=%08x", imem_addr, imem_rdata);
endmodule
