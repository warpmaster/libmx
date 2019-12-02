#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !(*arr) || !delim)
        return;

    mx_printstr(*arr);
    while (*(++arr)) {
        mx_printstr(delim);
        mx_printstr(*arr);
    }
    mx_printchar('\n');
}
