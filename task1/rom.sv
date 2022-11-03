module rom #( //# allows for parameterisation so later you can do rom #(ADDRESS_WIDTH=16, DA...=10) (...)
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic                         clk,
    input logic     [ADDRESS_WIDTH-1:0] addr,
    output logic    [DATA_WIDTH-1:0]    dout
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0]; //rom_array is an internal value that has memory

initial begin //initial means initialise. Usually non-synthesisable commands (e.g. wouldn't synthesise readmemh, as rom would be built with it)
        $display("Loading rom.");
        //This sort of stuff wouldn't work when programming for an actual chip (other than FPGA, which has data stream)
        $readmemh("sinerom.mem", rom_array);
        //can find more of these macros 
end;

always_ff @(posedge clk)
    dout <= rom_array[addr];

endmodule
