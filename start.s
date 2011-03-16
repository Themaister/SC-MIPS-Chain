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
   li $a0, 0
   li $a1, 0
   jal main
   j redo
   
