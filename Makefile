Default: valid_parenthese
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=valid_parenthese

valid_parenthese: valid_parenthese.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

