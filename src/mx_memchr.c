#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n){
    const unsigned char *str = s;
    size_t i = 0;

    for (; i < n && str[i] != c; i++);

    if (i == n) return NULL;

    return (void *)&str[i];
}
