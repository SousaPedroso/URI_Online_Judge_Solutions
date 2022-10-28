#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fore(i, N) for(int i=0; i<N; i++)
#define endl '\n'
using namespace std;

int N, M, A=0;

int x_offset[] = {1, -1, 0, 0};
int y_offset[] = {0, 0, 1, -1};

void floodfill(vector<vector<char>>& m, vector<vector<bool>>& v, int x, int y){
    v[x][y] = true;
    int x_atual, y_atual;
    stack<pair<int, int>> s;
    pair<int, int> p;
    
    s.push(make_pair(x, y));
    while (!s.empty()){
        p = s.top();
        s.pop();

        // cout<< p.first<< " "<< p.second<< endl;
        for (int i=0; i<4; i++){
            x_atual = p.first + x_offset[i];
            y_atual = p.second + y_offset[i];
            
            if (x_atual >= 0 && x_atual < N && y_atual >= 0 && y_atual < M){
                if (!v[x_atual][y_atual] && m[x_atual][y_atual] == '.'){
                    s.push(make_pair(x_atual, y_atual));
                    v[x_atual][y_atual] = true;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int area =0;
    
    cin >> N >> M;
    
    vector<vector<char>> scenario(N, vector<char>(M, 'o'));
    vector<vector<bool>> visitados(N, vector<bool>(M, false));
    
    fore(i, N){
        fore(j, M){
            cin>> scenario[i][j];
        }
    }
    fore(i, N){
        fore(j, M){
            if (scenario[i][j] == '.' && !(visitados[i][j])){
                floodfill(scenario, visitados, i, j);
                area++;
            }   
        }
    }
    cout<< area<< endl;
    return 0;
}