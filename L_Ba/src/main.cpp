#include "backtracking.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

using namespace std;

vector<string> tallas = {"XXL", "XL", "L", "M", "S", "XS"};

int main() {
    int opcion;

    do {
        cout << "========================" << endl;
        cout << "         MENU" << endl;
        cout << "========================" << endl;
        cout << "1. Probar Backtracking" << endl;
        cout << "2. Ayuda" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if(opcion == 1){
            int N, M;
            cout << "Introduce el número total de camisetas: ";
            cin >> N;
            cout << "Introduce el número de voluntarios: ";
            cin >> M;

			vector<PosiblesTallas> tallas(M + 1);
			vector<int> disponibles(NUM_TALLAS, N / NUM_TALLAS);
			
			cout << "A continuación debe introducir "<< M << " líneas de las dos tallas separadas por un espacio: "<<endl;
			for (int i = 1; i <= M; ++i) {
				string t1, t2;
				cin >> t1 >> t2;
				tallas[i].t1 = asignaTalla(t1);
				tallas[i].t2 = asignaTalla(t2);
			}

			if (backtracking(M, tallas, disponibles)) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
        }

        if(opcion == 2){
            cout << "=================================================" << endl;
            cout << "              MENU DE AYUDA" << endl;
            cout << "=================================================" << endl;
            cout << "El formato de entrada del programa es el siguiente:" << endl;
            cout << "1) La primera línea es el número total de casos de prueba." << endl;
            cout << "2) Luego dos números separados por espacio: número de camisetas (N) y voluntarios (M)." << endl;
            cout << "3) Después, M líneas con las 2 tallas que prefiere cada voluntario (XXL, XL, L, M, S o XS)." << endl;
            cout << "=================================================" << endl;
        }

        if(opcion == 3){
            cout << "Saliendo..." << endl;
        }

        cout << endl;

    } while (opcion != 3);

    return 0;
}
