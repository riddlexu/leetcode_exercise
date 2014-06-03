Default: remove_duplicate_from_list
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=remove_duplicate_from_list

remove_duplicate_from_list: remove_duplicate_from_list.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

