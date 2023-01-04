#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#define fore(i, k, N) for(int i=0; i<N; i+=k)
#define endl '\n'

using namespace std;

int R, C;

class Aresta{

    public:
        int u, v, p;

        bool operator<(const Aresta& a1){
            return p<a1.p;
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

    int V, W, P, price=0, num_routers=0;

    cin >> R>> C;
    vector<int> pset(R);
    vector<Aresta> routers(C);

    fore(i, 1, C){
        cin >> V>> W>> P;
        routers[i].u = V-1;
        routers[i].v = W-1;
        routers[i].p = P;
    }

    sort(routers.begin(), routers.end());

    initSet(pset);
    fore(i, 1, C){
        if (findSet(pset, routers[i].u) != findSet(pset, routers[i].v)){
            unionSet(pset, routers[i].u, routers[i].v);
            num_routers ++;
            price += routers[i].p;

            if (num_routers == R){
                break;
            }
        }
    }
    cout<< price<< endl;

    return 0;
}