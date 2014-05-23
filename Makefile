Default: merge_sorted_array
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=merge_sorted_array

merge_sorted_array: merge_sorted_array.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

