#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNum;

    // Seed the random number generator
    srand(time(NULL));

    // Generate and print 5 random numbers
    printf("Random numbers: ");
    for (int i = 0; i < 5; i++) {
        randomNum = rand() % 100; // Generate a random number between 0 and 99
        printf("%d ", randomNum);
    }
    printf("\n");

    return 0;
}
