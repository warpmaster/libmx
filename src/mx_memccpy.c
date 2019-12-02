#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	size_t i = 0;

	for (; i < n && ((const char *restrict)src)[i] != c; i++)
		((char *restrict)dst)[i] = ((const char *restrict)src)[i];

	if (i == n)
		return NULL;

	((char *restrict)dst)[i] = c;
	return &((char *restrict)dst)[++i];
}
