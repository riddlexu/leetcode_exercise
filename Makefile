default: postorder_traversal
WORK=postorder_traversal
CC=g++
CFLAGS=-O3 -Wall -std=c++11
PROGRAM=reverse_word_in_string evaluate_rpn single_number max_depth_tree same_tree reverse_int preorder_traversal postorder_traversal

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

reverse_int: reverse_int.cpp
	$(CC) $(CFLAGS) $< -o $@

preorder_traversal: preorder_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@

postorder_traversal: postorder_traversal.cpp
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(WORK)	
