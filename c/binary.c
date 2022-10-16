// Convert a decimal number to a binary number.
#include <stdio.h>

int main(void) {
    int decimal_num = 348;
    int count, quotient, remainder, binary_num[32];
    while (decimal_num != 0) {
        quotient = decimal_num / 2;
        remainder = decimal_num % 2;
        printf("%d / 2 = %d R %d\n", decimal_num, quotient, remainder);
        binary_num[count] = decimal_num % 2;
        decimal_num = quotient;
        count++;
    }
    // print in reverse
    for (int i = count - 1; i >= 0; i--)
        printf("%d", binary_num[i]);
    putchar('\n');
    return 0;
}
