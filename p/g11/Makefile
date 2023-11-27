# To compile all programs, run:
#   make
#
# AED ua.pt 2023

# Options for the C compiler.
CFLAGS += -g -Wall -Wextra

TARGETS = MinHeapTest TopKValues FileMerge KLongestWords

all: $(TARGETS)

# Object file dependencies (obtained with `gcc -MM *.c`):

FileMerge.o: FileMerge.c FileReader.h MinHeap.h
FileReader.o: FileReader.c FileReader.h
HashTable.o: HashTable.c HashTable.h
KLongestWords.o: KLongestWords.c HashTable.h MinHeap.h
MinHeap.o: MinHeap.c MinHeap.h
MinHeapTest.o: MinHeapTest.c MinHeap.h
TopKValues.o: TopKValues.c MinHeap.h

# Executable file dependencies:

MinHeapTest: MinHeapTest.o MinHeap.o

FileMerge: FileMerge.o MinHeap.o FileReader.o

TopKValues: TopKValues.o MinHeap.o

KLongestWords: KLongestWords.o HashTable.o MinHeap.o

file%.txt:
	@# Generate a sample file with % sorted lines taken from word list
	cat /etc/dictionaries-common/words | \
	grep -v "'" | tr '[:upper:]' '[:lower:]' | \
	shuf -n $* - | \
	LC_ALL=C sort -o $@

clean:
	rm -f *.o
	rm -f $(TARGETS)
