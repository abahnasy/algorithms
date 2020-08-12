#include <stdlib.h>

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return (b%a, a);
    }
}
