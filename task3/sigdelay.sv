module sigdelay #(
    parameter   ADDRESS_W = 8,
                DATA_W = 8
)(
    input logic                     clk,
    input logic                     rst,
    input logic                     wr,
    input logic                     rd,
    input logic     [ADDRESS_W-1:0] offset,
    input logic     [DATA_W-1:0]    mic_signal,
    output logic    [DATA_W-1:0]    delayed_signal
);

logic [ADDRESS_W-1:0] address;

counter #(ADDRESS_W) addr_count ( //is this the right syntax for parameterisation?
    .clk (clk),
    .rst (rst),
    .en (1'b1),
    .count (address)
);

ram2ports #(ADDRESS_W, DATA_W) mic_ram (
    .clk (clk),
    .wr_en (wr),
    .rd_en (rd),
    .wr_addr (address),
    .rd_addr (address - offset - {{ADDRESS_W-1{1'b0}}, 1'b1}), //needs minimum 1 address offset because of delay between writing and reading
    .din (mic_signal),
    .dout (delayed_signal)
);
endmodule
