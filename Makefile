CC = gcc
CFLAGS = -Wall
TARGET = system

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean: 
	$(RM) $(TARGET)