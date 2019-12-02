#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *str = s;
    int i = n - 1;

    for (; i >= 0 && str[i] != c; i--);

    if (i < 0) return NULL;

    return (void *)&str[i];
}
