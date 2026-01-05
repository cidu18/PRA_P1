# Variables para simplificar
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I..

# Regla para Drawing (incluye el flag -I.. para encontrar List.h y ListLinked.h)
bin/testDrawing: testDrawing.cpp Drawing.h Rectangle.h Shape.h Square.h Circle.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testDrawing.cpp -o bin/testDrawing

# Regla para Square
bin/testSquare: testSquare.cpp Rectangle.h Shape.h Square.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testSquare.cpp -o bin/testSquare

# Regla para Rectangle
bin/testRectangle: testRectangle.cpp Rectangle.h Shape.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testRectangle.cpp -o bin/testRectangle

# Regla para Circle
bin/testCircle: testCircle.cpp Circle.h Shape.h p2d.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testCircle.cpp -o bin/testCircle

clean:
	rm -rf bin# Variables para simplificar
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I..

# Regla para Drawing (incluye el flag -I.. para encontrar List.h y ListLinked.h)
bin/testDrawing: testDrawing.cpp Drawing.h Rectangle.h Shape.h Square.h Circle.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testDrawing.cpp -o bin/testDrawing

# Regla para Square
bin/testSquare: testSquare.cpp Rectangle.h Shape.h Square.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testSquare.cpp -o bin/testSquare

# Regla para Rectangle
bin/testRectangle: testRectangle.cpp Rectangle.h Shape.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testRectangle.cpp -o bin/testRectangle

# Regla para Circle
bin/testCircle: testCircle.cpp Circle.h Shape.h p2d.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) testCircle.cpp -o bin/testCircle

clean:
	rm -rf bin
