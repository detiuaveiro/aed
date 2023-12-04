# To compile all programs, run:
#   make
#
# AED, ua, 2023

CFLAGS += -g -Wall -Wextra

TARGETS = example1 example2 example3

all: $(TARGETS)

example1: example1.o Graph.o SortedList.o

example2: example2.o Graph.o GraphDFSRec.o IntegersStack.o SortedList.o

example3: example3.o Graph.o GraphBFSWithQueue.o IntegersStack.o \
 IntegersQueue.o GraphDFSRec.o GraphDFSWithStack.o SortedList.o

# Dependencies of source files (obtained with gcc -MM)

example1.o: example1.c Graph.h

example2.o: example2.c Graph.h GraphDFSRec.h 

example3.o: example2.c Graph.h GraphBFSWithQueue.h IntegersStack.h \
 GraphDFSRec.h GraphDFSWithStack.h

Graph.o: Graph.c Graph.h SortedList.h

GraphBFSWithQueue.o: GraphBFSWithQueue.c GraphBFSWithQueue.h Graph.h \
 IntegersStack.h IntegersQueue.h

GraphDFSRec.o: GraphDFSRec.c GraphDFSRec.h Graph.h IntegersStack.h

GraphDFSWithStack.o: GraphDFSWithStack.c GraphDFSWithStack.h Graph.h \
 IntegersStack.h

IntegersQueue.o: IntegersQueue.c IntegersQueue.h

IntegersStack.o: IntegersStack.c IntegersStack.h

SortedList.o: SortedList.c SortedList.h

clean:
	rm -f *.o
	rm -f $(TARGETS)


