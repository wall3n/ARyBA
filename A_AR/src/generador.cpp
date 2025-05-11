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
#include "avance-rapido.hpp"

using namespace std;

/*
 * Ejecuta un caso de prueba para N camisetas y M voluntarios.
 * Cada voluntario tiene 2 tallas posibles (t1, t2), generadas aleatoriamente.
 * Se mide el tiempo de ejecución de la función backtracking y se devuelve en milisegundos.
 */
double caso_prueba(int N, int M) {

    int nw = N;
    int nt = M;

    vector<vector<int> > b(nw, vector<int>(nt));
    vector<int> c(nw);

    // Generamos aleatoriamente la matriz de beneficios de 0 hasta 10 ya que el limite superior no es relevante para el problema
    for(int i = 0; i < nw; i++){
        for(int j = 0; j < nt; j++){
            b[i][j] = rand() % 10;
        }
    }

    // Generamos el vector de la capacidad de trabajo en relacion al numero de tareas ya que tendría sentido un trabajor con una carga superior al numero de tareas
    for(int i = 0; i < nw; i++){
        c[i] = rand() % nt;
    }

    // Generamos el vector con los trabajadores
    vector<int> C(nw);
    for(int i = 0; i < nw; i++){
        C[i] = i;
    }

    struct timeval ti, tf;
    gettimeofday(&ti, NULL);
    vector<int> resultado = avance_rapido(C, b, c, nw, nt);
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

    for (int N = 0; N <= 100; N++) {
        for (int M = 0; M <= 100; M++) {
            double t = caso_prueba(N, M);
            ostringstream oss;
            oss << fixed << setprecision(6) << t;
            string tiempoStr = oss.str();
            replace(tiempoStr.begin(), tiempoStr.end(), '.', ',');

            outputFile << N << ";" << M << ";" << tiempoStr << "\n";
        }
    }

    outputFile.close();
    return 0;
}
