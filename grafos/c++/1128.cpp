#include <bits/stdc++.h>
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

vector<int> num, low, scc, componentes;
vector<vector<int>> ans;
int cont, color;

void dfs(vector<vector<int>> &grafo, int u) {
    num[u] = low[u] = cont++;
    componentes.push_back(u);

    for (auto v : grafo[u]) {
        if (num[v] == 0) {
            dfs(grafo, v);
            low[u] = min(low[u], low[v]);
        }
          // Atualiza quando o vertice v
          // nao pertencia a outra componente
        else if (scc[v] == -1)
          low[u] = min(low[u], num[v]);
    }

    // Quando chega no comeco de um ciclo, cria a componente
    // correspondente desempilhando os elementos
    if (low[u] == num[u]) {
        ans.push_back(vector<int>());
        while (true) {
            int v = componentes.back();
            componentes.pop_back();
            ans[color].push_back(v);
            scc[v] = color;
            if (u == v) break;
        }
        color++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, u, v, t;

    while (cin >> n >> m && n && m) {
        vector<vector<int>> fields(n);
        
        fori(i, m){
            cin >> u>> v >> t;
            u--; v--;
            fields[u].push_back(v);
            if (t == 2) fields[v].push_back(u);
        }
        num.assign(n, 0);
        low.assign(n, 0);
        scc.assign(n, -1);
        cont = 1;
        color = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == 0) {
                dfs(fields, i);
            }
        }
        
        if (color == 1) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}