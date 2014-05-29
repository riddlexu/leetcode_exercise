Default: level_zigzag_traversal
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=level_zigzag_traversal

level_zigzag_traversal: level_zigzag_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

