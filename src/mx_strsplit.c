#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;

    int words = mx_count_words(s, c);
    char **strings = (char **)malloc(sizeof(char *) * (words + 1));

    for (int i = 0, b = 0, e = 0; i < words; i++) {
        for (; s[b] == c && s[b] != '\0'; b++);
        e = b;
        for (; s[e] != c && s[e] != '\0'; e++);
        //printf("Before mx_strndup(). b = %d, e = %d\n", b , e);
        strings[i] = mx_strndup(&s[b], e - b);
        b = e;
    }
    strings[words] = NULL;

    return strings;
}
