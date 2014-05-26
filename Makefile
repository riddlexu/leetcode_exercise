Default: pow
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=pow

pow: pow.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

