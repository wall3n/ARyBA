#include <iostream>
#include <vector>
#include "avance-rapido.hpp"

using namespace std;

int main(void){
    int nCasos;
    cin >> nCasos;

    for(int i = 0; i < nCasos; i++){
        int nw, nt;
        cin >> nw >> nt ;

        vector<vector<int>> b(nw, vector<int>(nt));
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
        for(int i = 0; i < nw; i++){
            C[i] = i;
        }

        vector<int> S = avance_rapido(C, b, c, nw, nt);

        cout << objetivo(S, b) << endl;
        for(int i = 0; i < S.size(); i++){
            cout << S[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}
