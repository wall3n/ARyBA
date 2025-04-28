#ifndef __AVANCE_RAPIDO__
#define __AVANCE_RAPIDO__

#include <vector>

std::vector<int> avance_rapido(std::vector<int> C, const std::vector<std::vector<int>> &b, const std::vector<int> &c, int nw, int nt);

int objetivo(const std::vector<int> &S, const std::vector<std::vector<int>> &b);
#endif
