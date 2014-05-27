Default: sqrt
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=sqrt

sqrt: sqrt.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

