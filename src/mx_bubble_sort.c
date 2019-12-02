#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swaps = 0;
    int flag = 1;

    for (int i = 0; i < size && flag; i++) {
        flag = 0;
        for (int j = 0, last = size - i - 1; j < last; j++) {
            if (mx_strcmp(arr[j], arr[j+1]) > 0) {
                char *temp = arr[j];

                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
                flag = 1;
            }
        }
    }
    return swaps;
}
