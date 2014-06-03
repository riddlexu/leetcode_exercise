Default: remove_duplicate_second
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=remove_duplicate_second

remove_duplicate_second: remove_duplicate_second.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

