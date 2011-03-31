#ifndef __SC_MIPS_H
#define __SC_MIPS_H

// Header defining some MMAP-ed addresses. :)
//

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

#define DE2_SW ((volatile const u16*)0x00600002)
#define DE2_LEDR ((volatile u16*)0x00500002)
#define DE2_LEDG ((volatile u8*)0x00500007)
#define DE2_HEX ((volatile u32*)0x00500008)
#define DE2_RAM ((volatile u8*)0x00700000)

#endif
