# Makefile

# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -ldl

# Define the targets
all: main

main: main.o plugin.so
	$(CC) -o main main.o $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

plugin.so: plugin.c
	$(CC) $(CFLAGS) -shared -o plugin.so plugin.c

clean:
	rm -f main main.o plugin.so
