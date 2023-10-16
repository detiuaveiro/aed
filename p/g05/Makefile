CC=gcc
CFLAGS=-Wall -std=c17

LIBS=-lrt -lm

TARGETS= ex01 ex02 ex03

all: $(TARGETS)

ex01: ex01.c
	$(CC) $(CFLAGS) -o $@ $<

ex02: ex02.c
	$(CC) $(CFLAGS) -o $@ $<

ex03: ex03.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)
