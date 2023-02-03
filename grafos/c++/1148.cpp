#include <iostream>
#include <vector>
#define INF 5000000
#define endl '\n'
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

void floydWarshall(vector<vector<int>>& grafo){
  int n = grafo.size();
  
  fori(k, n){
    fori(i, n){
      fori(j, n){
        grafo[i][j] = min(grafo[i][j], grafo[i][k]+grafo[k][j]);
      }
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false);
  int n, e, x, y, h, k;
  
  while (cin >>n>> e && n != 0){
    vector<vector<int>> countriesAdjMat(n, vector<int>(n, INF));
    
    fori(i, e){
      cin>> x>> y>> h;
      x--; y--;
      countriesAdjMat[x][y]=h;
    }
    
    // processa as entradas para quem é dupla-mão tornar 0,
    fori(i, n){
      fori(j, n){
        if (countriesAdjMat[i][j] != INF && countriesAdjMat[j][i] != INF){
          countriesAdjMat[i][j]=0;
          countriesAdjMat[j][i]=0;
        }
      }
    }
    floydWarshall(countriesAdjMat);
    cin >> k;
    
    fori(i, k){
      cin >> x>> y;
      x--;y--;
      if (countriesAdjMat[x][y] != INF) cout<< countriesAdjMat[x][y]<< endl;
      else cout<< "Nao e possivel entregar a carta"<< endl;
    }
    cout<<endl;
  }
    
    
    return 0;
}