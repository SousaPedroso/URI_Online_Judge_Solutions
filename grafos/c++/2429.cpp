#include <iostream>
#include <vector>
#include <algorithm>
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

vector<int> num, low, scc, componentes;
int cont, color;

void dfs(vector<vector<int>>& grafo, int u){
    num[u]=low[u]=cont++;
    componentes.push_back(u);

    for(auto v: grafo[u]){
        if (num[v] == 0){
            dfs(grafo, v);
            low[u] = min(low[v], low[u]);
        }
        // Não pertence a alguma componente ainda
        else if (scc[v] == -1){
            low[u] = min(low[u], num[v]);
        }
    }
    // vértice coordena o ciclo
    if (num[u] == low[u]){
        int v;
        while (true){
            v = componentes.back();
            componentes.pop_back();
            scc[v] = color;
            if (v == u) break;
        }
        color++;
    }
}

int main(){

    int n, a, b;

    cin >> n;

    vector<vector<int>> rodovias(n);
    num.assign(n, 0);
    low.assign(n, 0);
    scc.assign(n, -1);
    color = 0;
    cont = 1;

    fori(i, n){
        cin >> a >> b;
        a--; b--;
        rodovias[a].push_back(b);
    }

    fori(i, n){
        if (num[i] == 0) dfs(rodovias, i);
    }
    cout<<(color == 1? "S\n": "N\n");

    return 0;
}