#include <iostream>
#include <queue>
#include <list>
#include <numeric>
#include <vector>
#define fore(i, N) for(int i=0; i<N; i++)
#define endl '\n'
using namespace std;

int N, M, total;

void visit_rooms(vector<list<int>>& graph, vector<bool>& visits, vector<int>& rooms){
    queue<int> rooms_to_visit;
    int room=0, queue_size=1, count_loop=0;
    
    visits[0] = true;
    rooms_to_visit.push(room);

    while (!rooms_to_visit.empty()){
        room = rooms_to_visit.front();
        rooms_to_visit.pop();
        
        // Visitou todo mundo e não liberou nenhuma sala
        if (count_loop == queue_size) break;
        
        // Sala room não liberada
        if (!visits[rooms[room]]){
            rooms_to_visit.push(room);
            count_loop++;
            continue;
        }
        
        visits[room] = true;
        count_loop = 0;

        for (list<int>::iterator v=graph[room].begin(); v!=graph[room].end(); v++){
            if (!visits[*v]){
                
                rooms_to_visit.push(*v);
                
            }
        }
        queue_size = rooms_to_visit.size();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int S, D;

    while (cin >> N>> M){
        vector<list<int>> rooms(N, list<int>());
        vector<bool> visits(N, false);
        vector<int> priority(N, 0);

        fore(i, M){
            cin >> S>> D;
            rooms[S-1].push_back(D-1);
            rooms[D-1].push_back(S-1);
        }
        fore(i, N-1){
            cin >> S;
            priority[i+1] = S-1;
        }

        total = 0;
        priority[0] = 0;
        // Faz a busca considerando os pontos passados
        visit_rooms(rooms, visits, priority);
        total = accumulate(visits.begin(), visits.end(), 0);
        if (total == N){
            cout<< "sim"<< endl;
        }
        else {
            cout<< "nao"<< endl;
        }
    }

    return 0;
}