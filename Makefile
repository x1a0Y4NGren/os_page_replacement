# Member A: build script for the whole project.

CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -Iinclude
TARGET := bin/page_replacement
SRCS := src/main.c src/algorithms.c src/sequence.c src/extension.c
OBJS := $(SRCS:src/%.c=build/%.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CC) $(CFLAGS) -o $@ $(OBJS)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build bin:
	mkdir -p $@

run: all
	./$(TARGET)

clean:
	rm -rf build bin
