#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned const char *haystack = big;
    unsigned const char *needle = little;

    for (size_t i = 0; i < big_len; i++) {
        if (haystack[i] == needle[0]) {
            if (mx_memcmp((void *)(&haystack[i]), little, little_len) == 0) {
                return (void *)(&haystack[i]);
            }
        }
    }
    return NULL;
}
