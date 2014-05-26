Default: level_traversal
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=level_traversal

level_traversal: level_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

