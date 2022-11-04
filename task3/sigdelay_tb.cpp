//This code was provided. (I did some slight changes and added comments for understanding)
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vsigdelay.h"

#include "vbuddy.cpp"     // include vbuddy code
#define ADDRESS_WIDTH 9 //This relates to the buffer, not the address of the ram. (I think)
#define RAM_SZ pow(2,ADDRESS_WIDTH)

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vsigdelay* top = new Vsigdelay;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("sigdelay.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L2T3:Delay");
  //vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->rst = 0; //input for counter
  top->wr = 1; //for enable write
  top->rd = 1; //for read enable
  top->offset = 64; //for offsetting read addr ahead of write addr - implemented on top level sigdelay.sv
  
  // intialize variables for analogue output
  vbdInitMicIn(1); 

  for (simcyc=0; ; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    top->mic_signal = vbdMicValue(); //on sigdelay.sv, mic_signal would be din for RAM
    top->offset = abs(vbdValue());

    top->rst = simcyc < 2; //unsure if necessary

    // plot RAM input/output, send sample to DAC buffer, and print cycle count
    vbdPlot(int (top->mic_signal) - 50, 0, 255); //og signal is below.
    vbdPlot(int (top->delayed_signal) + 50, 0, 255); //corresponds to dout from RAM
    vbdCycle(simcyc);

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
