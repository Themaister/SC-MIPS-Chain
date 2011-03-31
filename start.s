###
##
# Entry point and setup for our SC-MIPS
##

.text
.global sc_mips_start
.extern main

sc_mips_start:
   nop
redo:
   li $a0, 0 # argc = 0, it will never be used anyways on this stuff. :D
   li $a1, 0 # argv = 0
   li $sp, 0x007007fc # Set up stack.
   jal main
   j redo
   
