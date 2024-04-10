#include <stdio.h>

int main() {
    int num = 5;

    if (num > 0) {
        if (num % 2 == 0) {
            printf("%d is positive and even.\n", num);
        } else {
            printf("%d is positive and odd.\n", num);
        }
    } else if (num < 0) {
        printf("%d is negative.\n", num);
    } else {
        printf("%d is zero.\n", num);
    }

    return 0;
}
