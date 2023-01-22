#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define fore(i, n) for(int i=0; i<n; i++)
using namespace std;

vector<int> num, parent;
bool loop;

void dfs(vector<vector<int>>& grafo, int u, int p){
    num[u] = 1;
    int v;
    
    fore (i, grafo[u].size()){
        v = grafo[u][i];
        
        // Vértice não visitado
        if (num[v] == 0){
            parent[v] = u;
            dfs(grafo, v, u);
        }
        
        // vértice já explorado, back edge
        else if (num[v] == 1) {
            // back edge, tem loop
            loop = true;
        }
    }
    num[u] = 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, m, a, b;
    
    cin >> t;
    
    while (t--){
        cin >> n>> m;
        vector<vector<int>> grafo(n);
        loop = false;
        
        num.assign(n, 0);
        parent.assign(n, 0);
        
        // le as dependencias
        fore(i, m){
            cin >> a >> b;
            a--; b--;
            
            grafo[a].push_back(b);
        }
        
        fore(i, n){
            if (loop) break;
            if (num[i] == 0){
                dfs(grafo, i, i);
            }
        }
        loop? cout<< "SIM"<< endl : cout<< "NAO"<< endl;
    }

    return 0;
}