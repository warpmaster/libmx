#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2) return NULL;
    if (!s2) return mx_strdup(s1);
    if (!s1) return mx_strdup(s2);

    return mx_strcat(mx_strcpy(mx_strnew(mx_strlen(s1) + mx_strlen(s2)), s1), s2);
}
