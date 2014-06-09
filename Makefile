Default: combinations
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=combinations

combinations: combinations.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

