# Compiler and flags
CC = gcc
CFLAGS = -Wall -ansi -pedantic

# Program name
TARGET = magic

# Source files
SRC = magic.c magic_utils.c
HEADERS = magic_utils.h

# Object files (automatically derived from sources)
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
