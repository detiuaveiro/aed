CC=gcc
CFLAGS=-Wall -std=c17

LIBS=-lrt

TARGETS= functions_iterations_count functions_timing ex03

all: $(TARGETS)

functions_iterations_count: functions_iterations_count.c
	$(CC) $(CFLAGS) -o $@ $<

functions_timing: functions_timing.c
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200112 $(LIBS) -o $@ $<

ex03: ex03.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGETS)

