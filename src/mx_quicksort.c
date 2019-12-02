#include "libmx.h"

static void swap_elements(char **left, char **right) {
    char *temp = *left;
    *left = *right;
    *right = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    if (left >= right) return 0;

    int swaps = 0;
    int pi = left;
    char *pivot = arr[left+(right-left)/2];
    int pivot_len = mx_strlen(pivot);

    //printf("PIVOT\nindex: %d\t value: %s\t length: %d\n", left+(right-left)/2, pivot, pivot_len);
    //printf("left: %s, index: %d\t right: %s, index: %d\n", arr[left], left, arr[right], right);
    for (int r = right; pi <= r;) {
        for (; mx_strlen(arr[pi]) < pivot_len ; pi++);
        //printf("l [%d] is now pointing to: %s\n", pi, arr[pi]);
        for (; mx_strlen(arr[r]) > pivot_len ; r--);
        //printf("r [%d] is now pointing to: %s\n\n", r, arr[r]);
        if (pi <= r) {
            if (mx_strlen(arr[pi]) != mx_strlen(arr[r])) {
                //printf("swapping: %s and %s\n", arr[pi], arr[r]);
                swap_elements(&arr[pi], &arr[r]);
                swaps++;
                //printf("swaps: %d\n\n", swaps);
            }
            pi++;
            r--;
        }
    }
    //printf("end of call, partition index = %d\n\n", pi);
    return swaps + mx_quicksort(arr, left, pi - 1) + mx_quicksort(arr, pi, right);
}

// static void skip_and_swap(char **arr, int *l, int *r, char *pivot, int *sw) {
//     char *temp = NULL;

//     while(mx_strlen(arr[*l]) < mx_strlen(pivot))
//         (*l)++;
//     while(mx_strlen(arr[*r]) > mx_strlen(pivot))
//         (*r)--;

//     if(*l <= *r) {
//         temp = arr[*l];
//         arr[(*l)++] = arr[*r];
//         arr[(*r)--] = temp;
//         (*sw)++;
//     }
// }

// int mx_quicksort(char **arr, int left, int right) {
//     if(arr) {
//         char *pivot = arr[(left + right) / 2];
//         int l = left;
//         int r = right;
//         int swaps = 0;

//         while(l <= r)
//             skip_and_swap(arr, &l, &r, pivot, &swaps);
//         if(left < r)
//             mx_quicksort(arr, left, r);
//         if(right > l)
//             mx_quicksort(arr, l, right);
//         return swaps;
//     }
//     else
//         return -1;
// }


// int mx_quicksort(int *arr, int left, int right) {
//     if (!arr) return -1;
//     if (left >= right) return 0;

//     int shifts = 0;
//     int pi = left;
//     int pivot = arr[left+(right-left)/2];

//     printf("** pivot is: %d\n", pivot);
//     printf("** left is: %d\n", arr[left]);
//     printf("** right is: %d\n\n", arr[right]);

//     for (int r = right; pi <= r;) {
//         for (; arr[pi] < pivot; pi++);
//         printf("l [%d] is now pointing to: %d\n", pi, arr[pi]);
//         for (; arr[r] > pivot; r--);
//         printf("r [%d] is now pointing to: %d\n\n", r, arr[r]);
//         if (pi <= r) {
//             if (pi != r) {
//                 printf("** now swapping l [%d]: %d and r [%d]: %d\n\n", pi, arr[pi], r, arr[r]);
//                 int temp = arr[pi];
//                 arr[pi] = arr[r];
//                 arr[r] = temp;
//                 shifts++;
//             }
//             pi++;
//             r--;
//         }
//     }
//     printf("end of call, partition index = %d\n", pi);
//     return shifts + mx_quicksort(arr, left, pi - 1) + mx_quicksort(arr, pi, right);
// }

// int mx_quicksort(char **arr, int left, int right) {
//     if (!arr) return -1;
//     if (left >= right) return 0;
//     //srand(time(NULL));

//     int shifts = 0;
//     int pi = left;
//     //int pivot_index = left + rand() % (right - left);
//     int pivot_index = left + (right - left) / 2;
//     char *pivot = arr[pivot_index];
//     arr[pivot_index] = arr[right];
//     arr[right] = pivot;
//     shifts++;

//     for (int i = left; i < right; i++) {
//         if (mx_strcmp(arr[i], pivot) < 0) {
//             if (i != pi) {
//                 swap_elements(arr[i], arr[pi]);
//                 shifts++;
//             }
//             pi++;
//         }
//     }
//     if (arr[right] != arr[pi]) {
//         arr[right] = arr[pi];
//         arr[pi] = pivot;
//         if (pi != pivot_index) {
//             shifts++;
//         }
//     }
//     return shifts + mx_quicksort(arr, left, pi - 1) + mx_quicksort(arr, pi + 1, right);
// }
