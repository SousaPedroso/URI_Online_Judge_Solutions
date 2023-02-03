#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#define fori(i, n) for(int i=0; i<n; i++)
#define endl '\n'
using namespace std;

typedef vector<double> vf;
typedef pair<int, double> pif;
typedef pair<double, int> pfi;

void djikstra(vector<vector<pif>>&g, vf& dist, int s){
    priority_queue<pfi, vector<pfi>, greater<pfi>> pq; pq.push(pfi(1, s));
    dist[s]=1;

    while(!pq.empty()){
        pfi front = pq.top(); pq.pop();
        double d = front.first, u = front.second;
        
        if (d >= dist[u]){
            for(auto v: g[u]){
                if (v.second * dist[u] > dist[v.first]){
                    dist[v.first] = dist[u] * v.second;
                    pq.push(pfi(dist[v.first], v.first));
                }
            }
        }
    }
}

int main()
{
    int n, m, a, b;
    double p;
    
    while (cin >> n >> m && n != 0){
        vector<vector<pif>> paths(n);
        
        fori(i, m){
            cin >> a >> b >> p;
            a--; b--; p/=100;
            paths[a].push_back(pif(b, p));
            paths[b].push_back(pif(a, p));
        }
        vf dist(n, 0);
        
        djikstra(paths, dist, 0);
        cout<< fixed;
        cout<< setprecision(6)<< dist[n-1]*100.0<< " percent"<< endl;
    }

    return 0;
}