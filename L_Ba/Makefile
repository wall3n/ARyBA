all: directorio programa generador

directorio: 
	mkdir -p build 

programa: build/main.o build/backtracking.o
	g++ build/main.o build/backtracking.o -o programa

generador: build/generador.o build/backtracking.o
	g++ build/generador.o build/backtracking.o -o generador

build/main.o: src/main.cpp src/backtracking.hpp
	g++ -c src/main.cpp -o build/main.o

build/generador.o: src/generador-casos.cpp src/backtracking.hpp
	g++ -c src/generador-casos.cpp -o build/generador.o

build/backtracking.o: src/backtracking.cpp src/backtracking.hpp
	g++ -c src/backtracking.cpp -o build/backtracking.o

clean:
	rm -fr build/*.o programa generador

