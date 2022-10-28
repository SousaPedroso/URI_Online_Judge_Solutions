#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool pode_compilar = true;
int N, cor_atual;
void dfs(vector<list<int>>& g, int u, vector<bool>& v, vector<int>& compilacoes, vector<int>& cores){
    v[u] = true;
    
    for (list<int>::iterator i = g[u].begin(); i!= g[u].end(); i++){
        if (pode_compilar && !v[*i]){
            cores[*i] = cor_atual;
            dfs(g, *i, v, compilacoes, cores);
        }
        
        else {
            // Um arquivo depende do outro, não tem como compilar
            for (list<int>::iterator j = g[*i].begin(); j!= g[*i].end(); j++){
                if (*j == u || cores[*j] == cor_atual){
                    pode_compilar = false;
                    break;
                }
            }
        }
        
        // Depende do arquivo pra compilar
        compilacoes[u] = max(compilacoes[u], compilacoes[*i]+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, dependencia, tempo_compilacao;
    
    while (cin >> N){
        cor_atual = -1;
        pode_compilar = true;
        tempo_compilacao = 0;
        
        vector<list<int>> arquivos(N, list<int>());
        vector<bool> visitados(N, false);
        // Pinta cada arquivo de uma cor, para controlar
        // e evitar ciclos
        vector<int> cores(N, -1);
        
        // Constroi tempo de compilação, se depende de um arquivo,
        // Aumenta o total, em relação a aquele arquivo
        vector<int> compilacoes(N, 1);
        
        for (int i=0; i<N; i++){
            cin >> M;
            for (int j=0; j<M; j++){
                cin >> dependencia;
                arquivos[i].push_back(dependencia-1);
            }
        }

        for (int i=0; i<N; i++){
            if (!visitados[i] && pode_compilar){
                cor_atual ++;
                dfs(arquivos, i, visitados, compilacoes, cores);
            }
            if (!pode_compilar){
                tempo_compilacao = -1;
                break;
            }
            tempo_compilacao = max(tempo_compilacao, compilacoes[i]);
        }

        cout<< tempo_compilacao<< '\n';
    }

    return 0;
}