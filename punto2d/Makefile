all: bin/testp2d bin/testCircle bin/testRectangle bin/testSquare bin/testDrawing

bin/testp2d: testp2d.o p2d.o
	mkdir -p bin
	g++ testp2d.o p2d.o -o bin/testp2d

bin/testDrawing: testDrawing.o Drawing.o Square.o Circle.o Rectangle.o Shape.o p2d.o
	mkdir -p bin
	g++ testDrawing.o Drawing.o Square.o Circle.o Rectangle.o Shape.o p2d.o -o bin/testDrawing

bin/testCircle: testCircle.o Circle.o Shape.o p2d.o
	mkdir -p bin
	g++ testCircle.o Circle.o Shape.o p2d.o -o bin/testCircle

bin/testRectangle: testRectangle.o Rectangle.o Shape.o p2d.o
	mkdir -p bin
	g++ testRectangle.o Rectangle.o Shape.o p2d.o -o bin/testRectangle

bin/testSquare: testSquare.o Square.o Rectangle.o Shape.o p2d.o
	mkdir -p bin
	g++ testSquare.o Square.o Rectangle.o Shape.o p2d.o -o bin/testSquare

testp2d.o: testp2d.cpp p2d.h
	g++ -c testp2d.cpp

testDrawing.o: testDrawing.cpp Drawing.h Square.h Circle.h Rectangle.h Shape.h
	g++ -c testDrawing.cpp

testCircle.o: testCircle.cpp Circle.h Shape.h p2d.h
	g++ -c testCircle.cpp

testRectangle.o: testRectangle.cpp Rectangle.h Shape.h p2d.h
	g++ -c testRectangle.cpp

testSquare.o: testSquare.cpp Square.h Rectangle.h Shape.h p2d.h
	g++ -c testSquare.cpp

Drawing.o: Drawing.cpp Drawing.h Shape.h
	g++ -c Drawing.cpp

Square.o: Square.cpp Square.h Rectangle.h Shape.h
	g++ -c Square.cpp

Circle.o: Circle.cpp Circle.h Shape.h
	g++ -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h
	g++ -c Rectangle.cpp

Shape.o: Shape.cpp Shape.h p2d.h
	g++ -c Shape.cpp

p2d.o: p2d.cpp p2d.h
	g++ -c p2d.cpp

clean:
	rm -rf bin *.o
