// Enter a PIN number of any length (e.g., 0021), then brute force it.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int get_digits_amount(int num) {
    // Get literal amount of digits.
    // E.g., 9 returns 1, 99 returns 2, 999 returns 3 and 9,999 returns 4.
    return floor(log10(num)) + 1;
}

int get_max_value_for_digit_amount(int amount) {
    // Get maximum possible value for a given amount of digits.
    // E.g., 1 returns 10, 2 returns 100, 3 returns 1,000 and 4 returns 10,000.
    if (amount == 1) {
        return 10;
    }
    return pow(10, amount);
}

int main(void) {
    int answer, leading, trailing;
    printf("Enter a PIN number: ");
    if (scanf("%n%d%n", &leading, &answer, &trailing) != 1) {
        puts("Not an integer.");
        return -1;
    }
    answer = abs(answer);                                // no negative values
    int total_digits_amount = trailing - leading;        // 0032 = 4 digits
    int valid_digits_amount = get_digits_amount(answer); // 0032 = 2 digits
    int possible_combinations = pow(10, valid_digits_amount);
    int max_loop_value = get_max_value_for_digit_amount(valid_digits_amount);
    printf("OK: Received PIN to guess: %0*d (%d total digits, %d valid digits, "
           "%d possible combinations, max loop value for digits: %d)\n",
           total_digits_amount, answer, total_digits_amount,
           valid_digits_amount, possible_combinations, max_loop_value);
    char yesno;
    printf("Proceed? [y/n]: ");
    scanf(" %c", &yesno); // skip whitespace after previous scanf()
    if (yesno == 'n') {
        puts("Exit.");
        return 0;
    }
    int guess;
    for (guess = 0; guess < max_loop_value; guess++) {
        if (guess == answer) {
            printf("<- Correct: %0*d\n", total_digits_amount, guess);
            break;
        }
        printf("-> Wrong: %0*d\n", total_digits_amount, guess);
    }
    printf("The PIN was: %0*d\n", total_digits_amount, guess);
    return 0;
}
