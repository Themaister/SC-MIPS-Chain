#include "sc-mips.h"
#include "sc-stdlib.h"

int foo[128];
int bar[64] = {10, 10, 10};
int g_test = 0x10000;

static int test(void)
{
   int test[128];
   for (int i = 0; i < 128; i++)
      foo[i] = i;

   memcpy(test, foo, sizeof(test));

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
   u32 tmp = test();
   *DE2_HEX = tmp | g_test;
}
