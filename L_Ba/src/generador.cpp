#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "backtracking.hpp"

using namespace std;

/*
 * Ejecuta un caso de prueba para N camisetas y M voluntarios.
 * Cada voluntario tiene 2 tallas posibles (t1, t2), generadas aleatoriamente.
 * Se mide el tiempo de ejecución de la función backtracking y se devuelve en milisegundos.
 */
double caso_prueba(int N, int M) {
    vector<PosiblesTallas> voluntarios(M + 1); 
    vector<int> disponibles(6, N / 6);         

    // Generamos aleatoriamente dos tallas diferentes para cada voluntario
    for (int i = 1; i <= M; ++i) {
        int t1 = rand() % 6;
        int t2 = rand() % 6;
        while (t2 == t1) {
            t2 = rand() % 6;
        }
        voluntarios[i].t1 = t1;
        voluntarios[i].t2 = t2;
    }

    struct timeval ti, tf;
    gettimeofday(&ti, NULL);
    bool resultado = backtracking(M, voluntarios, disponibles);
    gettimeofday(&tf, NULL);

    double tiempo = (tf.tv_sec - ti.tv_sec) * 1000.0 + (tf.tv_usec - ti.tv_usec) / 1000.0;
    return tiempo;
}

int main() {
    srand(time(NULL));
    ofstream outputFile("resultados.csv", ios::app);
    if (!outputFile.is_open()) {
        cerr << "Error: no se pudo abrir el archivo resultados.csv" << endl;
        return 1;
    }

    for (int N = 6; N <= 60; N += 6) {
        for (int M = 1; M <= N; ++M) {
            int R;
            if (M <=12) {
                R = 30;       // casos pequeños
            } else if (M <= 24) {
                R = 30;       // casos medianos
            } else {
                R = 30;       // casos grandes
            }
            double sumaTiempos = 0.0;
            for (int i = 0; i < R; ++i) {
                double t = caso_prueba(N, M);
                sumaTiempos += t;
            }
            
            double tiempoPromedio = sumaTiempos / R;

            
            ostringstream oss;
            oss << fixed << setprecision(6) << tiempoPromedio;
            string tiempoStr = oss.str();
            replace(tiempoStr.begin(), tiempoStr.end(), '.', ',');

            outputFile << N << ";" << M << ";" << tiempoStr << "\n";
        }
    }

    outputFile.close();
    return 0;
}
