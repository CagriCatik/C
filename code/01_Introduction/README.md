# Workflow

## 1. Editing
First, create a file named `hello.c` and write the following code:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

## 2. Compiling
Compile the code using the following command:

```sh
gcc -c hello.c
```

## 3. Linking
Link the object file to create an executable:

```sh
gcc hello.o -o hello
```

## 4. Executing
Run the executable:

```sh
./hello
```

---

The method above is a straightforward and traditional way to compile, link, and execute a C program using GCC. However, there are a few ways to streamline and improve the process. Here are some suggestions:

## 1. Using a Single Command
You can compile and link the code in a single step by combining the commands:

```sh
gcc hello.c -o hello
```

This command tells GCC to compile `hello.c` and then link the resulting object file to create an executable named `hello`.

## 2. Adding Optimization and Debugging Information
To enable optimizations and include debugging information, you can use the following command:

```sh
gcc -O2 -g hello.c -o hello
```

Here:
- `-O2` enables optimization level 2, which makes the code run faster.
- `-g` includes debugging information, which is useful if you need to use a debugger like `gdb`.

## 3. Using Makefile for Larger Projects
For larger projects with multiple source files, it's better to use a `Makefile`. Here's a simple example:

### Makefile:
```Makefile
CC = gcc
CFLAGS = -O2 -g
TARGET = hello

all: $(TARGET)

$(TARGET): hello.o
	$(CC) $(CFLAGS) -o $(TARGET) hello.o

hello.o: hello.c
	$(CC) $(CFLAGS) -c hello.c

clean:
	rm -f *.o $(TARGET)
```

You can then use the following commands:

- Compile and link: `make`
- Clean up object files and executable: `make clean`

## 4. Automating with Shell Script
For very simple projects or quick compilation, you can use a shell script to automate the process:

### build.sh:
```sh
#!/bin/bash

gcc -O2 -g hello.c -o hello

if [ $? -eq 0 ]; then
    echo "Build successful. Running the program..."
    ./hello
else
    echo "Build failed."
fi
```

Make the script executable and run it:

```sh
chmod +x build.sh
./build.sh
```

## Summary
Using these methods, you can streamline the build process, make your code easier to maintain, and incorporate best practices for optimization and debugging. For small projects, a single command or a shell script is sufficient. For larger projects, a `Makefile` is more appropriate.