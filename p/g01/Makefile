CC=gcc
CFLAGS=-Wall -std=c11

LIBS=-lm

TARGETS=simplest simplest_1 warnings ex04 hello hello_X table ex06

all: $(TARGETS)

simplest: simplest.c
	$(CC) $(CFLAGS) -o $@ $<

simplest_1: simplest_1.c
	$(CC) $(CFLAGS) -o $@ $<

warnings: warnings.c
	$(CC) $(CFLAGS) -o $@ $<

ex04: ex04.c
	$(CC) $(CFLAGS) -o $@ $<

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

hello_X: hello_X.c
	$(CC) $(CFLAGS) -o $@ $<

table: table.c
	$(CC) $(CFLAGS) -o $@ $< ${LIBS}

ex06: ex06.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)

