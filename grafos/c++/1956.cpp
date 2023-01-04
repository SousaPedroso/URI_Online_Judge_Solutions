#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
#define fore(i, n) for(int i=0; i<n; i++)
using namespace std;

class Aresta{
    public:
        int i, j;
        long long c;

        bool operator<(const Aresta& a1){
            return c <a1.c;
        }
};

void initSet(vector<int>& pset){
    fore(i, pset.size()) pset[i] = i;
}

int findSet(vector<int>& pset, int i){
    if (pset[i] == i) return i;
    return pset[i] = findSet(pset, pset[i]);
}

void unionSet(vector<int>& pset, int i, int j){
    pset[findSet(pset, i)] = findSet(pset, j);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k, j, c;
    long long r=0;
    vector<Aresta> houses;
    set<int> families;

    cin >> n;
    fore(i, n-1){
        cin >> k;
        fore(u, k){
            cin >> j >> c;
            houses.push_back({i, j-1, c});
        }
    }
    sort(houses.begin(), houses.end());
    vector<int> pset(n);
    initSet(pset);

    fore(i, houses.size()){
        if (findSet(pset, houses[i].i) != findSet(pset, houses[i].j)){
            r += houses[i].c;
            unionSet(pset, houses[i].i, houses[i].j);
        }
    }

    fore(i, n){
        // Considera casas usadas na floresta
        families.insert(findSet(pset, pset[i]));
    }

    cout<< families.size() << " "<< r<< endl;

    return 0;
}