#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n_especies;

void dfs(vector<list<int>>&v, int u, vector<bool>& visitados){
    visitados[u] = true;
    
    for (list<int>::iterator especie = v[u].begin(); especie != v[u].end(); especie++){
        if (!visitados[*especie]){
            n_especies ++;
            dfs(v, *especie, visitados);
        }
    }
}

int main()
{
    int N, M, A, B, especie;
    ios_base::sync_with_stdio(false);
    
    while (cin >> N>> M){
        vector<list<int>> analogimon(N);
        vector<bool> visitados(N, false);
        n_especies = 1;
        for (int i=0; i<M; i++){
            cin >> A>> B;
            analogimon[A-1].push_back(B-1);
        }
        cin >> especie;
        especie --;
        dfs(analogimon, especie, visitados);
        cout<< n_especies<< '\n';
    }
    
    return 0;
}