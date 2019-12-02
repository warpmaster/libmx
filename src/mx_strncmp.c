#include "libmx.h"

int mx_strncmp(const char *str1, const char *str2, size_t n) {
    int i = 0;

    if (!str1 || !str2)
        return 0;

    for (; str1[i] != '\0' && str1[i] == str2[i] && n > 0; i++, n--);

    if (n == 0)
        return 0;

    return str1[i] - str2[i];
}
