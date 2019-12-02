#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) return -2;

    for (int i = 0, sub_len = mx_strlen(sub); str[i] != '\0'; i++) {
        if (mx_strncmp(&str[i], sub, sub_len) == 0) {
            return i;
        }
    }
    return -1;
}
