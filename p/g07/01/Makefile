EXECUTABLE = 01_example

CC = gcc
CFLAGS=-Wall -std=c17
LIBS=-lm

src = $(wildcard *.c)
obj = $(src:.c=.o)

all: prog

prog: $(obj)
	$(CC) -o $(EXECUTABLE) $^ $(LIBS)

.PHONY: clean
clean:
	rm $(obj) $(EXECUTABLE)