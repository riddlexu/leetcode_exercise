Default: rotate_image
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=rotate_image

rotate_image: rotate_image.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

