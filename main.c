#include "sc-mips.h"
#include "sc-stdlib.h"

int foo[1024];
int bar[64] = {10, 10, 10};
int g_test = 0x10000;

static int test(void)
{
   int sum = 0;
   for (int i = 0; i < 1024; i++)
      sum += i;

   return sum;
}

int main(void)
{
   u16 val = *DE2_SW;
   u64 i = val * val;

   DE2_RAM[2] = 0xFF;
   DE2_RAM[3] = 0x01;
   *DE2_LEDR = i | ((volatile u16*)DE2_RAM)[1];
   u32 tmp = test();
   *DE2_HEX = (tmp | g_test) + val;
}
