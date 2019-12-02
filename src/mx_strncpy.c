#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, size_t len) {
	size_t i = 0;

	for ( ; src[i] != '\0' && i < len; i++)
		dst[i] = src[i];
	for ( ; i < len; i++)
    	dst[i] = '\0';

	return dst;
}
