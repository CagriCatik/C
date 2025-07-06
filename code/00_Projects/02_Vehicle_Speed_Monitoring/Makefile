CC = gcc
CFLAGS = -Wall -g
TARGET = speed_monitor
OBJS = main.o speed_sensor.o alert_system.o display.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
