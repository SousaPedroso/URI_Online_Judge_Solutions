#include <bits/stdc++.h>
#define fori(i, n) for(int i=0; i<n; i++)
#define endl '\n'
#define INF 1e14
using namespace std;

typedef vector<int> vi;
typedef pair<pair<int, long long int >, long long int> ill;
typedef pair<int, long long> il;
typedef pair<long long, int> li;

void djikstra(vector<vector<ill>>&g, vector<long long>& dist, vector<long long>& cost, int s){
    priority_queue<li, vector<li>, greater<li>> q;
    q.push(li(0, s));
    dist[s]=0; cost[s]=0;

    while(!q.empty()){
        li front = q.top(); q.pop();
        long long d= front.first, u = front.second;

        if (d == dist[u]){
            for(auto v: g[u]){
                if (v.first.second + dist[u] < dist[v.first.first]){
                    dist[v.first.first] = dist[u] + v.first.second;
                    q.push(li(dist[v.first.first], v.first.first));
                    cost[v.first.first] = v.second;
                }
                else if (v.first.second + dist[u] == dist[v.first.first]){
                    if (v.second < cost[v.first.first]){
                        dist[v.first.first] = dist[u] + v.first.second;
                        q.push(li(dist[v.first.first], v.first.first));
                        cost[v.first.first] = v.second;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    int n, m, a, b;
    long long l, c, r=0;

    cin >> n>> m;
    vector<vector<ill>> grafo(n);
    vector<bool> visited(n, false);
    fori(i, m){
        cin >> a >> b >> l >> c;
        a--; b--;
        grafo[a].push_back(ill(il(b, l), c));
        grafo[b].push_back(ill(il(a, l), c));
    }
    vector<long long> dist(n, INF);
    vector<long long> cost(n, INF);
    djikstra(grafo, dist, cost, 0);
    
    fori(i, n) r += cost[i];
    cout<< r<< endl;
    
    return 0;
}