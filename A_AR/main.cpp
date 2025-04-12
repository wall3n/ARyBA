#include <iostream>

using namespace std;

int main(void){
    int nCasos;
    cin >> nCasos;

    for(int i = 0; i < nCasos; i++){
        int nw, nt;
        cin >> nw;
        cin >> nt;
        int b[nw][nt];
        int c[nw];

        for(int j = 0; j < nw; j++){
            for(int z = 0; z < nt; z++){
                cin >> b[j][z]; 
            }
        }

        for(int j = 0; j < nw; j++){
            cin >> c[j];
        }

        
    }
    return 0;
}
