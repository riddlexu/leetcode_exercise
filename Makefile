default: all
CC=g++
CFLAGS=-O3 -Wall
PROGRAM=reverse_word_in_string

all: $(PROGRAM)
half: half.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	
