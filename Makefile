Default: inorder_traversal
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=inorder_traversal

inorder_traversal: inorder_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

