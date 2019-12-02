#include "libmx.h"

int mx_strlen(const char *s) {
    int len = 0;

    while (s && *s != '\0') {
        len++;
        s++;
    }
    return len;
}
