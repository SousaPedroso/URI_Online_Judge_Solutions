#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'

using namespace std;

class Aresta{
    public:
        int u, v, km;
        
        Aresta(){
            
        }
        
        bool operator<(Aresta& a1){
            return km < a1.km;
        }
};

void initSet(vector<int>& pset){
    for (int i=0; i<pset.size(); i++){
        pset[i] = i;
    }
}

int findSet(vector<int>& pset, int i){
    if (pset[i] == i){
        return i;
    }
    pset[i] = findSet(pset, pset[i]);
    return pset[i];
}

void unionSet(vector<int>& pset, int i, int u){
    pset[findSet(pset, i)] = pset[findSet(pset, u)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M, count, kms;
    
    cin >> N>> M;
    while (N != 0){
        vector<Aresta> estradas(M);
        vector<int> pset(N);
        count = kms = 0;
        
        for (int i=0; i<M; i++){
            cin >> estradas[i].u>> estradas[i].v>> estradas[i].km;
        }
        sort(estradas.begin(), estradas.end());
        initSet(pset);
        for (int i=0; i<M; i++){
            if (findSet(pset, estradas[i].u) != findSet(pset, estradas[i].v)){
                count ++;
                kms += estradas[i].km;
                unionSet(pset, estradas[i].u, estradas[i].v);
                
                if (count == N){
                    break;
                }
            }
        }
        cout<< kms << endl;
        cin >> N>> M;
    }

    return 0;
}