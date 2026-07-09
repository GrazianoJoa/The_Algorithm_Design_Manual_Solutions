CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Busca en src/ y también en src/ds/ de forma segura
SRC = $(wildcard src/*.c) $(wildcard src/ds/*.c)
TEST_SRC = $(wildcard test/*.c) $(wildcard test/ds/*.c)
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

TARGET = app
TEST_TARGET = run_test

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(OBJ)
	$(CC) $(TEST_OBJ) $(filter-out src/main.o, $(OBJ)) -o $(TEST_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
