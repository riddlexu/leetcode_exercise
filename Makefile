Default: linked_list_cycle
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=linked_list_cycle

linked_list_cycle: linked_list_cycle.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

