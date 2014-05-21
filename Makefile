default: postorder_traversal
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=postorder_traversal

postorder_traversal: postorder_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

