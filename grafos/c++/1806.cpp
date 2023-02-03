#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define endl '\n'
#define fori(i, n) for(int i=0; i<n; i++)
#define INF 1e9
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

void djikstra(vector<vector<ii>>& grafo, vi& dist, int s){
  dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, s));
  
  while (!pq.empty()){
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    // Verifica se ja nao foi encontrado um caminho melhor antes
    if (dist[u] == d){
      fori(j, grafo[u].size()){
        ii v = grafo[u][j];
        if (dist[u] + v.second < dist[v.first]){
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  int n, c, s, nc, a, b, v, l, k, f, criminalsToDefeat=0;
  bool found;
  
  cin >> n>> c>> s>> nc;
  vector<vector<ii>> routes(n);
  vector<vector<ii>> criminalRoutes(n);
  vi distCriminals(n, INF);
  vi distBino(n, INF);
  vi criminalLocations(nc);
  
  fori(i, c){
    cin >> a>> b >> v;
    a--; b--;
    
    routes[a].push_back({b, v});
    routes[b].push_back({a, v});
    criminalRoutes[a].push_back({b, v});
    criminalRoutes[b].push_back({a, v});
  }
  
  // rotas secretas dos criminosos
  fori(i, s){
    cin >> a >> b>> v;
    a--; b--;
    criminalRoutes[a].push_back({b, v});
    criminalRoutes[b].push_back({a, v});
  }
  // onde cada criminoso se encontra
  fori(i, nc){
    cin >> l;
    l--;
    criminalLocations[i] = l;
  }
  
  cin >> k >> f;
  k--; f--;
  djikstra(routes, distBino, k);

  // djikstra do ponto final para ver se a distancia equivale a do Bino
  djikstra(criminalRoutes, distCriminals, f);
  fori(i, nc){
    if (distCriminals[criminalLocations[i]] <= distBino[f]) criminalsToDefeat++;
  }
  cout<< criminalsToDefeat<< endl;
  
  return 0;
}


