#include "Misc.h"

void Memset(void* ptr, char val, int size)
{
	char* newPtr = ptr;
	while (size--)
		*newPtr++ = val;
}