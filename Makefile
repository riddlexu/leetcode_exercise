Default: linked_list_cycle_2
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=linked_list_cycle_2

linked_list_cycle_2: linked_list_cycle_2.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

