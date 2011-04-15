#include "sc-stdlib.h"

void* sc_memcpy(void * restrict out, const void * restrict in, size_t size)
{
   u8 * restrict _out = out;
   const u8 * restrict _in = in;

   for (size_t i = 0; i < size; i++)
      *_out++ = *_in++;

   return out;
}

void* sc_memset(void *data, int byte, size_t size)
{
   u8 * restrict _data = data;
   for (size_t i = 0; i < size; i++)
      *_data++ = byte;

   return data;
}
