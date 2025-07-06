# Command Line Arguments 

 In this tutorial, we'll cover what command line arguments are, how to use them in your C programs, and provide detailed code snippets for better understanding.

## Introduction to Command Line Arguments

Command line arguments are a way to pass data to your C program when it's executed from the command line. Instead of prompting the user to input data while the program is running, you can specify this data directly in the command line when executing the program.

### Why Use Command Line Arguments?

- **Dynamic Input:** Command line arguments allow dynamic input to the program without requiring user interaction during runtime.
- **Flexibility:** It provides flexibility in providing input data without modifying the source code.
- **Automation:** Useful for automation and scripting tasks.

Now, let's delve into the details of how to work with command line arguments in C.

## Understanding Command Line Arguments

In C programming, the `main` function serves as the entry point for the program. It can receive command line arguments when the program is invoked. Let's understand the parameters of the `main` function:

```c
int main(int argc, char *argv[])
```

Here, `argc` represents the argument count, i.e., the number of arguments passed to the program, and `argv` is an array of character pointers (`char*`) containing the actual arguments.

- `argc`: An integer value specifying the number of arguments typed at the command line.
- `argv`: An array of character pointers where each pointer points to a string representing an argument.

### Code Example:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Displaying the number of arguments
    printf("Number of arguments: %d\n", argc);

    // Displaying each argument
    for (int i = 0; i < argc; ++i) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```

## Using Command Line Arguments in C Programs

Now, let's see how we can use command line arguments in a C program. We'll demonstrate passing and accessing command line arguments through a simple example.

### Example Program:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Displaying the number of arguments
    printf("Number of arguments: %d\n", argc);

    // Displaying each argument
    for (int i = 0; i < argc; ++i) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```

### Explanation:

1. The `main` function accepts two parameters: `argc` and `argv`.
2. `argc` stores the count of command line arguments passed to the program.
3. `argv` is an array containing pointers to strings, where each string represents a command line argument.
4. The program iterates over each argument and prints its index and value using a `for` loop.

## Executing C Programs with Command Line Arguments

To execute a C program with command line arguments, follow these steps:

1. Compile the program using a C compiler (e.g., GCC).
2. Open the terminal or command prompt.
3. Navigate to the directory containing the compiled executable.
4. Execute the program followed by the desired command line arguments.

### Example (Linux/Unix):

```bash
./program_name arg1 arg2 arg3
```

### Example (Windows):

```cmd
program_name.exe arg1 arg2 arg3
```

Command line arguments provide a convenient way to pass data to C programs during execution. By utilizing command line arguments, you can create more flexible and versatile applications. This tutorial covered the basics of working with command line arguments in C programming, including syntax, usage, and examples.
