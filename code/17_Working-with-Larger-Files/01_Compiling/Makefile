# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Target executable
TARGET = myprogram

# Source files
SRCS = mod1.c mod2.c main.c

# Object files (replace .c with .o in source file names)
OBJS = $(SRCS:.c=.o)

# Default rule to build the program
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild the project from scratch
rebuild: clean all
