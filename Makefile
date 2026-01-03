# Regla principal (compila todo lo que pongas aquí)
all: bin/testListArray bin/testNode

# Regla para ListArray
bin/testListArray: testListArray.cpp ListArray.h list.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

# Regla nueva para Node
bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

# Limpieza
clean:
	rm -rf bin
