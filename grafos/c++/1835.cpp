#include <iostream>
#include <vector>
#include <queue>
#define endl '\n';
using namespace std;

int N, M, estradas_encontradas=0;

void bfs(vector<vector<int>>& g, int x, vector<bool>& v){
    queue<int> q;
    int estrada;

    q.push(x);

    while (q.size() != 0){
        estrada = q.front();
        v[estrada] = true;
        q.pop();
        estradas_encontradas ++;

        for (auto adj: g[estrada]){
            if (!v[adj]){
                q.push(adj);
            }
        }
    }
}

int main(){

    int T, X, Y, estradas_precisas, parada, ultimo_encontro;

    cin >> T;
    for (int i=1; i<=T; i++){
        estradas_encontradas = 0;
        cin >> N>> M;
        vector<vector<int>> g(N);
        vector<bool> v(N, false);

        while (M--){
            cin >> X>> Y;
            g[X-1].push_back(Y-1);
            g[Y-1].push_back(X-1);
        }
        bfs(g, 0, v);
        estradas_precisas = 0;
        ultimo_encontro = estradas_encontradas;
        parada = 0;
        
        cout<< estradas_encontradas<< endl;
        if (estradas_encontradas < N){
            while (estradas_encontradas+estradas_precisas < N){
                    if (!v[parada]){
                        bfs(g, parada, v);
                        // Não achou caminho para esse bairro, o melhor é ligar com um existente
                        estradas_precisas ++;
                        ultimo_encontro = estradas_encontradas;
                    }
                    parada ++;
            }
            cout<< "Case #"<< i<< ": ainda falta(m) "<< estradas_precisas<< " estrada(s)"<< endl;
        }
        else {
            cout<< "Case #"<< i<< ": a promessa foi cumprida"<< endl;
        }
    }

    return 0;
}