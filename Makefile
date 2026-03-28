CC = gcc
CFLAGS = -Iinclude -Wall
SRC = src/main.c src/game.c src/logic.c src/ui.c
TARGET = tictactoe

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
