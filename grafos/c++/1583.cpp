#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;

/* Ir para baixo, ir para cima, ir para a direita e ir para a esquerda
*/
int offset_x[] = {1, -1, 0, 0};
int offset_y[] = {0, 0, 1, -1};

void buscaContaminantes(vector<vector<char>>& g, vector<vector<bool>>& lc, int x, int y){
    lc[x][y] = true;

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            int x_atual = x+offset_x[i];
            int y_atual = y+offset_y[i];

            // cout<<"Visitado: ["<<x_atual<<","<<y_atual<<"] = "<<g[x_atual][y_atual]<<endl;
            if (x_atual >= 0 && x_atual < N && y_atual >= 0 && y_atual < M){
                if (g[x_atual][y_atual] == 'A' && !(lc[x_atual][y_atual])){
                    g[x_atual][y_atual] = 'T';
                    buscaContaminantes(g, lc, x_atual, y_atual);
                }
            }
        }
    }

}
 
int main() {
    
    cin>> N>> M;
    
    while (N!= 0 && M!= 0){
        vector<vector<char>> mapa(N, vector<char>(M, 'X'));
        vector<vector<bool>> lc(N, vector<bool>(M, false));

        // Escolhe alguns pontos para fazer a busca
        queue<pair<int, int>> pontapes;

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cin >> mapa[i][j];
                if (mapa[i][j] == 'T'){
                    pontapes.push(make_pair(i, j));
                }
            }
        }
        
        pair<int, int> contaminacao;
        while (pontapes.size() != 0){
            contaminacao = pontapes.front();
            pontapes.pop();
            buscaContaminantes(mapa, lc, contaminacao.first, contaminacao.second);
        }
        
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cout << mapa[i][j];
            }
            cout<< '\n';
        }
        
        cout<< '\n';
        cin >> N>> M;
    }
 
    return 0;
}