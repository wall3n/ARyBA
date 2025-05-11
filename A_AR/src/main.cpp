#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

#include "avance-rapido.hpp"

using namespace std;

int main() {
    int opcion;

    do {
        cout << "========================" << endl;
        cout << "         MENU" << endl;
        cout << "========================" << endl;
        cout << "1. Probar Avance Rápido" << endl;
        cout << "2. Ayuda" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if(opcion == 1){
            ios::sync_with_stdio(false);
            cin.tie(NULL);

            int nCasos;
            cin >> nCasos;

            for(int i = 0; i < nCasos; i++){
                int nw, nt;
                cin >> nw >> nt ;

                vector<vector<int> > b(nw, vector<int>(nt));
                vector<int> c(nw);

                for(int j = 0; j < nw; j++){
                    for(int z = 0; z < nt; z++){
                        cin >> b[j][z]; 
                    }
                }

                for(int j = 0; j < nw; j++){
                    cin >> c[j];
                }

                vector<int> C(nw);
                for(int j = 0; j < nw; j++){
                    C[j] = j;
                }

                vector<int> S = avance_rapido(C, b, c, nw, nt);

                int beneficio = 0;
                if(solucion(S, c, b, nt)){
                    beneficio = objetivo(S, b, nt);
                } else {
                    while(S.size() < (size_t)nt){
                        S.push_back(-1);
                    }
                }

                cout << beneficio << endl;
                for(int j = 0; j < nt; j++){
                    cout << S[j] << " "; 
                }
                cout << endl;
            }
        }

        if(opcion == 2){
            cout << "=================================================" << endl;
            cout << "              MENU DE AYUDA" << endl;
            cout << "=================================================" << endl;
            cout << "El formato de entrada del programa es el siguiente:" << endl;
            cout << "1) La primera línea es el número total de casos de prueba." << endl;
            cout << "2) Luego dos números separados por espacio: número de trabajadores (N) y número de tareas (M)." << endl;
            cout << "3) Después, N lineas con M enteros que representan el beneficio que aporta cada trabajador a cada tarea." << endl;
            cout << "4) Finalmente, una linea con N enteros que representan la capacidad de cada trabajador." << endl;
            cout << "=================================================" << endl;
        }

        if(opcion == 3){
            cout << "Saliendo..." << endl;
        }

        cout << endl;

    } while (opcion != 3);

    return 0;
}
