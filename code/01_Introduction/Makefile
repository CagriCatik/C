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
