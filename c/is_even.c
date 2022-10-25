// Check if a number is even (a multiple of 2).
#include <stdio.h>

int main(void) {
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, val;
    for (i = 0; i < 9; i++) {
        val = nums[i];
        printf("%d is ", val);
        if (val % 2 == 0)
            puts("even");
        else
            puts("odd");
    }
    return 0;
}
