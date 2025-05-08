#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "backtracking.hpp"

using namespace std;

vector<string> tallas = {"XXL", "XL", "L", "M", "S", "XS"};

double caso_prueba(int N, int M){
    vector<PosiblesTallas> voluntarios(M + 1);
    vector<int> disponibles(6, N / 6);

    for (int i = 1; i <= M; ++i) {
        int t1 = rand() % 6;
        int t2 = rand() % 6;
        while (t2 == t1) t2 = rand() % 6;
        voluntarios[i].t1 = t1;
        voluntarios[i].t2 = t2;
    }

    struct timeval ti, tf;
    double tiempo;

    gettimeofday(&ti, NULL);
    bool resultado = backtracking(M, voluntarios, disponibles);
    gettimeofday(&tf, NULL);

    tiempo = (tf.tv_sec - ti.tv_sec) * 1000.0 + (tf.tv_usec - ti.tv_usec) / 1000.0;
    return tiempo;
}

int main(int argc, char **argv){
    if(argc != 3){
        cerr << "El uso de este programa es: ./generador <nº_de_casos> <fichero_salida.csv>" << endl;
        return 1;
    }

    int n_casos = stoi(argv[1]);
    if(n_casos < 1){
        cerr << "El número de casos de prueba debe ser al menos 1." << endl;
        return 1;
    }

    string archivo = argv[2];
    size_t check_csv = archivo.find(".csv");
    if(check_csv == string::npos){
        cerr << "El segundo parámetro debe ser un archivo con extensión .csv" << endl;
        return 1;
    }

    ofstream outputFile;
    outputFile.open(archivo, ios::app);

    for(int i = 0; i < n_casos; i++){
        int N = (rand() % 6 + 1) * 6; // múltiplo de 6 entre 6 y 36
        int M = rand() % N + 1;

        double resultado = caso_prueba(N, M);
        string resultado_str = to_string(resultado);
        replace(resultado_str.begin(), resultado_str.end(), '.', ','); // para compatibilidad con Excel (opcional)
        string linea = to_string(N) + ";" + to_string(M) + ";" + resultado_str + "\n";
        outputFile << linea;
    }

    outputFile.close();

    return 0;
}
