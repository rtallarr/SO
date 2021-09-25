CC = gcc
CFLAGS = -Wall
TARGET = laberinto
TARGET2 = buscador

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	./$(TARGET)

$(TARGET2): $(TARGET2).c
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).c
	./$(TARGET2)

clean: 
	$(RM) $(TARGET)
	rm -r 1 2 3

dir:
	rm -r 1 2 3