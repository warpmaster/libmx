#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int words = 0;

    if (!str)
        return -1;

    if (mx_strlen(str) == 0)
        return 0;

    for (int index = 0, dist_to_next = mx_get_char_index(str, c); dist_to_next >= 0; ) {
        if (dist_to_next > 0)
            words++;
        index += (dist_to_next + 1);
        dist_to_next = mx_get_char_index(&str[index], c);
    }

    if (str[mx_strlen(str)-1] != c)
        words++;

    return words;
}
