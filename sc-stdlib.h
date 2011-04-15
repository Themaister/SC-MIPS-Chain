#ifndef __SC_STDLIB_H
#define __SC_STDLIB_H

#include "sc-mips.h"

void *sc_memcpy(void * restrict dest, const void * restrict source, size_t size);
void *sc_memset(void * dest, int byte, size_t size);


#endif
