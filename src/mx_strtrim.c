#include "libmx.h"

char *mx_strtrim(const char *str) {
    int i = 0;
    int j = mx_strlen(str) - 1;
    char *trim_str = NULL;

    if (!str) return NULL;

    for (; mx_isspace(str[i]) && i < j; i++);
    for (; mx_isspace(str[j]) && j >= i; j--);

    trim_str = mx_strndup(&str[i], j - i + 1);
    //free((void *)str);

    return trim_str;
}
