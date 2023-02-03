#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define INF 500
#define fori(i, n) for(int i=0; i<n; i++)
#define endl '\n'
using namespace std;

typedef vector<short int> vi;
typedef pair<short int, short int> pii;

void djikstra(vector<vector<pii>>&g, vi& dist, set<short int>& visited, short int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push(pii(0, s));
    dist[s]=0;
    visited.insert(s);

    while(!pq.empty()){
        pii front = pq.top(); pq.pop();
        short int d = front.first, u = front.second;
        
        if (d == dist[u]){
            for(auto v: g[u]){
                if (v.second + dist[u] < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(pii(dist[v.first], v.first));
                    visited.insert(s);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    // evitar o quanto der MLE para criação de muitos vetores
    short int n, m, a, b;
    int p;
    
    cin >> n>> m >> p;
    vector<vector<pii>> neighborhood(n);
    vector<vector<short int>> region;
    fori(i, m){
        cin >> a >> b;
        a--; b--;
        // simbólico para indicar que existe um caminho
        neighborhood[a].push_back(pii(b, 1));
        neighborhood[b].push_back(pii(a, 1));
    }
    
    set<short int> visited;
    short int k, l;
    
    // vai salvando os caminhos e visitando
    for (int i=0; i<n && visited.size() < n; i++){
        // já visitou em algum momento
        if (visited.find(i) != visited.end()) continue;
        vi dist(n, INF);
        djikstra(neighborhood, dist, visited, i);
        region.push_back(dist);
    }
    
    bool found;
    fori(i, p){
        found = false;
        cin >> k >> l;
        k--; l--;
        fori(j, region.size()){
            if (region[j][k] != INF && region[j][l] != INF){
                found = true;
                break;
            }
        }
        if (found) cout<< "Lets que lets"<< endl;
        else cout<< "Deu ruim"<< endl;
    }

    return 0;
}