Default: symmetric_tree
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=symmetric_tree

symmetric_tree: symmetric_tree.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

