CC = gcc
CFLAGS = -Wall
TARGET = laberinto
TARGET2 = buscador

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o lab $(TARGET).c
	./lab

$(TARGET2): $(TARGET2).c
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).c
	./$(TARGET2)

clean: 
	$(RM) lab
	$(RM) $(TARGET2)
	rm -r Laberinto/