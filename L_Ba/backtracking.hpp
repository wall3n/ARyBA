#ifndef __BACKTRACKING__
#define __BACKTRACKING__

#include <iostream>
#include <string>
#include <vector>

const int NUM_TALLAS = 6;

struct PosiblesTallas {
    int t1;
    int t2;
};

int asignaTalla(const std::string& talla);

bool backtracking(int M, std::vector<PosiblesTallas>& tallas, std::vector<int>& disponibles);

#endif
