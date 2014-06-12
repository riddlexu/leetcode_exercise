Default: construct_tree_prev
CC=g++
CFLAGS=-Wall -std=c++11 -g
PROGRAM=construct_tree_prev

construct_tree_prev: construct_tree_prev.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

