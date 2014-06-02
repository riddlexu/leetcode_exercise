Default: search_insert_pos
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=search_insert_pos

search_insert_pos: search_insert_pos.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

