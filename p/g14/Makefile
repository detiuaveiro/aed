# To compile all programs, run:
#   make
#
# AED, ua, 2023

CC = g++
CFLAGS += -g -std=c++17 -Wall -Wextra -lm
CPPFLAGS = $(CFLAGS)

TARGETS = ex_1_vector ex_2_vector

all: $(TARGETS)

ex_1_vector: ex_1_vector.o
	$(CC) $(CFLAGS) -o $@ $<

ex_2_vector: ex_2_vector.o
	$(CC) $(CFLAGS) -o $@ $<

# Dependencies of source files 

ex_1_vector.o: ex_1_vector.cpp

ex_2_vector.o: ex_2_vector.cpp

clean:
	rm -f *.o
	rm -f $(TARGETS)


