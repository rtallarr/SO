CC = gcc
CFLAGS = -Wall
TARGET = mono

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	./mono

clean: 
	$(RM) $(TARGET)