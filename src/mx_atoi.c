#include "libmx.h"

int mx_atoi(const char *s) {
    int i = 0, digits = 0, number = 0;
    int sign = 1;
    unsigned long long power = 1;

    for (; mx_isspace(s[i]); i++);

    if (s[i] == '-') {
        sign = -1;
        i++;
    }

    for (int j = i; mx_isdigit(s[j]); j++, digits++, power *= 10);

    for (power = power / 10; power > 0; power /= 10, i++) {
        number += (s[i] - 48) * power;
    }

    return sign * number;
}
