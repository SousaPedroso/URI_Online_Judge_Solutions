#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define fori(i, n) for(int i=0; i<n; i++)
#define INF 1e9
#define endl '\n'
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;

void djikstra(vector<vector<ii>>& graph, vi& dist, int s){
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, s));
    
    while (!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        
        if (dist[u] == d){
            fori(i, graph[u].size()){
                ii v = graph[u][i];
                if (dist[u] + v.second < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
    }
}

int main()
{
    int c, v;
    int c1, c2, g;
    
    cin >> c >> v;
    vector<vector<ii>> routes(2*c);
    vi dist(2*c, INF);
    fori(i, v){
        cin>> c1>> c2 >> g;
        c1--; c2--;
        // rotas entre c1 e c2 não são atingidas diretamente, mas permite
        // que atinja rotas indiretas em número par ou impar
        routes[c1+c].push_back(ii(c2, g));
        routes[c2+c].push_back(ii(c1, g));
        routes[c1].push_back(ii(c2+c, g));
        routes[c2].push_back(ii(c1+c, g));
    }
    djikstra(routes, dist, 0);
    c--;
    if (dist[c] != INF) cout<< dist[c]<< endl;
    else cout<< -1<< endl;
    
    return 0;
}