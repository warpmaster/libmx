#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double raised = 1;

    if (n == 0) return 1;

    while (pow--) {
        raised *= n;
    }
    return raised;
}
