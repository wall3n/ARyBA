#include "backtracking.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int asignaTalla(const string& talla) {
    if (talla == "XXL") return 0;
    if (talla == "XL")  return 1;
    if (talla == "L")   return 2;
    if (talla == "M")   return 3;
    if (talla == "S")   return 4;
    if (talla == "XS")  return 5;
    return -1; 
}

// Comprueba si ya hemos analizado a todos los voluntarios
bool Solucion(int nivel, int M) {
    return nivel == M;
}

// Comprueba que queden camisetas disponibles
bool Criterio(const vector<int>& disponibles) {
	
    for (int i = 0; i < 6; ++i) {
        if (disponibles[i] < 0) {
			return false;
		}
    }
    return true;
}

// Comprueba si aún le queda otra talla por probarse
bool MasHermanos(int nivel, const vector<int>& s) {
    return s[nivel] < 1; 
}

// Genera una nueva talla para el voluntario del nivel
void Generar(int nivel, const vector<PosiblesTallas>& tallas, vector<int>& s, vector<int>& disponibles) {
    
    // Si tenía una camiseta asignada, se restablece la disponibilidad
    if (s[nivel] != -1) {
		int tallaAnterior = -1;
		if(s[nivel] == 0){
			tallaAnterior = tallas[nivel].t1;
		} else if (s[nivel] == 1) {
			tallaAnterior = tallas[nivel].t2;
		}
        disponibles[tallaAnterior]++;
    }
	
	// Intentar con sig talla
    s[nivel]++;
    
    if (s[nivel] <= 1) {
		int tallaNueva = -1;
		if(s[nivel] == 0){
			tallaNueva = tallas[nivel].t1;
		}else if (s[nivel] == 1) {
			tallaNueva = tallas[nivel].t2;
		}
        disponibles[tallaNueva]--;
    }
}

// Retrocede un nivel y deshace lo asignado
void Retroceder(int& nivel, const vector<PosiblesTallas>& tallas, vector<int>& s, vector<int>& disponibles) {
    
    int tallaAct = -1;
    
    if (s[nivel] == 0){
		tallaAct = tallas[nivel].t1;
    } else if (s[nivel] == 1) {
		tallaAct = tallas[nivel].t2;
	}
	
	// Deshace asignación
    disponibles[tallaAct]++; 
    s[nivel] = -1;
    nivel--;
}

bool backtracking(int M, vector<PosiblesTallas>& tallas, vector<int>& disponibles) {
    
    vector<int> s(M + 1, -1); 
    int nivel = 1;
    bool fin = false;

    while (nivel > 0 && !fin) {
        Generar(nivel, tallas, s, disponibles);

        if (Solucion(nivel, M) && Criterio(disponibles)) {
            fin = true;
        } else if (Criterio(disponibles)) {
            nivel++;
            if (nivel <= M) s[nivel] = -1;
        } else {
            while (nivel > 0 && !MasHermanos(nivel, s)) {
                Retroceder(nivel, tallas, s, disponibles);
            }
        }
    }

    return fin;
}

