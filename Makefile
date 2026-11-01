C = gcc
CFLAGS = -std=c23 -Wall -Wextra -pedantic -O2

SRC = $(wildcard *.c)
HEAD = $(wildcard *.h)
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main

all: $(TARGET)

$(TARGET): $(SRC) $(HEAD)
	mkdir -p $(BUILD_DIR)
	$(C) $(CFLAGS) -o $@ $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
