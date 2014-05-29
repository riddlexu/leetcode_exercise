Default: min_depth_tree
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=min_depth_tree

min_depth_tree: min_depth_tree.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

