# Standard C Library Functions

The Standard C Library, also known as the C Standard Library or libc, is a collection of functions and macros that are part of the C programming language standard. These functions provide a wide range of capabilities, including input/output operations, string manipulation, memory management, mathematical operations, date and time handling, and more. Understanding and utilizing these library functions is essential for writing efficient and portable C programs.

In this tutorial, we'll explore the major functionalities of the Standard C Library, covering various headers and their associated functions.

## Table of Contents

1. [Input/Output Operations (stdio.h)](#inputoutput-operations-stdioh)
2. [String Manipulation (string.h)](#string-manipulation-stringh)
3. [Dynamic Memory Management (stdlib.h)](#dynamic-memory-management-stdlibh)
4. [Mathematical Functions (math.h)](#mathematical-functions-mathh)
5. [Date and Time Handling (time.h)](#date-and-time-handling-timeh)
6. [Random Number Generation (stdlib.h)](#random-number-generation-stdlibh)
7. [Error Handling (errno.h)](#error-handling-errnoh)

### 1. Input/Output Operations (stdio.h)

The `stdio.h` header provides functions for standard input and output operations. Key functions include `printf`, `scanf`, `fopen`, `fclose`, `fread`, `fwrite`, `fprintf`, and `fscanf`. These functions are used for printing to the console, reading input from the console, and reading/writing files.

```c
#include <stdio.h>

int main() {
    printf("Hello, world!\n");

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("You entered: %d\n", num);

    FILE *file = fopen("example.txt", "w");
    fprintf(file, "This is an example.");
    fclose(file);

    return 0;
}
```

### 2. String Manipulation (string.h)

The `string.h` header provides functions for manipulating strings. Key functions include `strlen`, `strcpy`, `strcat`, `strcmp`, `strchr`, `strstr`, and `strtok`. These functions are used for calculating string length, copying, concatenating, comparing, searching, and tokenizing strings.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    printf("Length of str1: %d\n", strlen(str1));
    printf("Concatenated string: %s\n", strcat(str1, str2));

    return 0;
}
```

### 3. Dynamic Memory Management (stdlib.h)

The `stdlib.h` header provides functions for dynamic memory management. Key functions include `malloc`, `calloc`, `realloc`, and `free`. These functions are used for allocating and deallocating memory dynamically during program execution.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
```

### 4. Mathematical Functions (math.h)

The `math.h` header provides functions for mathematical operations. Key functions include `sqrt`, `pow`, `sin`, `cos`, `tan`, `log`, and `exp`. These functions are used for performing common mathematical calculations.

```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("Square root of 16: %.2f\n", sqrt(16));
    printf("Logarithm of 10: %.2f\n", log(10));
    return 0;
}
```

### 5. Date and Time Handling (time.h)

The `time.h` header provides functions for date and time handling. Key functions include `time`, `localtime`, `strftime`, `ctime`, `difftime`, and `mktime`. These functions are used for obtaining current time, converting time formats, and calculating time differences.

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL);
    printf("Current time: %s", ctime(&currentTime));
    return 0;
}
```

### 6. Random Number Generation (stdlib.h)

The `stdlib.h` header provides functions for generating pseudo-random numbers. Key functions include `rand` and `srand`. These functions are used for generating random integers within a specified range.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Random number: %d\n", rand() % 100);
    return 0;
}
```

### 7. Error Handling (errno.h)

The `errno.h` header provides error handling macros and global variable `errno`. Key macros include `errno`, `perror`, and `strerror`. These macros are used for identifying and printing error messages during program execution.

```c
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        perror("Error");
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }
    fclose(file);
    return 0;
}
```

## Conclusion

In this tutorial, we've covered the major functionalities of the Standard C Library, including input/output operations, string manipulation, dynamic memory management, mathematical operations, date and time handling, random number generation, and error handling. Understanding and utilizing these library functions are essential for writing efficient and portable C programs. Further exploration of these functions will greatly enhance your C programming skills.
