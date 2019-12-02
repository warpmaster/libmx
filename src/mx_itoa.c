#include "libmx.h"

char *mx_itoa(int number) {
    char buffer[12];
    int i = 0;
    long num = number;

    if (number == 0)
        return "0";

    mx_memset(buffer, '\0', 12);

    if (number < 0) {
        buffer[i++] = '-';
        num *= -1;
    }
    for (; num > 0; num /= 10)
        buffer[i++] = num % 10 + 48;

    for (int k = (number > 0 ? 0 : 1), j = i - 1; k < j; k++, j--)
        mx_swap_char(&buffer[k], &buffer[j]);

    return mx_strncpy(mx_strnew(i), buffer, i);
}
