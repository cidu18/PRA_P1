# Regla principal: Compila el ejecutable usando el .cpp de la clase y el del test
bin/p2d: p2h.cpp p2d.h
	mkdir -p bin
	g++ -std=c++11 -Wall p2h.cpp -o bin/p2d

# Regla para limpiar los binarios
clean:
	rm -rf bin
