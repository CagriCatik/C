#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Size of the array
    const int size = 10000;

    // Create and initialize an array with random integers
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }

    // Record the starting time
    clock_t start = clock();

    // Sort the array using quicksort algorithm
    quicksort(arr, 0, size - 1);

    // Record the ending time
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution time of sorting %d integers: %f seconds\n", size, time_taken);

    return 0;
}
