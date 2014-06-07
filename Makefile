Default: jump_game
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=jump_game

jump_game: jump_game.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

