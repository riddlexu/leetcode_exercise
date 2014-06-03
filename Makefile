Default: remove_duplicate_from_list_second
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=remove_duplicate_from_list_second

remove_duplicate_from_list_second: remove_duplicate_from_list_second.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

