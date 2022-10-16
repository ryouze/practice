// Convert a decimal number to a binary number.
#include <stdio.h>

int main(void) {
    int decimal_num = 348;
    int c, result, result_remainder, binary_num[32];
    while (decimal_num != 0) {
        result = decimal_num / 2;
        result_remainder = decimal_num % 2;
        printf("%d / 2 = %d R %d\n", decimal_num, result, result_remainder);
        binary_num[c] = decimal_num % 2;
        decimal_num = result;
        c++;
    }
    // print in reverse
    for (int i = c - 1; i >= 0; i--)
        printf("%d", binary_num[i]);
    putchar('\n');
    return 0;
}
