/*
Check if a number is even (a multiple of 2) or odd.
*/
#include <stdio.h>

int main(void) {
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0, val;
    while (i < 9) {
        val = nums[i];
        printf("%d is ", val);
        if (val % 2 == 0)
            puts("even");
        else
            puts("odd");
        i++;
    }
    return 0;
}
