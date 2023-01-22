#include <iostream>
#include <vector>
#include <algorithm>
#define fori(i, n) for(int i=0; i<n;i++)
using namespace std;

int bridges, cont;
vector<int> num, low;
vector<bool> articulation;

int dfs(vector<vector<int>>& grafo, int u, int p){
    num[u] = low[u] = cont++;
    int rootChildren = 0, v;
    
    fori(i, grafo[u].size()){
        v = grafo[u][i];
        
        // v é pai de u, ignorar
        if (v==p) continue;
        
        // Verifica se o estado é não visitado
        if (num[v] == 0){
            dfs(grafo, v, u);
            
            rootChildren++;
            // Vértice de corte
            if (num[u] <= low[v]) articulation[u] = true;
            // Aresta de corte
            if (num[u] < low[v]) bridges++;
            low[u] = min(low[u], low[v]);
        }
        // Já visitou, é forward edge
        else {
            low[u] = min(low[u], num[v]);
        }
    }
    return rootChildren;
}

int main() {
 
    int c, p, x, y;
    
    while (cin >> c >> p){
        vector<vector<int>> cities(c);
        bridges=0;
        cont=0;
        
        fori(i, p){
            cin >> x >> y;
            x--; y--;
            cities[x].push_back(y);
            cities[y].push_back(x);
        }
        
        num.assign(c, 0);
        low.assign(c, 0);
        articulation.assign(c, false);
        
        fori(i, c){
            if (num[i] == 0){
                dfs(cities, i, i);
            }
        }
        
        cout<< bridges<< endl;
    }
 
    return 0;
}