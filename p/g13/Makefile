# To compile all programs, run:
#   make
#
# AED, ua, 2023

CC = g++
CFLAGS += -g -std=c++17 -Wall -Wextra -lm
CPPFLAGS = $(CFLAGS)

TARGETS = PointTest CircleTest RectangleTest SquareTest FiguresTest

all: $(TARGETS)

PointTest: PointTest.o Point.o
	$(CC) $(CFLAGS) PointTest.o Point.o -o PointTest

CircleTest: CircleTest.o Circle.o Figure.o Point.o
	$(CC) $(CFLAGS) CircleTest.o Circle.o Figure.o Point.o -o CircleTest

RectangleTest: RectangleTest.o Rectangle.o Figure.o Point.o
	$(CC) $(CFLAGS) RectangleTest.o Rectangle.o Figure.o Point.o -o RectangleTest

SquareTest: SquareTest.o Square.o Rectangle.o Figure.o Point.o
	$(CC) $(CFLAGS) SquareTest.o Square.o Rectangle.o Figure.o Point.o -o SquareTest

FiguresTest: FiguresTest.o Square.o Rectangle.o Circle.o Figure.o Point.o
	$(CC) $(CFLAGS) FiguresTest.o Square.o Rectangle.o Circle.o Figure.o Point.o -o FiguresTest

# Dependencies of source files 

PointTest.o: PointTest.cpp Point.h

CircleTest.o: CircleTest.cpp Circle.h Figure.h Point.h

RectangleTest.o: RectangleTest.cpp Rectangle.h Figure.h Point.h

SquareTest.o: SquareTest.cpp Square.h Rectangle.h Figure.h Point.h

FiguresTest.o: FiguresTest.cpp Square.h Rectangle.h Circle.h Figure.h Point.h

clean:
	rm -f *.o
	rm -f $(TARGETS)


