Default: construct_tree_post
CC=g++
CFLAGS=-Wall -std=c++11 -g
PROGRAM=construct_tree_post

construct_tree_post: construct_tree_post.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm $(PROGRAM)	

