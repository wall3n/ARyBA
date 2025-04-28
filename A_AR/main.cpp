#include <iostream>
#include <vector>

using namespace std;

bool factible(const vector<int> &S, int x, const vector<int> &c){
    int c_act = c[x];
    for(int i = 0; i < S.size(); i++){
        if(S[i] == x){
            c_act -= 1;
        }
    }
    return c_act > 0;
}

void insertar(vector<int> &S, int x, const vector<vector<int> > &b, int t){
    if(b[x][t] > 0){
        S.push_back(x);
    } else {
        S.push_back(-1);
    }
}

int objetivo(const vector<int> &S, const vector<vector<int> > &b){
    int bt = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == -1){
            bt = 0;
            return bt;
        }
        bt += b[S[i]][i];
    }
    return bt;
}

int seleccionar(const vector<int> &C, int j, const vector<vector<int> > &b){
    int candidato = C[0];
    int max_b = b[C[0]][j];
    for(int i = 0; i < C.size(); i++){
        if(max_b < b[C[i]][j]){
            max_b = b[C[i]][j];
            candidato = C[i];
        }
    }
    return candidato;

}

bool solucion(const vector<int> &S, const vector<int> &c, const vector<vector<int> > &b, int nt){
    if(S.size() != nt){ 
        return false; 
    }
    vector<int> c_copia = c;
    for(int i = 0; i < nt; i++){
        if(S[i] == -1){
            return false;
        } else if(c_copia[S[i]] > 0 && b[S[i]][i] > 0){
            c_copia[S[i]] -= 1;
        } else {
            return false;
        }
    }

    return true;
}

void actualizar_cjto(vector<int> &C, const vector<int> &S, const vector<int> &c, int x){
    int cont = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == x){
            cont += 1;
        }
    }
    if(cont >= c[x]){
       vector<int>::iterator it = C.begin();
       while(it != C.end() && *it != x){
            ++it;        
       }
       if(it != C.end()){
            C.erase(it);
       }
    }
}

vector<int> avance_rapido(vector<int> C, const vector<vector<int> > &b, const vector<int> &c, int nw, int nt){
    vector<int> S;
    int trabajo_act = 0;

    while(!C.empty() && !solucion(S, c, b, nt) && trabajo_act < nt){
        int x = seleccionar(C, trabajo_act, b);
        if(factible(S, x, c)){
            insertar(S, x, b, trabajo_act);
            actualizar_cjto(C, S, c, x);
            trabajo_act++;
        } 
    }
    return S;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nCasos;
    cin >> nCasos;

    for(int i = 0; i < nCasos; i++){
        int nw, nt;
        cin >> nw >> nt ;

        vector<vector<int> > b(nw, vector<int>(nt));
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
        for(int j = 0; j < nw; j++){
            C[j] = j;
        }

        vector<int> S = avance_rapido(C, b, c, nw, nt);

        cout << objetivo(S, b) << endl;
        for(int j = 0; j < S.size(); j++){
            cout << S[j] << " "; 
        }
        cout << endl;
    }
    return 0;
}
