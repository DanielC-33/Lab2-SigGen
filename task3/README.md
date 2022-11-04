# Task 3 notes - Capture and Display audio signal in RAM

End goal:
- Using mic on vbuddy, display both write and read data from dual-port ram on display.

Steps:
- ~~Testbench has been provided, go through and understand.~~
- ~~Make a SystemV 512 x 8 bit dual-port RAM module~~
    - ~~Check L4S25~~
- ~~Make a top-level sigdelay.sv module which has the RAM and a counter~~
    - ~~Top-level design end of L4~~
    - ~~Use the tb to decide which variables to make on the sv - check comments~~
    - ~~clk, rst, wr, rd (for ram), offset \[7:0\] (adder), mic_signal \[7:0\] (din), delayed_signal \[7:0\] (dout), address \[7:0\] (as a wire, not input or output)~~
- ~~update doit.sh~~


Quite unsure if it works. The delay definitely works, but the audio signal doesn't look very nice. (should test with higher audio)