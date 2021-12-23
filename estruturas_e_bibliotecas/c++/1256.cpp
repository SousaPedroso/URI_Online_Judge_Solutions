#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, M, C, chave, chave_tabela;
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> M >> C;
        vector<vector<int>> tabela_dispersao(M, {{}});

        for (int j=0; j<C; j++){
            cin >> chave;
            // Chave de insercao na tabela
            chave_tabela = chave % M;
            tabela_dispersao[chave_tabela].push_back(chave);
        }

        for (int j=0; j<M; j++){
            cout << j << " -> ";
            // Ignore the 0 element
            for (int k=1; k<tabela_dispersao[j].size(); k++){
                cout << tabela_dispersao[j][k] << " -> ";
            }
            cout << "\\" <<endl;
        }
        if (i != N-1){        
            cout <<endl;
        }
    }

    return 0;
}