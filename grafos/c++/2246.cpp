#include <iostream>
#include <vector>
#define fore(i, N) for(int i=0; i<N; i++)
using namespace std;

int x_offset[] = {1, -1, 0, 0};
int y_offset[] = {0, 0, 1, -1};
int H, L, smallest_area=40001, current_area=1;
void flood_fill(vector<vector<int>>& grafo, vector<vector<bool>>& visitados, int u, int v, int cor){
    visitados[u][v] = true;

    int x_atual, y_atual;
    fore(i, 4){
        x_atual = u+x_offset[i];
        y_atual = v+y_offset[i];

        if (x_atual >= 0 && x_atual < H && y_atual >= 0 && y_atual < L
            && !visitados[x_atual][y_atual] && grafo[x_atual][y_atual] == cor){

                flood_fill(grafo, visitados, x_atual, y_atual, cor);
                current_area ++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int cor;
    cin >> H>> L;
    vector<vector<int>>tiles(H, vector<int>(L, 0));
    vector<vector<bool>>visits(H, vector<bool>(L, false));

    fore(i, H){
        fore(j, L){
            cin >> tiles[i][j];
        }
    }

    fore(i, H){
        fore(j, L){
            if (!visits[i][j]){
                cor = tiles[i][j];
                current_area = 1;
                flood_fill(tiles, visits, i, j, cor);
                if (current_area < smallest_area){
                    smallest_area = current_area;
                }
            }
        }
    }

    cout<< smallest_area<< endl;

    return 0;
}