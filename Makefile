Default: generate_parenteses
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=generate_parenteses

generate_parenteses: generate_parenteses.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

