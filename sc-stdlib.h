#ifndef __SC_STDLIB_H
#define __SC_STDLIB_H

#include "sc-mips.h"

void *memcpy(void * restrict dest, const void * restrict source, size_t size);
void *memset(void * dest, int byte, size_t size);


#endif
