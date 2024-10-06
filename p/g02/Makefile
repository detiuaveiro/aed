CC=gcc
CFLAGS=-Wall -std=c11 -g

LIBS=-lm

TARGETS=integer_arithmetic_pitfalls ex02 ex03 ex04 binary_search

all: $(TARGETS)

ex02: ex02.c
	$(CC) $(CFLAGS) -o $@ $<

ex03: ex03.c
	$(CC) $(CFLAGS) -o $@ $<

ex04: ex04.c
	$(CC) $(CFLAGS) -o $@ $<

integer_arithmetic_pitfalls: integer_arithmetic_pitfalls.c
	$(CC) $(CFLAGS) -Wextra -o $@ $<

binary_search: binary_search.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)

