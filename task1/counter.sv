module counter #(
    parameter WIDTH = 8
)(
    // interface signals
    input   logic               clk,    // clock
    input   logic               rst,    // reset
    input   logic               en,
    input   logic [WIDTH-1:0]   incr,
    output  logic [WIDTH-1:0]   count   // count output 
);

always_ff @ (posedge clk) //this specifies a clocked circuit. posedge rst is async reset.
    if(rst) count <= {WIDTH{1'b0}}; //Uses concatenation operator
    else if(en)    count <= count + incr;

endmodule
