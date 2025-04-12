#ifndef __AVANCE_RAPIDO__
#define __AVANCE_RAPIDO__

#include <vector>

struct Solucion {
    int status;
    vector<int> cjtosolucion;
};

Solucion avance_rapido(vector<int> C, vector<int> b, vector<int> c, int nW, int nT);

int objetivo(vector<int> S, vector<int> b);
#endif
