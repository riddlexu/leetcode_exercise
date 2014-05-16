default: evaluate_rpn
CC=g++
CFLAGS=-O3 -Wall
PROGRAM=reverse_word_in_string evaluate_rpn

all: $(PROGRAM)
reverse_word_in_string: reverse_word_in_string.cpp
	$(CC) $(CFLAGS) $< -o $@

evaluate_rpn: evaluate_rpn.cpp
	$(CC) $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(PROGRAM)	
