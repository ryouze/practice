// Enter a 4-digit PIN, (e.g., 0021), then brute force it.
#include <stdio.h>
#include <string.h>

int main(void) {
    char pin[5];
    char guess[5];
    fputs("Enter a 4-digit PIN to guess: ", stdout);
    if (scanf("%4s", pin) != 1) {
        puts("Invalid input.");
        return -1;
    }
    if (strlen(pin) != 4) {
        puts("Not 4 digits long.");
        return -1;
    }
    printf("You entered: %s\n", pin);
    for (int i = 0; i < 10000; i++) {
        sprintf(guess, "%0*i", 4, i);  // append leading zeros
        if (strcmp(pin, guess) == 0) {
            printf("<- Correct: %s\n", guess);

            return 0;
        }
        printf("-> Wrong: %s\n", guess);
    }
    printf("The PIN was: %s\n", pin);
    return 0;
}
