# Regla principal: Compila el ejecutable usando el .cpp de la clase y el del test
bin/p2d: p2h.cpp p2d.h
	mkdir -p bin
	g++ -std=c++11 -Wall p2h.cpp -o bin/p2d
bin/testShape: testShape.cpp Shape.h
	mkdir -p bin
	g++ -std=c++11 -Wall testShape.cpp -o bin/testShape
bin/testCircle: testCircle.cpp Circle.h Shape.h p2d.h
	mkdir -p bin
	g++ -std=c++11 -Wall testCircle.cpp -o bin/testCircle
bin/testRectangle: testRectangle.cpp Rectangle.h Shape.h
	mkdir -p bin
	g++ -std=c++11 -Wall testRectangle.cpp -o bin/testRectangle
clean:
	rm -rf bin:
