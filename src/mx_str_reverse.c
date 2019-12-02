#include "libmx.h"

void mx_str_reverse(char *s) {
    if (!s) return;

    for (int i = 0, j = mx_strlen(s) - 1; i < j; i++, j--)
        mx_swap_char(&s[i], &s[j]);
}
