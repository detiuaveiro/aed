CC=gcc
CFLAGS=-Wall -std=c17

LIBS=-lrt -lm

TARGETS= ex01

all: $(TARGETS)

ex01: ex01.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)
