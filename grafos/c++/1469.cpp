#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
using namespace std;
#define endl '\n';

void reset_visits(vector<bool>& visitados){
    for (int i=0; i<visitados.size(); i++){
        visitados[i] = false;
    }
}

void update_managers(map<int, set<int>>& managers, vector<int>& idades, int u, int v){
    set<int>::iterator it1;
    set<int>::iterator it2;
    for (int i=0; i<managers.size(); i++){
        idades[i] = 101;
        if (i == u || i == v){
            continue;
        }
        // Se tiver u e v, não faz nada, caso contrário, troca os 2
        it1 = managers[i].find(u);
        it2 = managers[i].find(v);
        if (it1 != managers[i].end() && it2 == managers[i].end()){
            managers[i].erase(it1);
            managers[i].insert(v);
        }
        else if (it1 == managers[i].end() && it2 != managers[i].end()){
            managers[i].erase(it2);
            managers[i].insert(u);
        }
    }
}

void dfsP(map<int, set<int>>& grafo, int u, vector<int>& manager, vector<int>& idades, vector<bool>& visitados){
    visitados[u] = true;
    for (set<int>::iterator adj = grafo[u].begin(); adj != grafo[u].end(); adj++){
        if (!visitados[*adj]){
            manager[u] = min(manager[u], idades[*adj]);
            dfsP(grafo, *adj, manager, idades, visitados);
            manager[u] = min(manager[u], manager[*adj]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N, M, I, X, Y, menor;
    bool trocou;
    char instruction;
    set<int>::iterator adj;
    set<int> troca;

    int c=0;
    while( cin >> N >> M>> I){
        // Guarda por quem i-th employer é gerenciado
        map<int, set<int>> employers;
        
        vector<int> idades(N, 0);
        vector<bool> visitados(N, false);
        
        // Guarda o maior pra sempre comparar quando houver troca
        vector<int> newest_manager(N, 101);
        
        for (int i=0; i<N; i++){
            cin >> idades[i];
        }
        
        for (int i=0; i<M; i++){
            cin>> X>> Y;
            employers[Y-1].insert(X-1);
        }

        for (int i=0; i<I; i++){
            trocou = false;
            cin>> instruction;
            
            cin >> X;
            if (instruction == 'T'){
                cin>> Y;
                // Organiza quem gerencia quem
                troca = employers[X-1];
                employers[X-1] = employers[Y-1];
                employers[Y-1] = troca;

                // Se um for gerenciado por outro diretamente, tira-los da lista
                adj = employers[X-1].find(X-1);
                if (adj != employers[X-1].end()){
                    employers[X-1].erase(adj);
                    employers[X-1].insert(Y-1);
                    trocou = true;
                }
                
                if (!trocou){
                    adj = employers[Y-1].find(Y-1);
                    if (adj != employers[Y-1].end()){
                        employers[Y-1].erase(adj);
                        employers[Y-1].insert(X-1);
                    }
                }
                
                // Procura outros que dependem deles
                update_managers(employers, newest_manager, X-1, Y-1);
                
            }
            else{
                dfsP(employers, X-1, newest_manager, idades, visitados);
                if (newest_manager[X-1] != 101){
                    cout<< newest_manager[X-1]<< endl;
                }
                else {
                    cout<< "*"<< endl;
                }
                c++;
            }
            reset_visits(visitados);
        }
    }

    return 0;
}