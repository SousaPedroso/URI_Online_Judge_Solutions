#include <iostream>
#include <vector>

using namespace std;
int familias=0;

void dfs(vector<vector<int>>& g, int u, vector<bool>& v){
    v[u]=true;
    
    for (int i=0; i<(int)g[u].size(); i++){
        if (!v[g[u][i]]){
            dfs(g, g[u][i], v);
        }
    }
}

int main()
{
    int N, M, p1, p2;
    
    cin>> N>> M;
    vector<vector<int>>g(N);
    vector<bool> visitados(N, false);
    
    while(M--){
        cin>> p1>> p2;
        g[p1-1].push_back(p2-1);
        g[p2-1].push_back(p1-1);
    }
    
    for (int i=0; i < N; i++){
		if (!visitados[i]){
			dfs(g, i, visitados);
			familias++;
		}
    }
    cout<< familias<< '\n';

    return 0;
}