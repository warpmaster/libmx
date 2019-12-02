#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int subs = 0, sub_len = 0, rep_len = 0, new_len = 0, b = 0;
    char *rep_str = NULL;

    if (!str || !sub || !replace)
        return NULL;

    sub_len = mx_strlen(sub);
    rep_len = mx_strlen(replace);

    if (sub_len == 0 || rep_len == 0)
        return mx_strdup(str); // or return NULL - ?

    subs = mx_count_substr(str, sub);
    new_len = mx_strlen(str) - subs * (sub_len - rep_len);
    rep_str = mx_strnew(new_len);

    for (int i = 0, l = mx_get_substr_index(str, sub); i < subs; i++) {
        rep_str = mx_strncat(rep_str, &str[b], l);
        rep_str = mx_strcat(rep_str, replace);
        b += l + sub_len;
        l = mx_get_substr_index(&str[b], sub);
    }
    rep_str = mx_strcat(rep_str, &str[b]);

    return rep_str;
}
