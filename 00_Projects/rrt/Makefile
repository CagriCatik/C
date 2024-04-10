CC = gcc
CFLAGS = -Wall -Wextra -I./include

SRCS = src/rrt.c src/main.c
OBJS = $(SRCS:.c=.o)

all: rrt

rrt: $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(OBJS) rrt
