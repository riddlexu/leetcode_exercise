Default: next_permutations
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=next_permutations

next_permutations: next_permutations.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

