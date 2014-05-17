default: same_tree
WORK=same_tree 
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=reverse_word_in_string evaluate_rpn single_number max_depth_tree same_tree

all: $(PROGRAM)
reverse_word_in_string: reverse_word_in_string.cpp
	$(CC) $(CFLAGS) $< -o $@

evaluate_rpn: evaluate_rpn.cpp
	$(CC) $(CFLAGS) $< -o $@

single_number: single_number.cpp
	$(CC) $(CFLAGS) $< -o $@

max_depth_tree: max_depth_tree.cpp
	$(CC) $(CFLAGS) $< -o $@

same_tree: same_tree.cpp
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(WORK)	
