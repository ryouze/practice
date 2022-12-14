/*
Compare memory addresses of two ints and two null pointers.
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void compare_ptr(int *ptr1, int *ptr2) {
    bool is_different = false;
    // check for null pointer
    if (ptr1 == NULL && ptr2 == NULL) {
        if (ptr1 == ptr2)
            is_different = true;
    } else if (*ptr1 == *ptr2)
        is_different = true;
    if (is_different)
        puts("different memory address");
    else
        puts("same memory address");
}

int main(void) {
    int *null_ptr1 = NULL;
    int *null_ptr2 = NULL;
    int int_ptr1 = 5, int_ptr2 = 2;
    puts("[1] int ptr vs. int ptr");
    compare_ptr(&int_ptr1, &int_ptr2);  // different memory address
    puts("[2] null ptr vs. null ptr");
    compare_ptr(null_ptr1, null_ptr1);  // same memory address
}
