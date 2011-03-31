#include "sc-mips.h"

static int test(void)
{
   int test[128];
   for (int i = 0; i < 128; i++)
      test[i] = i;

   int sum = 0;
   for (int i = 0; i < 128; i++)
      sum += test[i];

   return sum;
}

int main(void)
{
   u16 val = *DE2_SW;
   u64 i = val * val;

   DE2_RAM[2] = 1;
   *DE2_LEDR = i | DE2_RAM[2];
   *DE2_HEX = test();
}
