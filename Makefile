CC = gcc
CFLAGS = -Wall -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = libds.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

test: all
	$(CC) $(CFLAGS) test/test_main.c -L. -lds -o test_main
	./test_main

clean:
	rm -f src/*.o $(TARGET) test_main
