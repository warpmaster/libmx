#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;

    (*count) = 0;
    while (first <= last) {
        int mid = first + (last - first) / 2;
        int check = mx_strcmp(s, arr[mid]);

        (*count)++;
        if (check == 0) {
            return mid;
        } else if (check < 0) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    (*count) = 0;
    return -1;
}
