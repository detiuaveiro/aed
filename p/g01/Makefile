CC=gcc
CFLAGS=-Wall -std=c11

LIBS=-lm

TARGETS=simplest warnings hello hello_X table

all: $(TARGETS)

simplest: simplest.c
	$(CC) $(CFLAGS) -o $@ $<

warnings: warnings.c
	$(CC) $(CFLAGS) -o $@ $<

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

hello_X: hello_X.c
	$(CC) $(CFLAGS) -o $@ $<

table: table.c
	$(CC) $(CFLAGS) -o $@ $< ${LIBS}

.PHONY: clean
clean:
	rm -f $(TARGETS)

