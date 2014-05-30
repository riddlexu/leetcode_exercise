Default: permutations
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=permutations

permutations: permutations.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

