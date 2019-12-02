#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int subs = 0;
    int sub_len = mx_strlen(sub);

    if (!str || !sub)
        return -1;

    if (sub_len == 0)
        return 0;

    for (int i = mx_get_substr_index(str, sub), j = 0; i >= 0; subs++) {
        j += (i + sub_len);
        i = mx_get_substr_index(&str[j], sub);
    }
    return subs;
}
