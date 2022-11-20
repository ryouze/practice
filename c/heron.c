/*
Get the approximate square root of a number using the Heron's algorithm.

This is not meant to be efficient.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float heron(int *x, int *max_iter, int *max_decimals) {
    float g = *x / 2;  // initial guess
    // rounding hack: 1 decimal = 10, 2 decimals = 100, 3 decimals = 1,000
    int round_hack = pow(10, *max_decimals);
    for (int i = 1; i < *max_iter + 1; i++) {
        g = (g + *x / g) / 2;
        g = round(g * round_hack) / round_hack;
        printf("iter_no=%i; g=%g\n", i, g);  // %g skips trailing zeros
        if (pow(g, 2) == *x) {
            puts("SUCCESS: found exact square root.");
            return g;
        }
    }
    printf("FAIL: giving up after %d tries.\n", *max_iter);
    return g;
}

int main(int argc, char *argv[]) {
    /*
    argc is the number of arguments passed to your program, including the program name itself.
    argv is an array containing each argument as a string of characters.
    */
    if (argc != 2) {
        printf("Please provide a number. For example to get the square root of 25:\n%s 25\n", argv[0]);
        return 1;
    }
    int x = atoi(argv[1]);  // convert to int
    printf("You have entered: %d\n", x);
    int max_iter = 10, max_decimals = 3;
    printf("The square root of %i is %g.\n", x, heron(&x, &max_iter, &max_decimals));
    return 0;
}
