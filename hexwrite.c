// Simple program to print out a .hex file for our MIPS.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define INS_MEM_SIZE (1024 * 4) // Size of ROM memory on our puny MIPS.
#define START_ADDR (0x0 / 4) // Divide by 4 here to remember that our instruction memory is word based.

static uint8_t checksum(const uint8_t *in_data, int addr)
{
   unsigned sum = 4 + ((addr & 0xFF00) >> 8) + (addr & 0xFF) + in_data[0] + in_data[1] + in_data[2] + in_data[3];
   uint8_t tmp = sum & 0xFF;
   tmp = ~tmp + 1;
   return tmp;
}

int main(int argc, char **argv)
{
   uint8_t in_data[4];
   FILE *file = fopen(argv[1], "rb");
   FILE *out_file = fopen(argv[2], "wb");

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s infile outfile\n", argv[0]);
      exit(1);
   }

   if ((!file) || (!out_file))
      goto error;

   unsigned start_addr;
   for (start_addr = START_ADDR; !feof(file); start_addr++)
   {
      int rc = fread(in_data, sizeof(in_data), 1, file);
      if (rc != 1)
         break;

      fprintf(out_file, "%s%04x%s%02x%02x%02x%02x%02x\n", ":04", start_addr, "00", (unsigned)in_data[0], (unsigned)in_data[1], (unsigned)in_data[2], (unsigned)in_data[3], (unsigned)checksum(in_data, start_addr));
   }

   if (start_addr > INS_MEM_SIZE)
   {
      fprintf(stderr, "CRITICAL: Binary is larger than instruction memory!\n");
      goto error;
   }

   for (; start_addr < INS_MEM_SIZE; start_addr++)
   {
      uint8_t tmp[4] = {0};
      fprintf(out_file, "%s%04x%s%02x%02x%02x%02x%02x\n", ":04", start_addr, "00", 0, 0, 0, 0, checksum(tmp, start_addr));
   }

   fprintf(out_file, ":00000001FF\n");

   fclose(file);
   fclose(out_file);
   return 0;

error:
   fprintf(stderr, "Error opening file(s).\n");
   if (file)
      fclose(file);
   if (out_file)
      fclose(out_file);
   return 1;
}
