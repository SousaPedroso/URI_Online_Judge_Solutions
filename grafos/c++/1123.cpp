#include <iostream>
#include <vector>
#define endl '\n'
#define fore(i, n) for(int i=0; i<n; i++)
#define INF 1e4
using namespace std;

void floyd(vector<vector<int>>& dist){
    // Zera diagonais
    fore(i, dist.size())
        dist[i][i] = 0;

    // Perpassa por todos os vértices
    fore(k, dist.size())
        fore(i, dist.size())
            fore(j, dist[i].size())
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m, c, k;
    int u, v, p;

    cin >> n>> m>> c>> k;

    while (n != 0){
        vector<vector<int>> routes(n, vector<int>(n, INF));

        fore(i, m){
            cin >> u>> v >> p;
            // Já que não pode haver caminhos de C para N-C 
            // vamos eliminá-los

            // Verifica algum está no caminho
            if(u<c && v<c){
                if(u>v) swap(u, v);
                if(u+1==v) routes[u][v] = p;
            }
            else if(u<c || v < c){
                if(u<c) routes[v][u] = p;
                else routes[u][v] = p;
            }
            // Nenhum no caminho
            else {
                routes[u][v] = p;
                routes[v][u] = p;
            }
            
        }

        floyd(routes);
        
        cout<< routes[k][c-1]<< endl;

        cin >> n>> m>> c>> k;
    }

    return 0;
}