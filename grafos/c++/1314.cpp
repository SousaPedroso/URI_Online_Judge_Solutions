#include <iostream>
#include <vector>
#define fori(i, n) for(int i=0; i<n; i++)

using namespace std;

vector<int> num, low;
vector<vector<int>> bridges;
vector<int> colors;
bool found;
int cont, color;

void dfs(vector<vector<int>>& graph, int u, int p){
    num[u]=low[u]=cont++;

    for (auto v: graph[u]){
        // pai de u, ignorar
        if (v == p) continue;

        if (num[v] == 0){
            dfs(graph, v, u);

            if (num[u] < low[v]){
                bridges[u].push_back(v);
                bridges[v].push_back(u);
            }

            low[u] = min(low[u], low[v]);
        }

        // atualiza com o menor alcançável
        else low[u] = min(num[v], low[u]);
    }
}

void goodChallenge(vector<vector<int>>& graph, int u, int v){
    colors[u]=color;

    if (u == v){
        found=true;
        return ;
    }

    for(auto w: graph[u]){
        if (colors[w] != color){
            goodChallenge(graph, w, v);
        }
    }
}

int main(){

    int n, m, q, a, b;

    while (cin >> n>> m>> q && n != 0){
        vector<vector<int>> mazes(n);

        low.assign(n, 0);
        num.assign(n, 0);
        bridges.assign(n, {});
        colors.assign(n, -1);
        cont=1;
        color=0;

        fori(i, m){
            cin>> a>> b;
            a--;b--;
            mazes[a].push_back(b);
            mazes[b].push_back(a);
        }

        fori(i, n){
            if (num[i] == 0){
                dfs(mazes, i, -1);
            }
        }
        
        fori(i, q){
            found=false;
            cin>> a>> b;
            a--; b--;
            goodChallenge(bridges, a, b);
            cout<<(found? "Y\n": "N\n");
            color++;
        }
        cout<< "-"<< endl;
    }

    return 0;
}