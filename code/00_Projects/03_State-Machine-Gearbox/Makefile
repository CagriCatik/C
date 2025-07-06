CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJS = main.o gearbox.o

all: gearbox_sm

gearbox_sm: $(OBJS)
	$(CC) $(CFLAGS) -o gearbox_sm $(OBJS)

main.o: main.c gearbox.h
	$(CC) $(CFLAGS) -c main.c

gearbox.o: gearbox.c gearbox.h
	$(CC) $(CFLAGS) -c gearbox.c

clean:
	rm -f gearbox_sm *.o
