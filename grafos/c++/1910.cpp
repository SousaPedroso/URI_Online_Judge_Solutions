#include <iostream>
#include <queue>
#include <vector>
#define fore(i, N) for(int i=0; i<N; i++)
#define endl '\n'
using namespace std;

int max_channel = 100000;

bool add_channel(int channel, int dest, vector<bool>& visits, queue<int>& c){
    if (channel <= max_channel && channel > 0 && !visits[channel]){
        c.push(channel);
        visits[channel] = true;
        return true;
    }
    return false;
}

int bfs(int source, int dest, vector<bool>& visits){
    if (source == dest){
        return 0;
    }

    queue<int> channels;
    queue<int> levels;
    int channel, next_channel;

    channels.push(source);
    levels.push(0);
    while (!channels.empty()){
        channel = channels.front();
        channels.pop();

        // cout<< channel<< endl;
        if (add_channel(channel * 2, dest, visits, channels)){
            levels.push(levels.front()+1);
            if (channels.back() == dest){
                return levels.back();
            }
        }
        if (add_channel(channel * 3, dest, visits, channels)){
            levels.push(levels.front()+1);
            if (channels.back() == dest){
                return levels.back();
            }
        }
        if (add_channel(channel+1, dest, visits, channels)){
            levels.push(levels.front()+1);
            if (channels.back() == dest){
                return levels.back();
            }
        }

        if (add_channel(channel-1, dest, visits, channels)){
            levels.push(levels.front()+1);
            if (channels.back() == dest){
                return levels.back();
            }
        }

        next_channel = channel % 2 == 0? channel / 2: channel;
        if (add_channel(next_channel, dest, visits, channels)){
            levels.push(levels.front()+1);
            if (channels.back() == dest){
                return levels.back();
            }
        }
        levels.pop();
    }
    
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int O, D, K, b;

    cin >> O>> D>> K;
    while (O != 0){
        vector<bool> visited(max_channel+1, false);

        fore(i, K){
            cin>> b;
            visited[b] = true;
        }

        cout<< bfs(O, D, visited)<< endl;
        
        cin >> O>> D>> K;
    }
    return 0;
}