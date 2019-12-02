#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t s1_len = mx_strlen(s1);

	return mx_strncpy(mx_strnew(s1_len <= n ? s1_len : n), s1, n);
}
