module sinegen #(
    parameter   A_WIDTH = 8, //Address number
                D_WIDTH = 8 //Length of each word
)(
    //interface signals
    input   logic               clk,
    input   logic               rst,
    input   logic               en,
    input   logic [A_WIDTH-1:0] phase,
    //input   logic [D_WIDTH-1:0] incr,
    output  logic [D_WIDTH-1:0] dout1,
    output  logic [D_WIDTH-1:0] dout2
);

    logic   [A_WIDTH-1:0]       address;    //interconnect wire

counter addrCounter (
    .clk (clk), //These are assigning the values from the module to this module
    .rst (rst),
    .en (en),
    //.incr (incr),
    .count (address)
);

rom sineRom (
    .clk (clk),
    .addr1 (address),
    .addr2 (address + phase), //unsure on the syntax of this
    .dout1 (dout1),
    .dout2 (dout2)
);

endmodule
