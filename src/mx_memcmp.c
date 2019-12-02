#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	unsigned const char *p1 = s1;
	unsigned const char *p2 = s2;
	size_t i = 0;

	for (; p1[i] == p2[i] && i < n; i++);

	if (i == n)
		return 0;
		 
	return p1[i] - p2[i];
}
