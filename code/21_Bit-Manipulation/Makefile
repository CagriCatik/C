CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o binary_operations.o bit_fields.o

all: bit_utility

bit_utility: $(OBJS)
	$(CC) $(CFLAGS) -o bit_utility $(OBJS)

main.o: main.c binary_operations.h bit_fields.h
	$(CC) $(CFLAGS) -c main.c

binary_operations.o: binary_operations.c binary_operations.h
	$(CC) $(CFLAGS) -c binary_operations.c

bit_fields.o: bit_fields.c bit_fields.h
	$(CC) $(CFLAGS) -c bit_fields.c

clean:
	rm -f bit_utility *.o
