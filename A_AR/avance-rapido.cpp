#include "avance-rapido.hpp"

using namespace std;

int nt, nw;

void actualizar_cjto(vector<int> &C, vector<int> S, vector<int> c, int x){
    int cont = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == x){
            cont += 1;
        }
    }
    if(cont == c[x]){
       int i = 0;
       // Crear iterador y bucle para encontrar el elemento
    }
}

Solucion avance_rapido(vector<int> C, vector<int> b, vector<int> c, int nW, int nT){
    nt = nT;
    nw = nW;

    vector<int> S;
    int trabajo_act = 0;

    while(!C.empty() && !solucion(S) && trabajo_act < nt){
        int x = seleccionar(C, trabajo_act);
        if(factible(S, x)){
            insertar(S, x);
            actualizar_cjto(C, S, x);
            trabajo_act++;
        }
    }
    if(!solucion(S)){
        struct Solucion s = { .status = 0};
        return s;
    } else {
        struct Solucion s = { .status = 1, .cjtosolucion= S};
        return s;
    }

}
