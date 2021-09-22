CC = gcc
CFLAGS = -Wall
TARGET = system

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	./$(TARGET)

clean: 
	$(RM) $(TARGET)
	rmdir 1 2 3