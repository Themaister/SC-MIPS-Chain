#include "sc-mips.h"

int main(void)
{
   volatile const short *switches = DE2_SW;
   volatile short* led = DE2_LEDR;
   *led = (*switches << 2) + 1;
}
