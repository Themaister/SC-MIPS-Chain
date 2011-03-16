SECTIONS {
   ENTRY(sc_mips_start)
   . = 0x00400000;
   .text : { * (.text); }
   .data : { * (.data); }
}
