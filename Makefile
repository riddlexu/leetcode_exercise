Default: remove_duplicate
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=remove_duplicate

remove_duplicate: remove_duplicate.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

