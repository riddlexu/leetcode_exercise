Default: spiral_matrix
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=spiral_matrix

spiral_matrix: spiral_matrix.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

