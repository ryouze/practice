// Get the approximate square root of a number using the Heron's algorithm.
#include <math.h>
#include <stdio.h>

float heron(int x, int max_iter, int max_decimals) {
    float g = x / 2;  // initial guess
    // rounding hack: 1 decimal = 10, 2 decimals = 100, 3 decimals = 1,000
    int round_hack = pow(10, max_decimals);
    for (int i = 1; i < max_iter + 1; i++) {
        g = (g + x / g) / 2;
        g = round(g * round_hack) / round_hack;
        printf("iter_no=%i; g=%g\n", i, g);  // %g skips trailing zeros
        if (pow(g, 2) == x)
            return g;
    }
    return g;
}

int main(void) {
    int x = 25, max_iter = 10, max_decimals = 3;
    printf("The square root of %i is %g.\n", x, heron(x, max_iter, max_decimals));
    return 0;
}
