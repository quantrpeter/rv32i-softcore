// Single-cycle RV32I core.
//
// Every instruction completes in one clock. Both memory ports are expected to
// read combinationally; stores are committed by the memory on the rising edge.
// Illegal instructions, misaligned accesses, ECALL and EBREAK halt the core.
module rv32i_core #(
    parameter logic [31:0] RESET_PC = 32'h0000_0000
) (
    input  logic        clk,
    input  logic        rst,
    // instruction port
    output logic [31:0] imem_addr,
    input  logic [31:0] imem_rdata,
    // data port
    output logic [31:0] dmem_addr,
    output logic [31:0] dmem_wdata,
    output logic [ 3:0] dmem_wstrb,
    input  logic [31:0] dmem_rdata,
    // halted on a trap
    output logic        trap
);
  localparam logic [6:0] OP_LUI    = 7'b0110111;
  localparam logic [6:0] OP_AUIPC  = 7'b0010111;
  localparam logic [6:0] OP_JAL    = 7'b1101111;
  localparam logic [6:0] OP_JALR   = 7'b1100111;
  localparam logic [6:0] OP_BRANCH = 7'b1100011;
  localparam logic [6:0] OP_LOAD   = 7'b0000011;
  localparam logic [6:0] OP_STORE  = 7'b0100011;
  localparam logic [6:0] OP_IMM    = 7'b0010011;
  localparam logic [6:0] OP_REG    = 7'b0110011;
  localparam logic [6:0] OP_FENCE  = 7'b0001111;
  localparam logic [6:0] OP_SYSTEM = 7'b1110011;

  logic [31:0] pc;
  logic [31:0] regs[32];
  logic        halted;

  assign imem_addr = pc;
  assign trap      = halted;

  // ---------------------------------------------------------------- decode
  wire  [31:0] insn   = imem_rdata;
  wire  [ 6:0] opcode = insn[6:0];
  wire  [ 4:0] rd     = insn[11:7];
  wire  [ 2:0] funct3 = insn[14:12];
  wire  [ 4:0] rs1    = insn[19:15];
  wire  [ 4:0] rs2    = insn[24:20];
  wire  [ 6:0] funct7 = insn[31:25];

  wire  [31:0] imm_i = {{20{insn[31]}}, insn[31:20]};
  wire  [31:0] imm_s = {{20{insn[31]}}, insn[31:25], insn[11:7]};
  wire  [31:0] imm_b = {{19{insn[31]}}, insn[31], insn[7], insn[30:25], insn[11:8], 1'b0};
  wire  [31:0] imm_u = {insn[31:12], 12'b0};
  wire  [31:0] imm_j = {{11{insn[31]}}, insn[31], insn[19:12], insn[20], insn[30:21], 1'b0};

  wire  [31:0] rs1_val = regs[rs1];  // regs[0] is never written, so it stays 0
  wire  [31:0] rs2_val = regs[rs2];

  // ------------------------------------------------------------------- ALU
  wire         is_reg_op = opcode == OP_REG;
  wire  [31:0] alu_b     = is_reg_op ? rs2_val : imm_i;
  // insn[30] selects SUB (register ops only) and SRA/SRAI
  wire         alu_alt   = insn[30] && (is_reg_op || funct3 == 3'b101);
  logic [31:0] alu_out;

  always_comb begin
    case (funct3)
      3'b000:  alu_out = alu_alt ? rs1_val - alu_b : rs1_val + alu_b;
      3'b001:  alu_out = rs1_val << alu_b[4:0];
      3'b010:  alu_out = {31'b0, $signed(rs1_val) < $signed(alu_b)};
      3'b011:  alu_out = {31'b0, rs1_val < alu_b};
      3'b100:  alu_out = rs1_val ^ alu_b;
      3'b101:  alu_out = alu_alt ? $unsigned($signed(rs1_val) >>> alu_b[4:0]) : rs1_val >> alu_b[4:0];
      3'b110:  alu_out = rs1_val | alu_b;
      default: alu_out = rs1_val & alu_b;
    endcase
  end

  // --------------------------------------------------------------- branches
  logic take_branch;
  always_comb begin
    case (funct3)
      3'b000:  take_branch = rs1_val == rs2_val;
      3'b001:  take_branch = rs1_val != rs2_val;
      3'b100:  take_branch = $signed(rs1_val) < $signed(rs2_val);
      3'b101:  take_branch = $signed(rs1_val) >= $signed(rs2_val);
      3'b110:  take_branch = rs1_val < rs2_val;
      3'b111:  take_branch = rs1_val >= rs2_val;
      default: take_branch = 1'b0;
    endcase
  end

  // ---------------------------------------------------------- loads/stores
  assign dmem_addr = rs1_val + (opcode == OP_STORE ? imm_s : imm_i);
  wire [1:0] byte_off = dmem_addr[1:0];
  wire       misaligned = (funct3[1:0] == 2'b01 && byte_off[0]) ||
                          (funct3[1:0] == 2'b10 && byte_off != 2'b00);

  /* verilator lint_off UNUSEDSIGNAL */
  wire [31:0] ld_shifted = dmem_rdata >> {byte_off, 3'b000};  // only [15:0] used
  /* verilator lint_on UNUSEDSIGNAL */
  logic [31:0] load_val;
  always_comb begin
    case (funct3)
      3'b000:  load_val = {{24{ld_shifted[7]}}, ld_shifted[7:0]};    // LB
      3'b001:  load_val = {{16{ld_shifted[15]}}, ld_shifted[15:0]};  // LH
      3'b100:  load_val = {24'b0, ld_shifted[7:0]};                  // LBU
      3'b101:  load_val = {16'b0, ld_shifted[15:0]};                 // LHU
      default: load_val = dmem_rdata;                                // LW
    endcase
  end

  assign dmem_wdata = rs2_val << {byte_off, 3'b000};
  logic [3:0] store_mask;
  always_comb begin
    case (funct3[1:0])
      2'b00:   store_mask = 4'b0001 << byte_off;
      2'b01:   store_mask = 4'b0011 << byte_off;
      default: store_mask = 4'b1111;
    endcase
  end

  // ---------------------------------------------------------------- control
  wire [31:0] pc_plus4 = pc + 32'd4;
  logic [31:0] pc_next, rd_val;
  logic        rd_we, store_en, illegal;

  always_comb begin
    pc_next  = pc_plus4;
    rd_val   = alu_out;
    rd_we    = 1'b0;
    store_en = 1'b0;
    illegal  = 1'b0;
    case (opcode)
      OP_LUI: begin
        rd_we  = 1'b1;
        rd_val = imm_u;
      end
      OP_AUIPC: begin
        rd_we  = 1'b1;
        rd_val = pc + imm_u;
      end
      OP_JAL: begin
        rd_we   = 1'b1;
        rd_val  = pc_plus4;
        pc_next = pc + imm_j;
      end
      OP_JALR: begin
        rd_we   = 1'b1;
        rd_val  = pc_plus4;
        pc_next = (rs1_val + imm_i) & ~32'd1;
        illegal = funct3 != 3'b000;
      end
      OP_BRANCH: begin
        if (take_branch) pc_next = pc + imm_b;
        illegal = funct3[2:1] == 2'b01;
      end
      OP_LOAD: begin
        rd_we   = 1'b1;
        rd_val  = load_val;
        illegal = funct3 == 3'b011 || funct3[2:1] == 2'b11 || misaligned;
      end
      OP_STORE: begin
        store_en = 1'b1;
        illegal  = funct3[2] || funct3[1:0] == 2'b11 || misaligned;
      end
      OP_IMM: begin
        rd_we   = 1'b1;
        illegal = (funct3 == 3'b001 && funct7 != 7'h00) ||
                  (funct3 == 3'b101 && funct7 != 7'h00 && funct7 != 7'h20);
      end
      OP_REG: begin
        rd_we   = 1'b1;
        illegal = funct7 != 7'h00 &&
                  !(funct7 == 7'h20 && (funct3 == 3'b000 || funct3 == 3'b101));
      end
      OP_FENCE: ;  // single hart, in-order: nothing to do
      default: illegal = 1'b1;  // includes SYSTEM (ECALL/EBREAK)
    endcase
    if (pc_next[1:0] != 2'b00) illegal = 1'b1;  // no C extension
  end

  assign dmem_wstrb = (store_en && !illegal && !halted && !rst) ? store_mask : 4'b0000;

  always_ff @(posedge clk) begin
    if (rst) begin
      pc     <= RESET_PC;
      halted <= 1'b0;
      for (int i = 0; i < 32; i++) regs[i] <= 32'b0;
    end else if (!halted) begin
      if (illegal) begin
        halted <= 1'b1;
        if (opcode == OP_SYSTEM)
          $display("[core] %s at pc=%08x", insn[20] ? "EBREAK" : "ECALL", pc);
        else
          $display("[core] TRAP: illegal/misaligned insn %08x at pc=%08x", insn, pc);
      end else begin
        pc <= pc_next;
        if (rd_we && rd != 5'd0) regs[rd] <= rd_val;
      end
    end
  end
endmodule
