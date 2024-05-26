#include <stdio.h>
#include <stdlib.h>

int main() {
    // Example using malloc
    int *ptr1;
    ptr1 = (int*) malloc(5 * sizeof(int)); // Allocate memory for 5 integers

    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and print values
    printf("Using malloc:\n");
    for (int i = 0; i < 5; i++) {
        ptr1[i] = i + 1;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Example using calloc
    int *ptr2;
    ptr2 = (int*) calloc(5, sizeof(int)); // Allocate memory for 5 integers and initialize to 0

    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print values
    printf("Using calloc:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    // Example using realloc
    ptr1 = (int*) realloc(ptr1, 10 * sizeof(int)); // Resize memory for 10 integers

    if (ptr1 == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initialize and print additional values
    printf("Using realloc:\n");
    for (int i = 5; i < 10; i++) {
        ptr1[i] = i + 1;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ptr1);
    free(ptr2);

    return 0;
}
