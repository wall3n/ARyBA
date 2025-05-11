all: directorio programa generador

directorio: 
	mkdir -p build 

programa: build/main.o build/avance-rapido.o
	g++ build/main.o build/avance-rapido.o -o programa

generador: build/generador.o build/avance-rapido.o
	g++ build/generador.o build/avance-rapido.o -o generador

build/main.o: src/main.cpp src/avance-rapido.hpp
	g++ -c src/main.cpp -o build/main.o

build/generador.o: src/generador.cpp src/avance-rapido.hpp
	g++ -c src/generador.cpp -o build/generador.o

build/avance-rapido.o: src/avance-rapido.cpp src/avance-rapido.hpp
	g++ -c src/avance-rapido.cpp -o build/avance-rapido.o

clean:
	rm -fr build/*.o programa generador

