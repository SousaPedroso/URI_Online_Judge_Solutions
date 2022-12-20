#include <iostream>
#include <list>
#include <vector>
#define fore(i, K, N) for(int i=0; i<N; i+=K)
#define endl '\n'

using namespace std;

void dfs(vector<list<int>>&g, vector<int>& ows, vector<bool>& who_called, int begin){
    // Se alguém chamar, poderá ser invocado
    who_called[begin] = true;
    
    for (auto neighbor=g[begin].begin(); neighbor != g[begin].end(); neighbor++){
        if (!who_called[*neighbor]){
            // Passa o valor para o representante
            ows[begin] += ows[*neighbor];
            ows[*neighbor] = 0;
            dfs(g, ows, who_called, *neighbor);
            // Atualiza com o que recebeu depois de buscar de outros vizinhos
            ows[begin] += ows[*neighbor];
            ows[*neighbor] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int N, M, X, Y, tot=0;

    cin >> N >> M;
    vector<int>ows(N);
    vector<list<int>>friendship(N);
    vector<bool> visited(N, false);
    fore(i, 1, N){
        cin>>ows[i];
    }
    fore(i, 1, M){
        cin>> X>> Y;
        friendship[X].push_back(Y);
        friendship[Y].push_back(X);
    }

    fore(i, 1, N){
        if (!visited[i]){
            dfs(friendship, ows, visited, i);
        }
    }
    
    for (auto o: ows){
        if (o == 0){
            tot ++;
        }
    }
    
    tot == N? cout<< "POSSIBLE"<< endl: cout<< "IMPOSSIBLE"<< endl;
    return 0;
}