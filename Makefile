Default: climb_stair
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=climb_stair

climb_stair: climb_stair.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

