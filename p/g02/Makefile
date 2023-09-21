CC=gcc
CFLAGS=-Wall -std=c11

LIBS=-lm

TARGETS=integer_arithmetic_pitfalls ex02 ex03

all: $(TARGETS)

ex02: ex02.c
	$(CC) $(CFLAGS) -o $@ $<

ex03: ex03.c
	$(CC) $(CFLAGS) -o $@ $<

integer_arithmetic_pitfalls: integer_arithmetic_pitfalls.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)

