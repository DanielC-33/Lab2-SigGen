#include "Vsinegen.h" 
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

//task: make a testbench for sinegen.sv (L4S22)

int main(int argc, char **argv, char **env) {
    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;
    Verilated::traceEverOn(true); 
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("sinegen.vcd");

    if (vbdOpen()!=1) return(-1);
    vbdHeader("Lab 2: SineGen");

    top->clk = 0;
    top->rst = 1;
    top->en = 0;

    int clk = 0;
    for (int i=0; ; i++){
        for(clk=0; clk<2; clk++){
            tfp->dump (2*i*clk);
            top->clk = !top->clk;
            top->eval();
        }
        vbdPlot(int(top->dout), 0, 255);
        vbdCycle(i+1); //what does this do?

        top->rst = i < 3;
        top->en = i > 5;

        if( vbdGetkey() == 'q' ) exit(0);
    }
}