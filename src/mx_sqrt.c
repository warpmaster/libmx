#include "libmx.h"

int mx_sqrt(int x) {
    long root = 1;

    if (x < 0) return 0;

    for (; root*root < x; root++);
    if (root*root == x) {
        return (int)root;
    }
    return 0;
}

// double mx_sqrt(double x) {

//     // - algorithm for real numbers:

//     double root = x / 2;
//     double scale_factor = 2.0;

//     if (root < 0) return 0;

//     for (int i = 0; i < 1000; i++, scale_factor *= 1.05) {
//         double squared_root = root*root;

//         if (squared_root == x) {
//             return root;
//         } else if (squared_root > x) {
//             root -= (root / scale_factor);
//         } else {
//             root += (root / scale_factor);
//         }
//     }
//     return root;
// }
