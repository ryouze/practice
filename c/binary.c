/*
Convert a positive decimal number to binary number.

E.g.,
348 / 2 = 174 R 0
174 / 2 = 87 R 0
87 / 2 = 43 R 1
43 / 2 = 21 R 1
21 / 2 = 10 R 1
10 / 2 = 5 R 0
5 / 2 = 2 R 1
2 / 2 = 1 R 0
1 / 2 = 0 R 1
101011100
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /*
    argc is the number of arguments passed to your program, including the program name itself.
    argv is an array containing each argument as a string of characters.
    */
    if (argc != 2) {
        printf("Please provide a number. For example to get 348 in binary:\n%s 348\n", argv[0]);
        return -1;
    }
    int decimal_num = atoi(argv[1]);  // convert to int
    printf("You have entered: %d\n", decimal_num);
    if (decimal_num < 0) {
        decimal_num = abs(decimal_num);  // if negative value, convert to positive
        printf("Negative value was provided, converted to positive: %d\n", decimal_num);
    }
    int i, result, result_remainder, binary_num[32];
    while (decimal_num > 0) {
        result = decimal_num / 2;
        result_remainder = decimal_num % 2;
        printf("%d / 2 = %d R %d\n", decimal_num, result, result_remainder);
        decimal_num = result;
        binary_num[i] = result_remainder;
        i++;
    }
    for (int c = i - 1; c >= 0; c--)  // print in reverse
        printf("%d", binary_num[c]);
    putchar('\n');
    return 0;
}
