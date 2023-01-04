#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#define fore(i, n) for(int i=0; i<n; i++)
#define endl '\n'
using namespace std;

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

    int n, x, y, rep, r;

    while (cin >> n && n != 0){
        r = 0;
        vector<int> pset(1001);
        initSet(pset);

        fore(i, n){
            scanf(" (%d,%d)", &x, &y);
            unionSet(pset, x, y);
        }
        rep = findSet(pset, 1);

        fore(i, 1001){
            if (findSet(pset, i) ==  rep) r++;
        }

        cout<< r<< endl;
    }

    return 0;
}