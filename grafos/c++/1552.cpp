#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define fore(i, N) for(int i=0; i<N; i+=1)
#define fori(i, s, N) for(int i=s; i<N; i+=1)

using namespace std;

class Aresta{
    public:
        int x, y;
        double p;

        Aresta (){}

        Aresta(int x, int y, double p){
            this->x=x;
            this->y=y;
            this->p=p;
        }

        bool operator<(const Aresta& a1){
            return p < a1.p;
        }
};

void initSet(vector<int>& pset){
    fore(i, pset.size()) pset[i] = i;
}

int findSet(vector<int>& pset, int i){
    if (pset[i] == i) return i;
    pset[i] = findSet(pset, pset[i]);
    return pset[i];
}

void unionSet(vector<int>& pset, int u, int v){
    pset[findSet(pset, u)] = findSet(pset, v);
}

double euclidianDistance(pair<int, int> p1, pair<int, int> p2){
    double d1, d2;
    d1 = pow(abs((double)p1.first-(double)p2.first), 2);
    d2 = pow(abs((double)p1.second-(double)p2.second), 2);

    return sqrtf(d1+d2);
}

int main(){

    int C, N;
    Aresta e;
    double web, dist;

    cin >> C;

    while (C--){
        cin>> N;

        vector<Aresta> people;
        vector<pair<int, int>> points(N);
        web = 0;

        fore(i, N){
            cin>> points[i].first >> points[i].second;
        }

        fore(i, N)
            fori(j, i+1, N){
                dist = euclidianDistance(points[i], points[j]);
                Aresta e(i, j, dist);
                people.push_back(e);
            }

        sort(people.begin(), people.end());
        vector<int> pset(N);
        initSet(pset);

        fore(i, people.size()){
            if (findSet(pset, people[i].x) != findSet(pset, people[i].y)){
                unionSet(pset, people[i].x, people[i].y);
                web += people[i].p;
            }
        }

        printf("%.2f\n", web/100);
    }

    return 0;
}