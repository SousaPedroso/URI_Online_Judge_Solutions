#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define endl '\n'
#define fore(i, k, N) for(int i=0; i<N; i+=k)
using namespace std;


map<char, pair<int, int>> moves;
map<char, char> inverted_moves;
int N, M;
bool found;

void flood_fill(vector<vector<char>>& g, vector<vector<bool>>& visits, queue<pair<int, int>>& cells, int x, int y){
    visits[x][y] = true;

    pair<int, int> direction = moves[g[x][y]];

    // Verifica se é o destino
    if (g[x][y] == 'x'){
        found = true;
        return ;
    }

    int next_move_x = x+direction.first;
    int next_move_y = y+direction.second;

    // Está na grid
    if (next_move_x >= 0 && next_move_x < N && next_move_y >= 0 && next_move_y < M){
        // cout<< "x: "<< next_move_x<< " y: "<< next_move_y<< endl;
        if (!visits[next_move_x][next_move_y]){
            cells.push(make_pair(next_move_x, next_move_y));
            flood_fill(g, visits, cells, next_move_x, next_move_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    moves['^'] = make_pair(-1, 0);
    moves['v'] = make_pair(1, 0);
    moves['<'] = make_pair(0, -1);
    moves['>'] = make_pair(0, 1);
    moves['x'] = make_pair(2, 1);

    inverted_moves['^'] = 'v';
    inverted_moves['v'] = '^';
    inverted_moves['<'] = '>';
    inverted_moves['>'] = '<';
    inverted_moves['x'] = 'x';

    int K;
    pair<int, int> cell;

    cin >> N>> M>> K;
    while (N != 0){
        vector<vector<char>> game_map(N, vector<char>(M, 'a'));
        vector<vector<bool>> visits(N, vector<bool>(M, false));
        queue<pair<int, int>> cells;
        found = false;

        fore(i, 1, N){
            fore(j, 1, M){
                cin>> game_map[i][j];
            }
        }

        // Primeira coluna e última de todas as linhas
        fore(i, 1, N){
            cells.push(make_pair(i, 0));
            cells.push(make_pair(i, M-1));
        }

        // As outras colunas da primeira e última linha
        fore(i, 1, M){
            cells.push(make_pair(0, i));
            cells.push(make_pair(N-1, i));
        }


        while (K >= 0){
            int queue_size = cells.size();
            while (queue_size--){
                cell = cells.front();
                cells.pop();

                flood_fill(game_map, visits, cells, cell.first, cell.second);
                if (found){
                    K = 0;
                    break;
                }
            }
            queue_size = cells.size();
            // Inverte quem passou antes
            while(queue_size--){
                cell = cells.front();
                cells.pop();

                game_map[cell.first][cell.second] = inverted_moves[game_map[cell.first][cell.second]];
                cells.push(make_pair(cell.first, cell.second));
            }
            K--;
        }
        found? cout<< "Sim"<< endl : cout<< "Nao"<< endl;
        cin >> N>> M>> K;
    }

    return 0;
}