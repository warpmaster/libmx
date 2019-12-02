#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *tr = mx_strtrim(str);
    char *s = NULL;

    if (!str)
        return NULL;

    s = mx_strnew(mx_strlen(tr));
    s[0] = tr[0];
    if (s[0] != '\0') {
        for (int i = 1, j = 1; tr[i] != '\0'; i++) {
            if (!mx_isspace(tr[i]))
                s[j++] = tr[i];
            if (mx_isspace(tr[i]) && !mx_isspace(tr[i-1]))
                s[j++] = ' ';
        }
    }
    free(tr);

    return mx_realloc(s, mx_strlen(s)+1);
}
