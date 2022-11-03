# Task 2 notes

Task 2:

End goal: display two sinusoidal waves on plot whose phase difference can be 
changed by the rotary switch.

---

steps:

- Rom dual port - two inputs and two outputs for different addresses - change on rom.sv
    - Accordingly change sinegen.sv
- ~~No longer need incr in sinegen.sv and counter.sv~~
- ~~Phase difference implementation:~~
    - ~~addr2 = addr1 + phase?~~
- ~~Testbench changes:~~
    - ~~phase value~~
    - ~~vbdValue() goes to phase.~~
    - ~~two plots using two different outputs~~
