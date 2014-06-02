Default: remove_element
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=remove_element

remove_element: remove_element.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

