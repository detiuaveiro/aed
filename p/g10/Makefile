# To compile all programs, run:
#   make
#
# AlgC ua.pt 2021

# Options for the C compiler.
CFLAGS += -g -Wall

TARGETS = BSTreeTest Tests

all: $(TARGETS)

clean:
	rm -f *.o
	rm -f $(TARGETS)

# Object file dependencies (obtained with `gcc -MM *.c`):

BSTree.o: BSTree.c BSTree.h PointersQueue.h
BSTreeTest.o: BSTreeTest.c BSTree.h PointersQueue.h
Date.o: Date.c Date.h
Person.o: Person.c Person.h Date.h
PersonSet.o: PersonSet.c PersonSet.h Person.h Date.h BSTree.h PointersQueue.h
PointersQueue.o: PointersQueue.c PointersQueue.h
Tests.o: Tests.c Person.h Date.h PersonSet.h

# Executable file dependencies:

BSTreeTest: BSTreeTest.o BSTree.o PointersQueue.o

Tests: Tests.o PersonSet.o BSTree.o PointersQueue.o Person.o Date.o

# make tst    # to run program twice and log outputs

tst: tst-12.txt tst-14.txt

tst-%.txt: Tests
	valgrind --log-fd=1 ./Tests $* > $@

## SPECIAL TARGETS BELOW //HIDE

# Source files for CodeCheck
SRCS = $(wildcard ./*.c ./*.h)

# Source files for student skel
SKELSRCS = $(SRCS) $(wildcard ./*.txt ./Makefile)

ALL: codecheck skel.zip

skel: skel/ $(subst ./,skel/,$(SKELSRCS))
	#nop

skel/:
	rm -rf $@/*
	install -d $@

skel/%: %
	sed -f filter.sed $< > $@

cc.zip: $(SRCS)
	rm -f $@
	zip -r $@ $^

codecheck: cc.zip

skel.zip: skel
	rm -f $@
	#ln -sf skel $(@:.zip=)
	zip -jr $@ $^
	#rm -f $(@:.zip=)

REF: ref-12.txt ref-14.txt

ref-%.txt: Tests
	valgrind --log-fd=1 ./Tests $* > $@

