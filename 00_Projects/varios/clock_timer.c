#include <stdio.h>
#include <time.h>

int main() {
    // Record the starting time
    clock_t start = clock();

    // Your code goes here
    // For example, a simple loop for demonstration
    for (int i = 0; i < 1000000; ++i) {
        // Do some computations
    }

    // Record the ending time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}
