#include <iostream>
#include <vector>
#include <algorithm>
#define fori(i, n) for(int i=0; i<n ; i++)
#define endl '\n'
using namespace std;

vector<int> num, low, scc, componentes;
int color, cont, parallelCont;

void dfs(vector<vector<int>>& graph, int u){
    num[u]=low[u]=cont++;
    componentes.push_back(u);

    for( auto v: graph[u]){
        if (num[v] == 0){
            dfs(graph, v);
            low[u] = min(low[u], low[v]);
        }
        // só se não pertencer a outra componente
        else if (scc[v] == -1){
            low[u] = min(low[u], num[v]);
        }
    }
    // é quem inicia o ciclo
    if (num[u] == low[u]){
        int v;
        while (true){
            v=componentes.back();
            componentes.pop_back();
            scc[v] = color;
            if (v == u) break;
        }
        color++;
    }
}

void parallelDfs(vector<vector<int>>& graph, vector<bool>& visited, int u){
    visited[u]=true;
    parallelCont++;

    for(auto v: graph[u]){
        if (!visited[v]){
            parallelDfs(graph, visited, v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, a, b, t;

    while (cin >> n>> m){
        cin >> a >> b>> t;
        vector<bool> visited(n);
        vector<vector<int>> streets(n);
        vector<vector<int>> parallelStreets(n);

        cont=1; color=0; parallelCont=0;
        num.assign(n, 0);
        low.assign(n, 0);
        scc.assign(n, -1);

        fori(i, m-1){
            cin >> a >> b >> t;
            a--; b--;
            streets[a].push_back(b);
            // verificará se o grafo é conexo
            parallelStreets[a].push_back(b);
            parallelStreets[b].push_back(a);

            if (t == 2){
                streets[b].push_back(a);
            }
        }

        fori(i, n){
            if (num[i] == 0) dfs(streets, i);
        }

        if (color == 1){
            cout<< "-"<< endl;
            continue;
        }

        parallelDfs(parallelStreets, visited, 0);
        if (parallelCont != n){
            cout<< "*"<< endl;
            continue;
        }

        vector<int> grau(color);

        fori(i, n){
            for(auto v: streets[i]){
                if (scc[i] != scc[v]){
                    grau[scc[i]]++;
                    grau[scc[v]]++;
                }
            }
        }

        int buildCycle=0;
        fori(i, color){
            if (grau[i] >= 2) buildCycle++;
        }

        if (buildCycle == color){
            cout<< "1"<< endl;
        }
        else {
            cout<< "2"<< endl;
        }
    }

    return 0;
}