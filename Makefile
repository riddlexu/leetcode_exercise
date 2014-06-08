Default: level_traversal_two
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=level_traversal_two

level_traversal_two: level_traversal_two.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

