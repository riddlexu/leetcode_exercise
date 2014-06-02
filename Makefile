Default: swap_node_pair
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=swap_node_pair

swap_node_pair: swap_node_pair.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

