#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define fori(i, n) for(int i=0; i<n; i++)
#define INF 1e4
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

void djikstra(vector<vector<pii>>&g, vi& dist, int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push(pii(0, s));
    dist[s]=0;

    while(!pq.empty()){
        pii front = pq.top(); pq.pop();
        int d= front.first, u = front.second;

        if (d == dist[u]){
            for(auto v: g[u]){
                if (v.second + dist[u] < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(pii(dist[v.first], v.first));
                }
            }
        }
    }
}

int main()
{
    int x, n, v, delay, start;
    
    while (cin >> x>> n >> v && x != 0){
        delay = 0;
        start = 0;
        if (x < 30){
            delay = 30-x;
        }
        else if (x < 50 && x > 30){
            delay = 50-x;
        }
        start = x;
        vector<vector<pii>> routes(v);
        map<string, int> localizations;
        localizations["varzea"] = 0; localizations["alto"] = 1;
        string o, d;
        int t, unique=2;
        
        fori(i, n){
            cin >> o >> d >> t;
            if (localizations.find(o) == localizations.end()){
                localizations[o] = unique;
                unique++;
            }
            if (localizations.find(d) == localizations.end()){
                localizations[d] = unique;
                unique++;
            }
            
            // onibus passando pela escola, precisa ter o delay para poder pegar para o destino
            if (localizations.find(o)->second == 0){
                t += delay;
            }
            routes[localizations.find(o)->second].push_back({localizations.find(d)->second, t});
        }
        vi dist(v, INF);
        djikstra(routes, dist, 0);
        
        int duration = dist[1];
        duration += start;
        printf("%d:%02d\n", 17+duration/60, duration%60);
        if (duration <= 60){
            cout<< "Nao ira se atrasar"<< endl;
        }
        else {
            cout<< "Ira se atrasar"<< endl;
        }
    }
    return 0;
}