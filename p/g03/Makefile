CC=gcc
CFLAGS=-Wall -std=c11

LIBS=-lrt -lm

TARGETS= functions_iterations_count functions_timing ex03 ex04

all: $(TARGETS)

functions_iterations_count: functions_iterations_count.c
	$(CC) $(CFLAGS) -o $@ $<

functions_timing: functions_timing.c
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200112 $(LIBS) -o $@ $<

ex03: ex03.c
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200112 $(LIBS) -o $@ $<

ex04: ex04.c
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200112 $(LIBS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)

