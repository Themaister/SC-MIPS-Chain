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

   jal dump_grom_to_ram

   jal main
   j redo
   


dump_grom_to_ram:
   li $t0, 0x00300000 # Source
   li $t1, 0x00700000 # Dest
   li $t2, 512 # Words to copy
_loop:
   lw $t3, 0($t0)
   sw $t3, 0($t1)
   addi $t2, $t2, -1
   addi $t0, $t0, 4
   addi $t1, $t1, 4
   bnez $t2, _loop

   jr $ra
