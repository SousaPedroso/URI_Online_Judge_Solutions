#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#define endl '\n'
#define fore(i, k, N) for(int i=0; i<N; i+=k)
using namespace std;


class Aresta{
    public:
        int u, v, c;

        bool operator<(const Aresta& a1){
            return c< a1.c;
        }
};

void initSet(vector<int>& pset){
    fore(i, 1, pset.size()) pset[i] = i;
}

int findSet(vector<int>& pset, int i){
    if (pset[i] == i) return i;
    pset[i] = findSet(pset, pset[i]);
    return pset[i];
}

void unionSet(vector<int>& pset, int u, int v){
    pset[findSet(pset, u)] = findSet(pset, v);
}

int main(){

    int M, N, X, Y, Z, current_cost, cost, junctions;

    cin >> M>> N;
    while (M != 0){
        vector<Aresta> roads(N);
        vector<int> pset(M);
        cost = 0;
        junctions = 0;
        current_cost=0;

        fore(i, 1, N){
            cin>> X>> Y>> Z;
            roads[i].u = X;
            roads[i].v = Y;
            roads[i].c = Z;
            current_cost += Z;
        }
        sort(roads.begin(), roads.end());
        initSet(pset);

        fore(i, 1, N){
            if (findSet(pset, roads[i].u) != findSet(pset, roads[i].v)){
                unionSet(pset, roads[i].u, roads[i].v);
                junctions ++;
                cost += roads[i].c;
                if (junctions == M){
                    break;
                }
            }
        }
        cout<< current_cost-cost<< endl;
        cin>> M>> N;
    }

    return 0;
}