#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#define fori(i, n) for(int i=0; i<n; i++)
using namespace std;

typedef pair<pair<int, int>, int> piii;
int kingdom[101][101], xMoves[4] = {1, 0, -1, 0}, yMoves[4] = {0, 1, 0, -1};
int marked[101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, r, c, k, x, y, f;
    pair<int, int> f2;

    while (cin >> n>> r>> c>> k && n != 0){
        memset(kingdom, 0, sizeof kingdom);

        fori(i, r){
            fori(j, c){
                cin >> kingdom[i][j];
            }
        }

        fori(l, k){
            queue<int> q;
            queue<pair<int, int>> adjs;
            memset(marked, 0, sizeof marked);
            fori(i, r){
                fori(j, c){
                    fori(m, 4){
                        x = i+xMoves[m];
                        y = j+yMoves[m];
                        if (x >= 0 && x < r && y>= 0 && y < c){
                            if ((kingdom[i][j] < kingdom[x][y]
                            && (kingdom[i][j]%n)+1 == kingdom[x][y]%n)
                            || (kingdom[i][j] > kingdom[x][y]
                            && ((kingdom[i][j]+1)%n == kingdom[x][y] ))){
                              q.push(kingdom[i][j]);
                              adjs.push(pair<int,int>(x, y));
                            }
                        }
                    }
                }
            }
            while(!q.empty()){
                f = q.front(); q.pop();
                f2 = adjs.front(); adjs.pop();

                kingdom[f2.first][f2.second]= f;
            }
        }
        fori(i, r){
            fori(j, c){
                cout<< kingdom[i][j];
                if (j != c-1) cout<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}